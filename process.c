/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:13:48 by vitor             #+#    #+#             */
/*   Updated: 2023/01/05 17:50:14 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	child_1(t_args *argvs, char **envp)
{
	argvs->fd1 = open(argvs->infile, O_RDONLY);
	dup2(argvs->fd1, 0);
	dup2(argvs->fd[1], 1);
	close(argvs->fd[0]);
	close(argvs->fd[1]);
	close(argvs->fd1);
	if (argvs->cmd)
		execve(argvs->cmd, argvs->args1, envp);
	return (0);
}

static int	child_2(t_args *argvs, char **envp)
{
	argvs->fd1 = open(argvs->outfile, O_TRUNC | O_RDWR | O_CREAT, 0644);
	dup2(argvs->fd1, 1);
	dup2(argvs->fd[0], 0);
	close(argvs->fd[0]);
	close(argvs->fd[1]);
	close(argvs->fd1);
	if (argvs->cmd)
		execve(argvs->cmd, argvs->args2, envp);
	return (0);
}

int	exec(t_args *argvs, char **envp)
{
	int		err;

	err = 0;
	if (pipe(argvs->fd) == -1)
		return (1);
	err = test_cmd(argvs, argvs->args1);
	argvs->pid1 = fork();
	if (argvs->pid1 == 0)
		child_1(argvs, envp);
	free (argvs->cmd);
	err = test_cmd(argvs, argvs->args2);
	argvs->pid2 = fork();
	if (argvs->pid2 == 0)
		child_2(argvs, envp);
	free (argvs->cmd);
	close(argvs->fd[0]);
	close(argvs->fd[1]);
	waitpid(argvs->pid1, NULL, 0);
	waitpid(argvs->pid2, NULL, 0);
	return (err);
}
