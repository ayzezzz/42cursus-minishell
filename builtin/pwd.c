/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:37:45 by zayaz             #+#    #+#             */
/*   Updated: 2024/10/29 18:16:32 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_pwd(t_program *program, int i, int bigA, int smallA)
{
	if (program->cmd[0][i] && (program->cmd[0][i] == smallA
			|| program->cmd[0][i] == bigA))
		return (1);
	return (0);
}
int	pwd_cmp(t_program *program)
{
	if (is_pwd(program, 0, 80, 112) && is_pwd(program, 1, 87, 119)
		&& is_pwd(program, 2, 68, 100))
		return (1);
	return (0);
}

void	pwd(void)
{
	char pwd[1024];
	getcwd(pwd, 1024);
	printf("%s\n", pwd);
}