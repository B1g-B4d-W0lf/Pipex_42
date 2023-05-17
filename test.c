/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:10:14 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/17 02:14:24 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
	

	char *cmd[2] = {"/usr/bin/ls", '\0'};
	char *cmd1[3] = {"/usr/bin/wc", "-l", '\0'};
	int	pid[2];
	int	link[2];

	pipe(link);
	// printf(">>%d\n", link[0]);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		dup2(link[1], STDOUT_FILENO);
		close(link[1]);
		execve(cmd[0], cmd, env);
		exit(26);
	}
	close(link[1]);
	waitpid(pid[0], 0, 0);	
	pid[1] = fork();
	if (pid[1] == 0)
	{
		dup2(link[0], STDIN_FILENO);
		close(link[0]);
		execve(cmd1[0], cmd1, env);
		exit(26);
	}	
	waitpid(pid[1], 0, 0);	
	printf("salut willow\n");
	
	

	
	// printf("hello from parent \n");
	// // int	status;

	// int pid = fork();
	// if (pid == 0)
	// {
	// 	printf("hello from child\n");
	// 	exit(42);
	// }

	// waitpid(pid, 0, 0);
	// // printf(">> %d", status);


	
	// printf("ta capte\n");
}

	// int	fd[2];
	// char	*ls[1];
	// char	buffer[14];
	// pid_t	pid;
	// ls[0] = argv[1];
	// ls[1] = argv[2];

	// if (argc >= 1)
	// {
	// 	fd[0] = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	// 	fd[1] = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0644);
	// 	if (fd[0] < 0 || fd[1] < 0)
	// 	{
	// 		perror("Missing a file are we?");
	// 		exit(0);
	// 	}
	// 	if (pipe(fd) == -1)
	// 	{
	// 		perror("pipe");
	// 		exit (0);
	// 	}
		
	// 	pid = fork();
	// 	if (pid == -1)
	// 	{
	// 		perror("fork");
	// 		exit(0);
	// 	}
	// 	//execve("/bin/ls", ls, NULL);
	// 	if (pid == 0)
	// 	{
	// 		dup2(fd[0]);
	// 		close(fd[0]);
	// 		printf
	// 		close(fd[1]);
	// 		exit(0);
	// 	}
	// 	else
	// 	{	
	// 		close(fd[1]);
	// 		read(fd[0], buffer, 14);
	// 		close(fd[0]);
	// 		printf("Just received this: %s\n", buffer);
	// 		exit(0);
	// 	}
	// }
	// else 
	// 	exit(0);
	// return (0);