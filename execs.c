#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>

/**
 * main - a program to run ls -l /tmp 5 times
 * @argc: argument count
 * @argv: argument vector array
 * @envp: environment
 * Return: 0 on sucess
 */
int main(int argc, char *arg[], char *envp[])
{

  pid_t child;
  int child_status, i;
  char *argv[] = {"/bin/ls","-l", "/tmp", NULL};
  (void) argc;
  (void) arg;
  
  for (i = 0; i < 5; i++)
    {
      child = fork();
      if (child == 0)
	{
	  if (execve("/usr/bin/ls", argv, envp) == -1)
	    {
	      printf("couldn't execute program\n");
	    }
	}
      else if (child != 0)
	{
	  wait(&child_status);
	  printf("process %d executed\n", i);
	}
    }
  return (0);
}
