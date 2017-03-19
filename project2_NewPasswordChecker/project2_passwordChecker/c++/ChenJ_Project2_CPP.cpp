#include <iostream>
#include <string>
using namespace std;


class passwordChecker 
{
	public:
	string password = "      ";
	string secondPassword;
	int passwordLength;
	int charCounts[5];
	
	public:
		
	passwordChecker()
	{
		passwordLength =0;
		for(int i =0; i< 5; i++ )
		{
			charCounts[i]=0;
		}
	};
	
	void getPassword()
	{
		cout << "Enter Password:";
		getline(cin, password, '\n');
		passwordLength = password.length();
		cout << password << "\n";
		cout << "\n";
		cout << "passwordLength: " + passwordLength;
	};
	
	void getSecondPassword()
	{
		 // Reading from System.in
		cout << ("\nPlease enter your password again:");
		getline(cin, secondPassword, '\n');
	};
	
	void printRule()
	{
		cout << ("Password Rule: \n" 
				"1) The password length: 8-16 characters\n"  
				"2) At least one numerical, i.e., 0, 1, 2,..\n"
				"3) At least one upper case letter, i.e., A, B, C, ...\n" 
				"4) At least one lower case letter, i.e., a, b, c, ...\n" 
				"5) At least one of the special characters, but it must be within the \n" 
				"  set:{ $ ^ & #  ( ) } at total of six (6). no other special characters is allowed.\n");
	};
	
	int checkChar(char ch)
	{
		
		if(ch >= '0' && ch <= '9') return 1;
		else if (ch >= 'a' && ch <= 'z') return 2;
		else if (ch >= 'A' && ch <= 'Z') return 3;
		else if ((ch == '$') || (ch =='^') || (ch == '#') || (ch =='&') || (ch == '(' ) || (ch ==')')) return 4;
		else return 0;
		
	}
	
	bool checker (int charCount[])
	{
		for(int i =0; i<5; i++ )
		{
			charCounts[i]=0;
		}		
		
		for(int i =0; i< passwordLength; i++)
		{
			int index = checkChar(password.at(i));
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
	
	bool matching(string s1, string s2)
	{
		cout << s1 << " "<< s2;
		
		if (s1.compare(s2)==0) return true;
		
		else return false;
	};
	
	void displySucess()
	{
		cout << ("your password will be updated in 2 minuties");
	};
	
};


	int main ()
	{
		passwordChecker checker;
		checker.printRule();
		checker.getPassword();
	
		while(true)
		{
			try{
				checker.printRule();
				checker.getPassword();
				
				if(! (checker.checker(checker.charCounts)==false ||  
						checker.passwordLength > 18 || checker.passwordLength < 8) )
				{
					checker.getSecondPassword();
					if(checker.matching(checker.password, checker.secondPassword)==true)
					{
						checker.displySucess();
						break;
					}
				}		
			}
			catch(...){
				cout << "error: " ;
			}
			
		}
	}
	
	
