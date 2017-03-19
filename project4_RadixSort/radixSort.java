import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class radixSort 
{
	int longestDataLength = 0;
	linkedListQueue hashTable[][];
	int previousTable;
	int currentDigit =0;
	int currentTable =0;
	int digit, hashIndex;
	
	public BufferedWriter bw;
	
	public radixSort()
	{
		hashTable = new linkedListQueue[2][10];
		
		for (int r = 0; r < 2; r++) 
		{
			for (int c = 0; c < 10; c++) 
			{
				hashTable[r][c] = new linkedListQueue();
			}
		}
	}
	
	public int getDigit (listNode node, int currentD)
	{
		int currentDigit = 0;
		int digit =node.data;
		for(int i =0; i< currentD+1; i++)
		{
			currentDigit =digit % 10;
			digit = digit/10;
		}
		return currentDigit;
	}
	

	public int hashIndex (int digit)
	{
		 return 0;
	}
	
	int currentDigit(listNode newNode)
	{
		return (newNode.data)%10;
	}
	
	int longestDataLength(listNode newNode) 
	{
		int length = 0;
		int data = newNode.data;
		while(data/10 > 0) 
		{
			data = data/ 10;
			length++;
			longestDataLength =(length > longestDataLength)? length : longestDataLength;
		}
		System.out.println("longestDataLength: " + longestDataLength);
		return longestDataLength;
	}
	
	public void printTable() throws IOException
	{
		for (int i = 0; i < 10; i++) {;		
			linkedListQueue queue = hashTable[currentTable][i];
			if (!queue.isEmpty()) 
			{
				bw.write("Table[" + currentTable+ "][" + i + "]: \n");
				queue.printQueue(bw);
				bw.write("\n");
			}
		}
	}
	
	public void moveToHashTable(linkedListStack stack)
	{
		int digit, hashIndex;
		while (!stack.isEmpty())
		{
			listNode node = stack.Pop();
			digit = this.getDigit(node, currentDigit);
			System.out.println("value:" + node.data + ",Digital:" + digit);
			hashIndex = digit;
			
			System.out.println("");			
			hashTable[currentTable][digit].addTail(node);
		}
	}
	
	public void movingNodesfromPreviousTabletoCurrentTable()
	{
		int currentQueue = 0;
		for (currentQueue = 0; currentQueue <= 10 - 1; currentQueue++) 
		{
			while (!hashTable[previousTable][currentQueue].isEmpty()) {
				
				
				listNode node = hashTable[previousTable][currentQueue].deleteHead();
				digit = getDigit(node, currentDigit);
				hashIndex = digit;
				hashTable[currentTable][hashIndex].addTail(node);
			}
		}

	}
	
	public void Step9toStep15() throws IOException
	{

		do {
			currentDigit++;
			currentTable = 1;
			previousTable = 0;
			
			movingNodesfromPreviousTabletoCurrentTable();
			
			
			// Step14
			int temp = currentTable;
			currentTable = previousTable;
			previousTable = temp;
						
			movingNodesfromPreviousTabletoCurrentTable();

		} while (currentDigit < longestDataLength);

		System.out.println("\nprint Table after step 9: ");
		printTable();

	}
}
