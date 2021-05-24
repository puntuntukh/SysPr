#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fstream>
#include <pthread.h>

using namespace std;

pthread_mutex_t mtx;

typedef struct{
string Text;
string SubStrFind;
}Args;

void* SearchThread(void* args)
{	
	Args *arg = (Args*) args; 
		
	if (arg->Text.find(arg->SubStrFind) != -1)
	{
	   	cout << "found '" << arg->SubStrFind << "' in '" << arg->Text << "'\n"; 
	}
	pthread_mutex_unlock(&mtx);
	return NULL;
}



int main(int argc, char *argv[])
{
	string TextFile = argv[1];
	int NumbSplit = atoi(argv[2]);
 	int ProcNumb = 0;
 	int status = 0;
 	
 	pthread_t Thread[NumbSplit];
 	
 	pthread_mutex_init(&mtx, NULL);
 	
 	string line; 
 	string text;
	string SubStrFind;
 	Args args;
 	
	ifstream FileStreamInput;
	FileStreamInput.open(TextFile);
	if(FileStreamInput.is_open())
	{
		while (getline(FileStreamInput, line)) 
        		text += line;
	}	
	else return 0;
	
	FileStreamInput.close();
	cout << "What do you whant to find: " << endl;
	cin >> args.SubStrFind;
	
	int Size = text.length() / NumbSplit;
	
	for (int i = 0; i < NumbSplit; i++)		
	{	
		pthread_mutex_lock(&mtx);
		//sleep(2);
		int displace = i * Size;
		args.Text = text.substr(displace, Size);
		int status = pthread_create(&Thread[i], NULL, SearchThread, &args);		
	}
	
	for( int i = 0; i < NumbSplit; i++ ) 
		pthread_join(Thread[i], NULL);
	
	pthread_mutex_destroy(&mtx);
	
	return 0;
}
