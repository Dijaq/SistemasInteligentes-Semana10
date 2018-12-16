#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
	string line;
	ifstream f("testb.txt");
	ofstream write("_testb.csv");
	if (f.is_open())
	{
		while ( getline (f,line) )
		{
			//cout << line << '\n';
			int j=0;
			string linea = "";
			for(int i=0; i<line.length(); i++)
			{
				if((line.substr(i,1) == " ") || (i == (line.length()-1)))
				{
					string imp="";
					for(int k=0; k<line.substr(j,i).length(); k++)
					{
						if((line.substr(j+k,1) == ",")  || (line.substr(j,i) == "\"") || (line.substr(j,i) == ";"))
						{
							imp += "-";
						}
						else
						{
							imp += line.substr(j+k,1);
						}
					}
					linea+=imp+",";
					//write << line.substr(j,i);
					j = i;
				//cout << line.substr(i,1) << '\n';
				}
			}
			//write << "\n";
			linea += "\n";
			write << linea;
			//write << endl;
		}
		f.close();
	}
	else
	{
		cout << "Unable to open file"; 
	}	  

	return 0;
}