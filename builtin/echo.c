/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:36:01 by itulgar           #+#    #+#             */
/*   Updated: 2024/11/06 13:43:44 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	flag_control(char **cmd, int *i)
{
	if (cmd[1][0] == '-' && cmd[1][1] == 'n' && cmd[1][2] == '\0')
	{
		while (cmd[*i] && zi_strcmp(cmd[*i], "-n") == 0)
		{
			if (cmd[*i])
				(*i)++;
		}
		return (1);
	}
	return (0);
}

void	echo(t_program *program, char **cmd)
{
	int	flag;
	int	i;

	i = 1;
	if (cmd[i])
		flag = flag_control(cmd, &i);
	else
		flag = 0;
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		i++;
		if (cmd[i])
			printf(" ");
	}
	if (!flag)
		printf("\n");
	program->status = 0;
}
