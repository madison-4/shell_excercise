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

int main(void)
{

  pid_t child;
  int i = 0, status;
  size_t nchars;
  ssize_t chars;
  char *command = NULL, *token, **av;

  av = malloc(1024 * (sizeof(char *)));
  while (true)
    {
      prompt();
      chars = getline(&command, &nchars, stdin);
      if (chars == -1)
	break;
      token = strtok(command, "\t\n");
      av = malloc(1024 * (sizeof (char *)));
      if (av == NULL)
	{
	  perror("cannot allocate data to array");
	  exit(1);
	}
      for (i = 0;token; i++)
	{
	  av[i] = token;
	  token = strtok(NULL, "\t\n");
	}
      av[++i] = NULL;
      child = fork();
      if (child == 0)
	{
	  if (execve(av[0], av, NULL) == -1)
	    perror("Error executing that partiocular command");
	}
      else
	wait(&status);
      i = 0;
      free(command);
    }
  free(av);
  return (0);
}
