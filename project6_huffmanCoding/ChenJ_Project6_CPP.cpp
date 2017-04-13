#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;
#define COL1 12

class listBinTreeNode
{
    friend class HuffmanLinkedList;
    friend class HuffmanBinaryTree;
    string chStr;
    int prob;
    listBinTreeNode* next;
    listBinTreeNode* left;
    listBinTreeNode* right;
    
	public:
	//constructor
    listBinTreeNode()
	{
        next = NULL;
        left = NULL;
        right = NULL;
    }
    
    listBinTreeNode(string str, int p)
	{
        chStr = str;
        prob = p;
        next = NULL;
        left = NULL;;
        right = NULL;
    }
    
    ~listBinTreeNode()
	{
        
        delete left;
        delete right;
    }
    
    void printNode(listBinTreeNode* T, ofstream& outFile)
	{
		
        if( T->next == NULL && T->left == NULL && T->right == NULL )
		{
            outFile  << std::left << setw(COL1) << T->chStr << setw(COL1) << T->prob << setw(COL1)<< "NULL" << setw(COL1) << "NULL"
            << setw(COL1) << "NULL" << endl;
        
        }
		else if( T->next == NULL )
		{
            outFile << std::left << setw(COL1) << T->chStr << setw(COL1) << T-> prob <<setw(COL1) << "NULL" << setw(COL1) << T-> left -> chStr
            << setw(COL1) << T -> right -> chStr << endl;
        }
        else if( T->left == NULL && T->right == NULL)
		{
            outFile << std::left << setw(COL1) << T-> chStr << setw(COL1)<< T->prob << setw(COL1) << T->next->chStr << setw(COL1)
            <<"NULL"<<setw(COL1)<<"NULL"<<endl;
        }
        else
		{
            outFile << std::left << setw(COL1) << T->chStr <<setw(COL1) << T->prob << setw(COL1) << T->next->chStr << setw(COL1)
            << T->left->chStr << setw(COL1) << T->right->chStr << endl;
        }
    }
};

class HuffmanLinkedList{
	public:
   	listBinTreeNode* listHead;
   	listBinTreeNode* spot = listHead;
   	
   	HuffmanLinkedList()	{
        listHead = new listBinTreeNode("dummy",0);
   	}  
	     
    listBinTreeNode* findSpot(int data)	{
      spot = listHead;
	 
        while (!isEmpty() && spot->next->prob < data)
       		spot = spot->next;	
        return spot;
    }
    
    void listInsert(listBinTreeNode* T)	{
        spot = findSpot(T->prob);
        T->next = spot->next;
        spot->next = T;  
    }
    
    bool isEmpty()	{
	 	return spot->next == NULL;	
	}
    
    void printList(ofstream& outFile3){
        outFile3 << "ListHead-->(\"" << listHead->chStr << "\"," << listHead->prob << ",";
       spot = listHead;
        while(!isEmpty()){
            spot = spot->next;
            outFile3 << "\"" << spot->chStr << "\")-->(\"" << spot->chStr << "\"," << spot->prob << ",";
        }
        outFile3 << "NULL)-->NULL" << endl;
    }
};

class HuffmanBinaryTree{ 
	public:
	string chStr;
    int prob;
    string code;
    listBinTreeNode* oldListHead;
    
    public:
    HuffmanBinaryTree()	{ 
		oldListHead = NULL;
	}
    
    void constructHuffmanBinaryTree(HuffmanLinkedList myHLL, ofstream& outFile3)	{
      	oldListHead = myHLL.listHead;
        myHLL.listHead = myHLL.listHead->next;
        
        while(myHLL.listHead->next != NULL)	{
            listBinTreeNode* newNode = new listBinTreeNode();
            newNode->prob = myHLL.listHead->prob + myHLL.listHead->next->prob;
            newNode->chStr = myHLL.listHead->chStr + myHLL.listHead->next->chStr;
            newNode->left = myHLL.listHead;
            newNode->right = myHLL.listHead->next;
            myHLL.listHead = myHLL.listHead->next->next;
            
            myHLL.listInsert(newNode);
            newNode->printNode(newNode,outFile3);
            if( myHLL.listHead == NULL || myHLL.listHead->prob >= newNode->prob)
                myHLL.listHead = newNode;
                
          	myHLL.printList(outFile3);
           	outFile3<<"\n"; 
        }
        oldListHead = myHLL.listHead;
    }

    void preOrderTraveral(listBinTreeNode* T, ofstream& outFile2)	{
        if(T == NULL) return;
        T->printNode(T,outFile2);
        preOrderTraveral( T->left, outFile2);
        preOrderTraveral( T->right, outFile2);
    }
    
    void constructCharCode(listBinTreeNode* T, string code, ofstream& outFile1)	{
        if(T== NULL) return;
        else if( T->left == NULL && T->right == NULL)
		{
            outFile1 << T->chStr << " " << code << endl;
        }     
        constructCharCode(T->left, code + "0", outFile1);
        constructCharCode(T->right, code + "1", outFile1);     
    }
}; 

int main(int argc, char ** argv) {
	if (argc != 5){
			cout << "wrong number of arguments.";
		return -1;
	}		
    ifstream inFile(argv[1]);
    ofstream outFile1(argv[2]);
    ofstream outFile2(argv[3]);
    ofstream outFile3(argv[4]);
    
    if( !inFile.is_open() || !outFile1.is_open() || !outFile2.is_open() || !outFile3.is_open() ){
        cout<< "Unable to open one of files" << endl;
    }
	else
	{
        HuffmanLinkedList myHLL = HuffmanLinkedList();
        string ch;
        int prob;
        
        while(inFile>>ch && inFile>>prob)
		{
            listBinTreeNode* newNode = new listBinTreeNode(ch, prob);
            myHLL.listInsert(newNode);
            
            myHLL.printList(outFile3);
        }
        inFile.close();
        outFile3<<"\n\n";
        
        HuffmanBinaryTree myHBT = HuffmanBinaryTree();
        myHBT.constructHuffmanBinaryTree( myHLL, outFile3);
        myHBT.constructCharCode( myHBT.oldListHead, "", outFile1);
        outFile2  << std::left << setw(COL1) << "String" << setw(COL1) << "Prob" << setw(COL1)<< "Next" << setw(COL1) << "Left"
            << setw(COL1) << "Tree right" << endl;
        outFile2  << endl;
        myHBT.preOrderTraveral( myHBT.oldListHead, outFile2);
    }
    outFile1.close();
    outFile2.close();
    outFile3.close();
}
