#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/**
 * node - a struct to hold the directories of path
 * @dir: path directory
 * next: next pointer
 */

typedef struct node {
  char *dir;
  struct node *next;
} node_t;
/**
 * create - creates a new list for the path dirs
 * @head: head of the list
 * @path: diorctory of path
 * Return: pointer to new node, 1 otherwise
 */

node_t *create(node_t *head, char *path)
{
  node_t *paths, *temp = head;

  paths = malloc(sizeof(node_t));
  if (paths == NULL)
    {
      printf("couldn't allocate memory for new path\n");
      return (NULL);
    }
  paths->dir = strdup(path);
  paths->next = NULL;
  while (temp->next)
    temp = temp->next;
  temp->next = paths;
  return (paths);
}
/**
 * printlist - function to print a linked list
 * @head: head of the list
 */
void printlist(node_t *head)
{
  node_t *temp = head;

  while (temp->next)
    {
      printf("%s \n", temp->dir);
      temp = temp->next;
    }
}
/**
 * main - print dirs contained in the PATH
 * Return: 0 on success
 */

int main(void)
{
  char *dirs, *nametok;
  node_t *head;

  dirs = getenv("PATH");
  nametok = strtok(dirs, ":");
  head = malloc(sizeof(node_t));
  if (head == NULL)
    return (1);
  head->next = NULL;
  head->dir = nametok;
  while (nametok)
    {
      printf("%s\t\n", nametok);
      nametok = strtok(NULL, ":");
      create(head, nametok);
    }
  printlist(head);
  return (0);
}
