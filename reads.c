#include <stdio.h>
/**
 * main - read a line from stdin and print it
 * Return: 0 on sucess
 */
int main(void)
{
  
  char *string;
  size_t wordsize = 0;
  ssize ret;

  printf("#cisfun: ");
  ret = getline(&string, &wordsize, stdin);
  printf("%s\n Has %l chars", string, ret);
  return (0);
}
