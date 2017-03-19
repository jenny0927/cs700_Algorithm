import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class main
{
	static int longestDataLength =0;
	
	public static void main(String []args)
	{
		radixSort sort = new radixSort();

		int d;
		int currentTable =0;
		int currentDigit =0;
		int previousTable; 
		int longestDataLength =0;
		
		int tableIndex; // which bucket of the given hash table

		if(args.length!=2)
		{
			System.out.println("Wrong number of arugments.");
			return;
		}
		
		String filename = args[0];
		String outputfilename = args[1];
		try{
			Scanner infile = new Scanner(new File (filename));
			BufferedWriter writer = new BufferedWriter(new FileWriter(outputfilename));
			linkedListStack stack = new linkedListStack();
			listNode newNode;
			
			while(infile.hasNext())	
			{
				d = infile.nextInt();
				//System.out.println(d);
				newNode = new listNode(d);
				stack.push(newNode);
				sort.longestDataLength (newNode); 
			}
			
			
			stack.printStack(writer);
			sort.bw = writer;
			
			sort.moveToHashTable(stack);
			sort.printTable();
			

			sort.Step9toStep15();
			
			writer.close();
			
		}
		catch(Exception e)
		{
			System.err.println(e.getMessage());
		}
		
	}
}