/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:02:45 by itulgar           #+#    #+#             */
/*   Updated: 2024/10/29 19:52:29 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// 1  out yazma terminalden veriir
// 0 input   okuma terminalden alıe
// cat main.c | echo a | efj
int	is_mu_builtin(t_program *program)
{
	if ((zi_strcmp(program->cmd[0], "cd") == 0) || (zi_strcmp(program->cmd[0],
				"unset") == 0) || (zi_strcmp(program->cmd[0], "export") == 0))
		return (1);
	return (0);
}

void	pipe_dup(t_program *program, int *i)
{
	printf("birim\n");
	if (*i == 0)
	{
		if (!redirect_c(program, i)){
			printf("yaptım\n");
			dup2(program->process[*i].fd[1], STDOUT_FILENO);
		}
	}
	else if (*i == program->p_count)
		dup2(program->process[(*i) - 1].fd[0], STDIN_FILENO);
	else
	{
		printf("ay\n");
		dup2(program->process[*i - 1].fd[0], STDIN_FILENO);
		dup2(program->process[*i].fd[1], STDOUT_FILENO);
	}
	if (redirect_c(program, i) && program->fd_output >= 2){
		printf("yaptım\n");
		dup2(program->fd_output, STDOUT_FILENO);
	}
	if (redirect_c(program, i) && program->fd_input >= 2)
		dup2(program->fd_input, STDIN_FILENO);

	int a = 0;
	while (a < program->p_count)
	{
		close(program->process[a].fd[0]);
		close(program->process[a].fd[1]);
		a++;
	}
}