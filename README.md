_This project has been created as part of the 42 curriculum by jfox_
# get_next_line
A more advanced function for reading documents one line at a time. For School 42.

## DESCRIPTION

get_next_line.c or GNL is a program that will read a text file pointed to a by a file descriptor. It will read the file 1 line at a time without reading the whole document first.  

The bonus of this project allows multiple files to printed using multiple file descriptors. The program will continue to print 1 line at a time. This will have varying results depending on the main you write to display your gnl results.  

GNL will not print that line by itself, use a custom main with a printf type function to print each line made by GNL.

## INSTRUCTIONS

Write a main and compile it with cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c  
You can add -D BUFFER_SIZE=* To set a custom BUFFER_SIZE when using the program. Default is 25.  

_For the Bonus add _bonus to each document being compiled._  

The main needs to include minimum 1 file descriptor which should be an int variable. This file descriptor should use the 'open' command with O_RDONLY to read a given .txt file.  

The file descriptor given can be 0 to give input from the command line.  

Stdio.h and printf can be used in a loop to print the results of repeated calls of get_next_line(fd), where the fd is file descriptor pointing to our .txt file.  

Inside the main do not forget to free the line being printed to avoid errors with Valgrind.  

(This repo contains an example main, to show the use of GNL in a practical way. Note the 'test' text files referenced in that main are not included in the repo.)  

## RESOURCES

Ai was not used in this project.  
Static variable [ref](https://en.wikipedia.org/wiki/Static_variable)  
GNL [video](https://www.youtube.com/watch?v=-Mt2FdJjVno)  
Helpful advice [here](https://medium.com/@beatrizbazaglia/get-next-line-3872eb3189e6)  

## ADDITIONAL

My choice of algorithm was not a conscious process, it was rather more iterative.  

I knew I needed to loop through the sting using my buffersize until I found a \n or a \0.  

This was the first element, building a string with calloc and strjoin that would include the first line up to \n and any additional text from the next line that happened to be caught in the loop due to buffersize.  

Once I had my first string, I could check the string was no longer than the first \n or \0 in the string. This was my second function where I check up to the end of the line and pass that result to be printed.  

I believed at the start I would need a 3rd function to save the 'remainder' of the string in my static variable for the next call of gnl.
However I found I was able to use a temporary variable in my check_line function, meaning that once a complete new line had been checked, any information after the \n was saved into the static variable for the next call.  

This kept my code short and clean.  

Once this was all in place it was simply a question of refining my code, putting protections in place and using the best/most efficient helper functions for the job.  
