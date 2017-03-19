
import java.util.Scanner;

public class passwordChecker 
{
	String password;
	String secondPassword;
	int passwordLength;
	int charCounts[] = new int[5];
	
	public passwordChecker()
	{
		passwordLength =0;
		for(int i =0; i< charCounts.length; i++ )
		{
			charCounts[i]=0;
		}
	}
	
	public static void main (String []args)
	{
		passwordChecker checker = new passwordChecker();
	
		while(true)
		{
			try{
				checker.printRule();
				checker.getPassword();
				
				if(! (checker.checker(checker.charCounts)==false ||  
						checker.passwordLength > 16 || checker.passwordLength < 8) )
				{
					checker.getSecondPassword();
					if(checker.matching(checker.password, checker.secondPassword)==true)
					{
						checker.displySucess();
						break;
					}
				}		
			}
			catch(Exception e){
				System.out.println("error: " + e.getMessage());
			}
			
		}
	}
	
	public void getPassword()
	{
		Scanner reader = new Scanner(System.in);  // Reading from System.in
		System.out.println("Enter Password:");
		password = reader.next(); 
		passwordLength = password.length();
		System.out.println(password);
		System.out.println("passwordLength: " + passwordLength);
	}

	public void getSecondPassword()
	{
		Scanner reader = new Scanner(System.in);  // Reading from System.in
		System.out.println("\nPlease enter your password again:");
		secondPassword = reader.next(); 
	}

	public void printRule()
	{
		System.out.println("Password Rule: \n" +
				"1) The password length: 8-16 characters\n" + 
				"2) At least one numerical, i.e., 0, 1, 2,.." + "\n" +
				"3) At least one upper case letter, i.e., A, B, C, ...\n" +
				"4) At least one lower case letter, i.e., a, b, c, ...\n" + 
				"5) At least one of the special characters, but it must be within the \n" + 
				"  set:{ $ ^ & #  ( ) } at total of six (6). no other special characters is allowed.\n");
	}
	
	public int checkChar(char ch)
	{
		
		if(ch >= '0' && ch <= '9') return 1;
		else if (ch >= 'a' && ch <= 'z') return 2;
		else if (ch >= 'A' && ch <= 'Z') return 3;
		else if ((ch == '$') || (ch =='^') || (ch == '#') || (ch =='&') || (ch == '(' ) || (ch ==')')) return 4;
		else return 0;
		
	}
	
	public boolean checker (int charCount[])
	{
		for(int i =0; i< charCounts.length; i++ )
		{
			charCounts[i]=0;
		}		
		
		for(int i =0; i< passwordLength; i++)
		{
			int index = checkChar(password.charAt(i));
			charCounts[index]++;
		}
		
//		for(int i=0; i < charCounts.length; i++)
//		{
//			System.out.println("charCounts[" + i + "]" + charCounts[i]);
//		}
		
		if((charCount[0] == 0) && (charCount[1]>0) && charCount[2]>0 && charCount[3]>0 && charCount[4] >0)
		{
			return true;
		}
	
		else 
		{
			return false;
		}
	}
	
	public boolean matching(String s1, String s2)
	{
		if (s1.equals(s2)) return true;
		else return false;
	}
	
	public void displySucess()
	{
		System.out.println("your password will be updated in 2 minuties");
	}
	
}
