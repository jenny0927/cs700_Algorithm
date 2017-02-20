#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char **argv) 
{
  ifstream infile;
  infile.open(argv[1]);
  int max = 0;
  
  if(!infile)
  {
  	cout << "Unable to open" << argv[1] << "for getting the max.\n";
  }
  
  else
  {
  	int n;
  	
  	while( infile >> n )
	{
  		max = (n > max) ? n : max;
	}
  }
  
  infile.close();
  
  int *arr = new int[max+1];
  
  for(int i =0; i< max+1; i++)
  {
  	arr[i]=0;
  }
  
  infile.open(argv[1]);
  
  if(!infile)
  {
  	cout << "Unable to open" << argv[1] << "for reading.\n";
  }
  else
  {
  	int n;
  	while(infile>>n)
	{
  		arr[n]++;
	}
  		
  }
  infile.close();
  
  ofstream outfile(argv[2]);
  
  if(!outfile)
  {
  	cout<< "Unable to open" << argv[2] << "for writing.\n";
  	return (1);
  }
  
  for(int i=0; i< max+1; i++)
  {
  	outfile << i << "--->" << arr[i] << endl;
  }
  
  outfile.close();
}
