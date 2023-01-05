/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:20:04 by vitor             #+#    #+#             */
/*   Updated: 2023/01/03 23:19:39 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>
# include "./Libft/Include/libft.h"
# include "pipex.h"
# include <stdio.h>
# include <fcntl.h>
# include "errors.h"

typedef struct s_args
{
	char	**paths;
	char	**args1;
	char	**args2;
	char	*infile;
	char	*outfile;
	char	*cmd;
	char	*tmp;
	int		fd[2];
	int		fd1;
	int		index;
	int		pid1;
	int		pid2;
}t_args;

char	*pathfinder(char *envp[]);
int		exec(t_args *argvs, char **envp);
int		err_chk(int argc, char **argv);
char	*spc_to_np(char *str);
int		get_params(t_args *argvs, char **argv, char **envp);
void	init_var(t_args *argvs, char **argv);
void	print_err(int i);
void	freeall(char **str);
int		test_cmd(t_args *argvs, char **argvn);
int		count_args_cmd(char *cmd);
void	quotes_trim(char **str, int len);

#endif