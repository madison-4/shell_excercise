#include <stdio.h>
#include <unistd.h>

/**
 * main - get id of parent process
 * Return: 0 on success, aany other char otherwise
 */

int main(void)
{
  printf("%u\n", getppid());
  return (0);
}
