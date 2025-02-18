/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:13:50 by vitor             #+#    #+#             */
/*   Updated: 2025/02/18 15:47:09 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	argvs->args1 = ft_split(spc_to_np(argv[2]), -1);
	argvs->args2 = ft_split(spc_to_np(argv[3]), -1);
	argvs->paths = ft_split(pathfinder(envp), ':');
	quotes_trim(argvs->args1, count_args_cmd(argv[2]));
	quotes_trim(argvs->args2, count_args_cmd(argv[3]));
	return (0);
}

void	quotes_trim(char **str, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i <= len)
	{
		tmp = str[i];
		str[i] = ft_strtrim(str[i], "'");
		free (tmp);
		i++;
	}
}
