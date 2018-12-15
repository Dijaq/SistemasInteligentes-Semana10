#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
	string line;
	ifstream f("train.txt");
	ofstream write("_train.txt");
	if (f.is_open())
	{
		while ( getline (f,line) )
		{
			//cout << line << '\n';
			int j=0;
			for(int i=0; i<line.length(); i++)
			{
				if((line.substr(i,1) == " ") || (i == (line.length()-1)))
				{
					//write << cout << i << endl;
					write << line.substr(j,i);
					j = i;
				//cout << line.substr(i,1) << '\n';
				}
			}
			write << endl;
		}
		f.close();
	}
	else
	{
		cout << "Unable to open file"; 
	}	  

	return 0;
}