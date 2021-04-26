#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	string TextFile = argv[1];
	int NumbSplit = atoi(argv[2]);
 	int ProcNumb = 0;
 	int status = 0;
 	
 	string Text;
 	string line; 
 	string SubStrFind;
 	
	ifstream FileStreamInput;
	FileStreamInput.open(TextFile);
	if(FileStreamInput.is_open())
	{
		while (getline(FileStreamInput, line)) 
        		Text += line;
	}	
	else return 0;
	
	FileStreamInput.close();
	cout << "What do you whant to find: " << endl;
	cin >> SubStrFind;
	
	int Size = Text.length() / NumbSplit;
	
	cout << "parent id " << getpid() << endl;
	
	for (int i = 0; i < NumbSplit; i++)		
	{
		pid_t num;
		num = fork();
		
		if(num == 0)
		{
			
			int displace = i * Size;
			execl("2program", 
			TextFile.c_str(), 
			SubStrFind.c_str(), 
			to_string(displace).c_str(), 
			to_string(Size).c_str(), 			
			NULL);	
			//exit(1);
		}
		waitpid(num, &status,0);	
	}
	cout << "parnet end" << endl;
	exit(0);
	return 0;
}


