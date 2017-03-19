#include <iostream>
#include <fstream>
using namespace std;

class HeapSort{
	public:
	int fatherIndex;
	int leftKidIndex;
	int rightKidIndex;
	int minKidIndex;
	int *heapAry;
	int size;
	ofstream debugOut;
	
	public:
	// The name of the constructor is the name of the class
	HeapSort(int size, char *debugFileName){
		this->size = size+1;
		
		debugOut.open(debugFileName);
		
		if(!debugOut)
		{
			throw "Failed to open the debug file.";			
		}
		
		heapAry = new int[this->size];
		
		for(int i =0; i < this->size; i++){
			heapAry [i] = 0;
		}
		
		// heapAry[0] = last Index
		// heapAry[1] = the root of the tree
		heapAry[0] = 0; 
		
	};
	
	~HeapSort() {
		debugOut.close();
		delete [] heapAry;	
	};
	
	void insertOneDataItem(int data)
	{
		int kidIndex = getLastIndex();
		
		kidIndex++;
		
		if(kidIndex < this->size)
		{
			heapAry[kidIndex] = data; // put the data at the end of the heapAry
			heapAry[0] = kidIndex; // store last index in heapaAry[0]	
		}
		else
		{
			cout << "The heap is full!! Heap Max Size: " + this->size << endl;
		}
	};
	
	int buildHeap(char *filename)
	{
		cout << "Creating the heap from the file: " << filename << endl;
		ifstream infile;
		infile.open(filename);
		int data;
	
		if(!infile)
		{
		  	cout << "Unable to open" << filename << "\n";
		  	return -1;
		}
		else
		{	
		  	while( infile >> data )
			{
				insertOneDataItem(data);
				bubbleUp(getLastIndex()) ;
				printHeap();
			}
		}
		  
		infile.close();
		return 0;
	};
	
	void deleteRoot()
	{
		
		if(isHeapEmpty())
			throw "Unable to delete Root. Heap is empty.";
		
		int lastIndex = getLastIndex();		

		if(isRoot(lastIndex))	
		{
			// there's only one element,  which is the root, in the heap tree.
			heapAry[0]--;  // reset lase index to delete the root.
		}
		else
		{
			heapAry[1] = heapAry[lastIndex];
			heapAry[lastIndex] = 0;
			heapAry[0]--;					
		}		
	};
	
	void deleteHeap(char* outputFileName)
	{
		ofstream of;
		of.open(outputFileName);
		cout << "executing deleteHeap:" << endl;
		
		if(!of)
		{
			cout << "deleteHeap - Unable to open output file: " << outputFileName << endl;
		}
		else
		{		
			while(!isHeapEmpty())
			{
				int data = getRoot();
				of << data << ", ";
					
				deleteRoot();
				fatherIndex = 1;
				bubbleDown(fatherIndex);
				printHeap();				
			}	
		}
		of.close();
	};

	void printHeap()
	{
		debugOut << "Print the heap: " ;
		
		// only want to print out 10 items or less
		int min = (this->size > 10) ? 10: this->size;
		
		for(int i = 0; i < min; i++)
		{
			debugOut << heapAry[i] << ", ";
		}
		debugOut << endl;		
	};
	
	int getLastIndex()
	{
		return heapAry[0];
	};
	
	bool isHeapFull()
	{
		int kidIndex = getLastIndex();				
		return (kidIndex == this->size);
	};
	
	bool isHeapEmpty()
	{
		int kidIndex = getLastIndex();
		return kidIndex == 0;
	};
	
	bool isRoot(int kidIndex)
	{
		return kidIndex == 1;
	};
	
	bool isLeaf(int kidIndex)
	{
		int leftIndex = kidIndex * 2;
		int rightIndex =kidIndex * 2 + 1;
		
		int lastIndex = getLastIndex();
		if( leftIndex > lastIndex && rightIndex > lastIndex )
			return true;
		return false;
	};
	
	int getRoot()
	{
		if(this->isHeapEmpty())
			throw "No Root Element is available. The Heap Tree is empty.";
		
		return heapAry[1];				
	};
	
	void bubbleUp(int kidIndex)
	{
		if(isRoot(kidIndex))
			return;
		else
		{
			fatherIndex = kidIndex / 2;
		
			if(heapAry[kidIndex] < heapAry[fatherIndex]) // swap if the kid is smaller.
			{
				// swap
				int temp = heapAry[kidIndex];
				heapAry[kidIndex] = heapAry[fatherIndex];
				heapAry[fatherIndex] = temp;
			}

			bubbleUp(fatherIndex);
		}
	};	
	
	void bubbleDown(int fatherIndex)
	{
		if( isLeaf(fatherIndex)) 
		{
			return;
		}
		else 
		{
			leftKidIndex = fatherIndex * 2;
			rightKidIndex =fatherIndex * 2 + 1;
			
			minKidIndex = findMinKidIndex(leftKidIndex, rightKidIndex);
			
			
			// if only left leaf is avaialble
			if(rightKidIndex > getLastIndex())
			{
				minKidIndex = leftKidIndex;
			}
			
			if(heapAry[minKidIndex] < heapAry[fatherIndex]) 
			{
				// swap
				int temp = heapAry[minKidIndex];
				heapAry[minKidIndex] = heapAry[fatherIndex];
				heapAry[fatherIndex] = temp;
			}
			bubbleDown(minKidIndex);
		}	
	};
	
	int findMinKidIndex(int leftIndex, int rightIndex)
	{
		
		int leftValue = heapAry[leftIndex];
		int rightValue = heapAry[rightIndex];
		
		if(leftValue <= rightValue)
		{
			return leftIndex; // return left index since its value is smaller.			
		}
		return rightIndex; // return right index if its value is smallere
	};
};

int getTotalLength(char *filename)
{
	ifstream infile;
	infile.open(filename);
	int length = 0;
	int n;

	if(!infile)
	{
	  	cout << "Unable to open" << filename << "\n";
	  	return -1;
	}
	else
	{	
	  	while( infile >> n )
		{
	  		length ++;
		}
	}	  
	infile.close();
	return length;	
}

int main(int argc, char **argv)
{
	if(argc!=4)
	{
		// Display User Help
		cout << "HeapSort Command User Guide:" << endl;
		cout << endl;
		cout << "Please specify input data file, debug output file as well as output file." << endl;
		cout << endl;
		cout << "Example:" << endl << endl;
		cout << "HeapSort inputData.txt debug.txt output.txt" << endl;
		return -1;
	}

	char* inputDataFileName = argv[1];
	char* debugFileName = argv[2];
	char* outputDataFileName = argv[3];
	
	// HeapSort Algorihtm step 1
	int size;	
	size = getTotalLength(inputDataFileName);
	HeapSort heapsort(size, debugFileName);
	
	// HeapSort Algorihtm step 2
	heapsort.buildHeap(inputDataFileName);	
	heapsort.deleteHeap(outputDataFileName);
} 

