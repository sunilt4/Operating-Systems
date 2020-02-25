/* GROUP 14
SUNIL TUMKUR 100620430
ERIC TSIM
MATTHEW BROWN
FAISAL PINDER
*/
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

int main(int argc, char *argv[], char **envp)
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
		perror("getcwd error!");
		return 1;
	}

	//Parse commands given using argc ad argv and perfirn an infinite loop getting command input from users

	while (fgets(buffer, BUFFER_LEN, stdin) != NULL) {

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

		//check if the input was cd
		if (strcmp(command, "cd\0") == 0) {

			int var;
			var = chdir(arr[1]);

			if (var) {

				int ern = errno;
				fprintf(stderr, "Error in chdir('%s') errno = %d: %s\n", arr[1], ern, strerror(ern));
			}
		}

			else if (strcmp(command, "dir\n") == 0) {

				DIR *d;
				struct dirent *dir;
				d = opendir(".");

				if (d) {

					while ((dir = readdir(d)) != NULL) {

						printf("%s\n", dir->d_name);
					}
					closedir(d);
				}

				//check if input was quit
			}

			else if (strcmp(command, "quit\n") == 0) {
				//other commands go here...
				//quit command will exit the shell

				return EXIT_SUCCESS;
				//check if input was clr (clear)
			}

			else if (strcmp(command, "clr\n") == 0) {
				for (int i=0; i<80; i++) {
					printf("\n");
				}
			}

			//check if input was pause
			else if (strcmp(command, "pause\n") == 0) {
				char chr = '\0';
				while(chr != '\n') {
					printf("Press the ENTER key on the keyboard to Continue\n");
					scanf("%c", &chr);
				}
			}

			//check if the input was echo
			else if (strcmp(command, "echo\0") == 0) {
				printf("%s %s", arr[1], arr[2]);
			}

			//check if the input was help 
			else if (strcmp(command, "help\n") == 0) {
				FILE *fp;
				char c;
            	fp=fopen("README.md","rt");

            	while((c=fgetc(fp))!=EOF){
                printf("%c",c);

               	}

               	fclose(fp);
			}

			//check if the input was environ
			else if (strcmp(command, "environ\n") == 0) {

				for (char **env = envp; *env != 0; env++) {
                	char *thisEnv = *env;
                	printf("%s\n", thisEnv);    
              	}
			}

			else {
				//Unsupported command
				fputs("Unsupported command, use help to display the manual\n", stderr);
			}

			// clearing the command memory
			memset(command, 0, sizeof(command));

			//printing the current working directory
			if(getcwd(cwd, sizeof(cwd)) != NULL) {
            	printf("%s ", cwd);
        	} 
        	else {
        		perror("getcwd error");
            	return 1;
        	}
		}

		return EXIT_SUCCESS;
	}