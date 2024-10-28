#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/**
 * main - print dirs contained in the PATH
 * Return: 0 on success
 */

int main(void)
{
  char *dirs, *nametok;

  dirs = getenv("PATH");
  nametok = strtok(dirs, ":");
  while (nametok)
    {
      printf("%s\t\n", nametok);
      nametok = strtok(NULL, ":");
    }
  return (0);
}
