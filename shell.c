#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdbool.h>
/**
 * prompt - gives a prompt
 */

void prompt(void)
{
  printf("#cisfun:  ");
}

/**
 * main - a super simple shell tpo excecute commands with their full path
 * @argc: argument count
 * @argv: commandline arguments
 * @envp: environment
 * Return: 0 on sucess
 */

int main(int argc, char *argv[], char *envp[])
{

  pid_t child;
  int i = 0, status, size;
  size_t nchars;
  ssize_t chars;
  char *command, *token, *av[1024];
  
  (void) argc;
  (void) argv;
  size = 0;
  while (true)
    {
      prompt();
      chars = getline(&command, &nchars, stdin);
      printf("The acquired command is: %s\n", command);
      if ((chars == -1))
	{
	  break;
	}
      token = strtok(command, " ");
      printf("Received token: %s\n", token);
      av[size] = token;
      printf("Argument token put in array is: %s\n", av[size]);
      while (true)
	{
	  if (token == NULL)
	    {
	      free(command);
	      break;
	    }
	  size+=1;
	  token = strtok(NULL, command);
	  printf("received token is: %s \n", token);
	  av[size] = token;
	  printf("token put in array is: %s\n", av[size]);
	}
      while (av[i])
	{
	  printf("The array after realloc is now %s\n", av[i]);
	  i++;
	}
      child = fork();
      if (child == 0)
	{
	  if (execve(av[0],av, envp) == -1)
	    printf("cpouldn't execute cmd: %s \n", av[0]);
	}
      else
	{
	  wait(&status);
	  kill(child, SIGTERM);
	}
    }
  return 0;
}
