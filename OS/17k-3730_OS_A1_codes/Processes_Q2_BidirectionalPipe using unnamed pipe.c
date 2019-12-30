/*
	Eisha
	17k-3730
	sec C
	processes_Q2
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
int main()
{
    int parent_pipe[2];
    int child_pipe[2];
    char buff[50];
    if(pipe(parent_pipe) || pipe(child_pipe))
	{
		//print error
		
        perror("pipe error");
        exit(1);
    }
    pid_t pid=fork();
    if (pid == -1)
	{
		//printerror
		
        perror("fork()");
        exit(1);
    }
    
    if(pid == 0)
	{
        int in, out;
        char child[] = "Child Writes. Parent Reads\n";
        in = child_pipe[0];

        // in = parent_pipe[0];  

        out = parent_pipe[1];
		//out = parent_pipe[1];
		
        for (int i = 0; i < 10; ++i){
            read(in, buff, 50);
            printf("Parent: %s", buff);
            write(out, child, strlen(child) + 1);
        }
    }
//     else
//	{
//        char parent[]="Parent Writes. Child Reads\n";
//        int input,output;
//
//        input=parent_pipe[0];
//        output=child_pipe[1];
//        test pipe;
//        for (i = 0; i < 10; ++i){
//            write(out, parent, strlen(parent) + 1);
//            read(in, buff, 50);
//            printf("Child: %s", buff);
//        }
//    }
    else
	{
        char parent[]="Parent Writes. Child Reads\n";

        int in,out;
        in =parent_pipe[0];
        out =child_pipe[1];
		//in =parent_pipe[1];
        for (int i = 0; i < 10; ++i)
		{
            write(out, parent, strlen(parent) + 1);
            read(in, buff, 50);
            printf("Child: %s", buff);
        }
    }
}
