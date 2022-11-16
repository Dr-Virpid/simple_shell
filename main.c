/*
 * File: main.c
 * Auth: Simon Tagbor
 * Ogunbona Jesutofunmi
 */

/**
 * main - Runs a simple UNIX command interpreter.
 *
 * Return: Always 0.
 */

#include "shell.h"

int main(void)
{
	pid_t child_pid;
	int status;
	char *buffarray[] = {NULL, NULL};
	size_t n;
	ssize_t read;
	char *line;
	char *envp[5];

	line = NULL;
	while (1)
	{
		printf("$ ");
		n = 0;
		read = getline(&line, &n, stdin);
		if (read  == -1)
		{
			printf("read failed\n");
			return (1);
		}
		buffarray[0] = strtok(line, " ");

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error child:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(line, buffarray, envp) == -1)
				printf("%s: No such file or directory\n", buffarray[0]);
		}
		else
		{
			wait(&status);
		}
		/* free the memory */
		free(line);
	}
	return (0);
}
