import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CountFrequency 
{
	public static void main(String[] args) 
	{
		int max =0;
		
		try 
		{
			Scanner infile = new Scanner(new File(args[0]));
	
			while (infile.hasNext()) 
			{
				int n = infile.nextInt();
				max = (n>max) ? n:max;
				
			}
			infile.close();
		}
		catch (FileNotFoundException e) {
			System.out.println("Error on getting the largest number: " + e);
		}
		
		int arr[] = new int[max+1];
		
		try 
		{
			Scanner infile = new Scanner(new File(args[0]));
		
			for (int i = 0; i < arr.length; i++) {
				arr[i] = 0;
			}
	
			while (infile.hasNext()) {
				
				int n = infile.nextInt();
				arr[n]++;
				
			}
			infile.close();
		}
		catch (FileNotFoundException e) {
			System.out.println("Read Error: " + e);
		}
		
		try 
		{
			BufferedWriter outfile = new BufferedWriter(new FileWriter(args[1]));
	            
			for (int i = 0; i < arr.length; i++) 
			{
				outfile.write(i + "---->" + arr[i] + "\n");	
				outfile.newLine();
			}
			outfile.close();
		} 
		catch (IOException e) {
			System.out.println("Write Error: " + e);
		}

	}
}
