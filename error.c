/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:13:53 by vitor             #+#    #+#             */
/*   Updated: 2023/01/05 13:45:50 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_err(int i)
{
	char	*err;

	if (i == 1)
		err = ERROR1;
	if (i == 2)
		err = ERROR2;
	if (i == 3)
		err = ERROR3;
	else
		return ;
	ft_printf("%s\n", err);
}

int	err_chk(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Invalis Args\n");
		return (1);
	}
	if (access(argv[1], R_OK))
	{
		perror("arg1 file error");
		return (1);
	}
	if (!argv[2] || !argv[3])
	{
		ft_printf("redirecionamento ambíguo\n");
		return (1);
	}
	return (0);
}

int	test_cmd(t_args *argvs, char **argvn)
{
	char *tmp;
	
	argvs->index = -1;
	while (argvs->paths[++argvs->index])
	{
		tmp = ft_strjoin(argvs->paths[argvs->index], "/");
		argvs->cmd = ft_strjoin(tmp, argvn[0]);
		if (access(argvs->cmd, X_OK) == 0)
		{
			free (tmp);
			return (0);
		}
		free (argvs->cmd);
		free (tmp);
	}
	argvs->cmd = NULL;
	ft_printf("%s: command not found\n", argvn[0]);
	return (127);
}
