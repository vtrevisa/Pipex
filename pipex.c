/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:13:55 by vitor             #+#    #+#             */
/*   Updated: 2023/01/05 13:20:38 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	argvs;
	int		i;

	if (err_chk(argc, argv))
		return (1);
	init_var(&argvs, argv);
	get_params(&argvs, argv, envp);
	i = exec(&argvs, envp);
	if (i)
	{
		freeall(argvs.args1);
		freeall(argvs.args2);
		freeall(argvs.paths);
		print_err(i);
		return (i);
	}
	freeall(argvs.args1);
	freeall(argvs.args2);
	freeall(argvs.paths);
	return (0);
}
