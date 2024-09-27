#include <stdio.h>
/**
 * main - a program to print all arguments passed to it
 * @argc: argument cpunt
 * @argv: argument vectpor
 * Return: 0 0on success
 */
int main(int argc, char **argv)
{
  int arg = 1;
  (void) argc;

  
  while (argv[arg])
    {
      printf("%s\n",  argv[arg]);
      arg++;
    }
  return (0);
}
