#include<string.h>
#include<stdlib.h>
#include<stdio.h>

/**
 * main - a program to reveive a string anmd split it
 * no arguments
 * Return: 0 on success
 */
int main(void)
{
  char *line = NULL, *delim = " ", *tok;
  size_t n = 0;
  int chars = 1;


  while (chars != EOF)
    {

      printf("#cisfun $: ");
      chars = getline(&line, &n, stdin);
  if (chars == -1)
    {
      printf("couldn't read input\n");
      free(line);
      exit(1);
    }
  else
    {
      printf(" the line %s \n", line);
      tok = strtok(line, delim);
      printf("%s\n", tok);
      while (tok != NULL)
	{
	  tok = strtok(NULL, delim);
	  if (tok == NULL)
	    break;
	  printf("%s\n", tok);
	}
    }
    }
  return (0);
}
