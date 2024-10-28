#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
/**
 * main - print the environment varibale
 * @argc: argument count
 * @argv: command args
 * @envp: environment
 */

extern char **environ;

int main(int argc, char *argv[], char *envp[])
{
  /* int first, second; */

  (void) argc;
  (void) argv;
  printf("Let's print using the thirs arg to main\n");
  printf("The address of envp is %p \n", (void *)envp);
  /*for (first = 0; envp[first]; first++)
    {
      printf("%d:  %s\n",first,envp[first]);
    }
  printf("\n\n\n Now let's print using the environ variable\n\n\n");
  for (second = 0; environ[second]; second++)
    {
      printf("%d:  %s\n", second, environ[second]);
      }*/
  printf("The address of environ is %p \n", (void *) environ);
  return (0);
}
