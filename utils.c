/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:13:50 by vitor             #+#    #+#             */
/*   Updated: 2023/01/05 13:17:33 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_var(t_args *argvs, char **argv)
{
	if (argv[1])
		argvs->infile = argv[1];
	if (argv[4])
		argvs->outfile = argv[4];
	if (access(argv[4], R_OK | W_OK))
		open(argv[4], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
}

char	*pathfinder(char *envp[])
{
	int	index;

	index = 0;
	while (!ft_strnstr(envp[index], "PATH=", 5))
		index++;
	return (envp[index] + 5);
}

char	*spc_to_np(char *str)
{
	int	index;
	int	flag;

	flag = 1;
	index = 0;
	while (str[index])
	{
		if (str[index] == '\'')
			flag *= -1;
		if (str[index] == ' ' && flag == 1)
			str[index] = -1;
		index++;
	}
	return (str);
}

int	get_params(t_args *argvs, char **argv, char **envp)
{
	int	i;
	int	max;
	char *tmp;

	i = 0;
	argvs->args1 = ft_split(spc_to_np(argv[2]), -1);
	argvs->args2 = ft_split(spc_to_np(argv[3]), -1);
	argvs->paths = ft_split(pathfinder(envp), ':');
	max = count_args_cmd(argv[2]);
	while (i <= max)
	{
		
		tmp = argvs->args1[i];
		argvs->args1[i] = ft_strtrim(argvs->args1[i], "'");
		free (tmp);
		i++;
	}
	max = count_args_cmd(argv[3]);
	i = 0;
	while (i <= max)
	{
		tmp = argvs->args2[i];
		argvs->args2[i] = ft_strtrim(argvs->args2[i], "'");
		free (tmp);
		i++;
	}
	return (0);
}
