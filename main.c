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

int main(int __attribute__((__unused__)) argc, char __attribute__((__unused__)) **argv, char *envp[])
{
	pid_t child_pid;
	int status;
	char *buffarray[] = {NULL, NULL};
	size_t n;
	ssize_t read;
	char *line;

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
			if (execve(buffarray[0], buffarray, envp) == -1)
				perror("Error exec gone wrong:");
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
