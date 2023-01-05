/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:58:11 by vitor             #+#    #+#             */
/*   Updated: 2022/12/29 17:58:18 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeall(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	count_args_cmd(char *cmd)
{
	int	index;
	int	flag;
	int	count;

	flag = 1;
	index = 0;
	count = 0;
	while (cmd[index])
	{
		if (cmd[index] == '\'')
			flag *= -1;
		if (cmd[index] == -1 && flag == 1)
			count++;
		index++;
	}
	return (count);
}
