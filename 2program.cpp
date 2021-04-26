#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{	
	string TextFile = argv[0];
	string SubStrFind = argv[1];
	int displace = atoi(argv[2]);
	int Size = atoi(argv[3]);
	string Text;
	string line;
	
	ifstream FileStreamInput;
	FileStreamInput.open(TextFile);
	if(FileStreamInput.is_open()){
		while (getline(FileStreamInput, line)) 
        		Text += line;
	}
	else return 0;
	FileStreamInput.close();
	
	Text = Text.substr(displace, Size); 	
	
	if (Text.find(SubStrFind) != -1)
	{
		cout << "child id " << getpid() << endl;
	   	cout << "found '" << SubStrFind << "' in '" << Text << "'\n"; 
	}
	 
	exit(0);
		
	
} 



