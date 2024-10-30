/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:58:07 by itulgar           #+#    #+#             */
/*   Updated: 2024/10/29 19:38:26 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	main_builtin(t_program *program)
{
	if ((built_strcmp(program->cmd[0], "cd", 2) == 0))
		cd(program, program->cmd);
	else if ((built_strcmp(program->cmd[0], "unset", 5) == 0))
		zi_unset(program, program->cmd);
	if ((zi_strcmp(program->cmd[0], "env") == 0))
		env(program, program->cmd);
	else if ((zi_strcmp(program->cmd[0], "echo") == 0))
		echo(program->cmd);
	else if (built_strcmp(program->cmd[0], "pwd", 3) == 0)
		pwd();
	else if ((zi_strcmp(program->cmd[0], "export") == 0))
	{
		export(program, program->cmd);
	}
}

void	child_builtin(t_program *program)
{
	if ((built_strcmp(program->cmd[0], "cd", 2) == 0))
		cd(program, program->cmd);
	else if ((built_strcmp(program->cmd[0], "unset", 5) == 0))
		zi_unset(program, program->cmd);
	if ((zi_strcmp(program->cmd[0], "env") == 0))
		env(program, program->cmd);
	else if ((zi_strcmp(program->cmd[0], "echo") == 0))
		echo(program->cmd);
	else if (built_strcmp(program->cmd[0], "pwd", 3) == 0)
		pwd();
	else if ((zi_strcmp(program->cmd[0], "export") == 0))
	{
		export(program, program->cmd);
	}
	exit(0);
}
// int is_m_builtin(t_program *program)
// {
// 	if ((built_strcmp(program->cmd[0], "cd", 2) == 0) ||
// 		(built_strcmp(program->built_cmd[0], "unset", 5) == 0) ||
// 		(built_strcmp(program->built_cmd[0], "export", 6) == 0))
// 		return (1);
// 	return (0);
// }

int	is_builtin(t_program *program)
{
	if ((built_strcmp(program->cmd[0], "env", 3) == 0)
		|| (built_strcmp(program->cmd[0], "echo", 4) == 0)
		|| (built_strcmp(program->cmd[0], "pwd", 3) == 0)
		|| (built_strcmp(program->cmd[0], "cd", 2) == 0)
		|| (built_strcmp(program->cmd[0], "unset", 5) == 0)
		|| (built_strcmp(program->cmd[0], "export", 6) == 0))
		return (1);
	return (0);
}

int	run_built_cmd(t_program *program)
{
(void)program;

	// program->built_cmd = zi_split(program, program->input, 32);
	// if(program->built_cmd==NULL)
	// 	return (0);
	// if (is_m_builtin(program) && program->p_count == 0)
	// {
	// 	//main_builtin(program);
	// 	return (0);
	// }
	return (0);
}