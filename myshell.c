//myshell C file

//include all the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"
#include <unistd.h>
#include <errno.h>
#include <dirent.h>

// Put macros or constants here using #define
#define BUFFER_LEN 256

int int main(int argc, char *argv[], char **envp)
{
	// Input buffer and and commands 
	char buffer[BUFFER_LEN] = {0};
	char command[BUFFER_LEN] = {0};

	char *token;
	const char s[2] = " ";
	const char *arr[3];
	(void)argc;
	(void)argv;

	//current working directory of size 512
	char cwd[512];

	//getcwd() function shall place an absolute pathname of the current working directory in the array pointed to by cwd, and return cwd
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		//print current working directory
		printf("%s ", cwd);
	}

	else {
		//print out an error if you cant find and display current working directory 
		perror("getcwd error!")
		return 1;
	}

	//Parse commands given using argc ad argv and perfirn an infinite loop getting command input from users

	while (fegts(buffer, BUFFER_LEN, stdin) != NULL {

		// Perform string tokenization to get the command and argument
		token = strtok(buffer, s);
		int counter = 0;

		while(token != NULL) {

			if (counter == 0) {

				memcpy(command, token, strlen(token));
			}

			arr[counter] = token;
			token = strtok(NULL, s);
			counter++;
		}
	}








	return 0;
}