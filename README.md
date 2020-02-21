# Operating-Systems
Operating Systems Lab 2 (SOFE 3950U) 

## How to run the Shell Program:

1) In order to run the Shell program, use the make command to compile myshell.c file. Once compiling, execute the program using the command: ./myshell (Can also run enter all commands into a file, then include the name of the file as a command line argument to the myshell program: ./myshell batchfile)

## List of Commands:

1) cd ./<directory> - Change current defualt directory to <directory>. If the <directory> argument is not present then report the current directory. If the directory does not exist then an appropriate error should be reported.
2) clr - Clear the screen
3) dir <directory> - List the contents of the directory <directory>
4) environ - List all enviroment strings
5) echo <comment> - Display <comment> on the display followed by a new line (multiple spaces/tabs may be reduced to a single space)
6) help - Display the user manual using the more filter
7) pause - Pause operation of the shell until 'Enter' is pressed
8) quit - Quit the shell
9) The shell environment should contain shell=<pathname>/myshell where <pathname>/myshell is the full path for the shell executable (not a hardwired path back to your directory, but the one from which it was executed)
