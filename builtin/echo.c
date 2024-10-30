/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:36:01 by itulgar           #+#    #+#             */
/*   Updated: 2024/10/29 18:16:17 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	flag_control(char **cmd, int *j)
{
	int	i;

	i = 0;
	if (cmd[1][0] == '-' && cmd[1][1] == 'n' && cmd[1][2] == '\0')
	{
		while (cmd[i] != NULL && ft_strncmp(cmd[i], "-n", ft_strlen("-n")) == 0
			&& cmd[i][*j] == '\0')
		{
			if (cmd[i][*j])
				(*j)++;
		}
		return (1);
	}
	return (0);
}

void	echo(char **cmd)
{
	int	flag;
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (cmd[i])
		flag = flag_control(cmd, &j);
	else
		flag=0;
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		if (cmd[i] && cmd[i] && cmd[i])
		{
			printf(" ");
			i++;
		}
		if (!cmd[i])
			break ;
	}
	if (!flag)
		printf("\n");
}
