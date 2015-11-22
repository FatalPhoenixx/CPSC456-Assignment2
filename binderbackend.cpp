#include <string>
#include "codearray.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <sys/wait.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
using namespace std;

int main()
{
	string temp = "";
	/* The child process id */
	pid_t childProcId = -1;
	
	/* Go through the binaries */
	for(int progCount = 0; 	progCount < NUM_BINARIES; ++progCount)
	{

		//TODO: Create a temporary file you can use the tmpnam() function for this.
		// E.g. fileName = tmpnam(NULL)
		char* fileName = tmpnam(NULL);
		
		//TODO: Open the file and write the bytes of the first program to the file.
		//These bytes are found in codeArray[progCount]	
		temp = string(fileName);
		
		FILE* myfile = fopen(temp.c_str(), "wb");
		if(!myfile)
		{
			perror("fopen");
			exit(-1);
		}

		if(fwrite(codeArray[progCount], sizeof(char), programLengths[progCount], myfile) < 0)
		{
			perror("fwrite");
			exit(-1);
		}
		fclose(myfile);

		//TODO: Make the file executable: this can be done using chmod(fileName,0777)		
		temp = "chmod 0777 "+ string(fileName);	
			
		system(temp.c_str());

		//TODO: Create a child process using fork
 		childProcId = fork();

		/* I am a child process; I will turn into an executable */
		if (childProcId < 0) { /* error occurred */
			fprintf(stderr, "Fork Failed");
			exit(-1);
		}
		else if(childProcId == 0)
		{
			//TODO: use execlp() in order to turn the child process into the process
			//running the program in the above file.
			if(execlp(fileName, fileName, NULL) < 0)
			{				
				perror("execlp");				
				exit(-1);
			}

		}
		else{
			if(wait (NULL) < 0)
			{				
				perror("execlp");				
				exit(-1);
			}
			cout <<"Child Complete" << endl;
		}
	}
	
	/* Wait for all programs to finish */
	for(int progCount = 0; progCount < NUM_BINARIES; ++progCount)
	{
		
		/* Wait for one of the programs to finish */
		if(wait(NULL) < 0)
		{			
			perror("wait");
			exit(-1);
		}
	}

return 0;
}
