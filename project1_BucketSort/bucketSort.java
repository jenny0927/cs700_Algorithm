import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class bucketSort 
{
	int min;
	int max;
	int lastIndex;
	int[] BucketAry;
	
	public bucketSort(String filename)
	{
		this.findMinMax(filename);
		lastIndex= max- min + 1;		
		int size = lastIndex;
		this.BucketAry = new int[size];
	}
	
	public static void main(String[] args) 
	{
		if( args.length!= 2)
		{ 
			System.out.println("Invalid number of arguments");
			System.exit(-1);
		}
		bucketSort bucket = new bucketSort(args[0]);
		bucket.findMinMax(args[0]);
		bucket.countFrequence(args[0]);
		bucket.printSortData(args[1]);
	}
	
	public void findMinMax(String filename) 
	{
		try
		{
			Scanner infile = new Scanner( new File(filename));
		
			while (infile.hasNext()) 
			{	
				int n = infile.nextInt();
				if(n < 0) 
				{
					throw new Exception("illegal negtive number");
				}
				else
				{
					max = (n>max) ? n:max;
					min = (n>min) ? min:n;
				}
			}
			infile.close();
		
		}
		catch(Exception e)
		{
			System.out.println( "Error on getting the largest number: " + e.getMessage());
			System.exit(-1);
		}
	}
	
	public int getIndex(int d)
	{
		return d-min;
	}
	
	public void countFrequence(String filename)
	{
		try 
		{
			Scanner infile = new Scanner(new File(filename));

			while (infile.hasNext()) 
			{
				int n = infile.nextInt();
				BucketAry[this.getIndex(n)]++;
				
			}
			infile.close();
		}
		catch (FileNotFoundException e) 
		{
			System.out.println("Read Error: " + e);
		}
	}
	
	public void printSortData(String filename)
	{
		try 
		{
			BufferedWriter outfile = new BufferedWriter(new FileWriter(filename));
	            
			for (int i = 0; i < lastIndex; i++) 
			{
				int frequency = BucketAry[i];
				int data = i + min;
				
				if(frequency!=0)
				{
					for(int j=frequency; j>0; j--)
					{
						outfile.write((data) + "\n");	
					}
				}
				
			}
			outfile.close();
		} 
		catch (IOException e) {
			System.out.println( "Write Error: " + e.getMessage());
		}
	}
}
