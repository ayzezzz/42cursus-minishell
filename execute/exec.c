/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:46 by zayaz             #+#    #+#             */
/*   Updated: 2024/10/27 20:52:46 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	main_builtin(t_program *program)
{
	if ((zi_strcmp(program->cmd[0], "cd") == 0))
		cd(program, program->cmd);
	else if ((zi_strcmp(program->cmd[0], "unset") == 0))
		zi_unset(program, program->cmd);
	else if ((zi_strcmp(program->cmd[0], "export") == 0))
		export(program, program->cmd);
	else if ((zi_strcmp(program->cmd[0], "env") == 0))
		env(program, program->cmd);
	else if ((zi_strcmp(program->cmd[0], "echo") == 0))
		echo(program->cmd);
	else if (pwd_cmp(program))
		pwd();
	exit(0);
}

int	is_builtin(t_program *program)
{
	if ((zi_strcmp(program->cmd[0], "cd") == 0) || (zi_strcmp(program->cmd[0],
				"unset") == 0) || (zi_strcmp(program->cmd[0], "export") == 0)
		|| (zi_strcmp(program->cmd[0], "env") == 0)
		|| (zi_strcmp(program->cmd[0], "echo") == 0) || pwd_cmp(program))
		return (1);
	return (0);
}

void	exec_command(t_program *program)
{
	int		i;
	char	*tmp_path;

	fill_env_cmd(program);
	find_path(program);
	i = 0;
	if (program->cmd[0][0] == '.') /*|| ft_strchr(program->cmd[0], 47*/
		relative_path(program);
	while (program->sep_path[i])
	{
		tmp_path = ft_strjoin(program->sep_path[i], program->cmd[0]);
		if (access(tmp_path, X_OK) == 0)
		{
			execve(tmp_path, program->cmd, program->env_cmd);
			return ;
		}
		i++;
		free(tmp_path);
	}
}
void	create_fork(t_program *program, int *i)
{
	pid_t	pid_fork;

	pid_fork = 0;
	exec_cmd(program, i);
	if (!program->cmd[0])
		return ;
	// if (program->p_count == 0 && is_builtin(program))
	// {
	// 	// if (redirect_c(program, i))
	// 	// 	redirect(program, i);
	// 	main_builtin(program);
	// 	//dup2(program->fd, STDIN_FILENO);
	// }
	// else
	// {
	if (is_builtin(program))
		main_builtin(program);
	pid_fork = fork();
	if (pid_fork == -1)
		return ;
	if (pid_fork == 0)
	{
		if (redirect_c(program, i))
			redirect(program, i);
		if (is_builtin(program))
			main_builtin(program);
		if (program->p_count > 0)
			pipe_dup(program, i);
		//	dup2(program->fd, STDIN_FILENO);
		else
		{
			exec_command(program);
			exec_error(program, "Command not found", 127);
		}
		exit(0);
		//	}
	}
	waitpid(pid_fork, NULL, 0);
	if (program->p_count > 0)
	{
		close(program->process[*i].fd[0]);
		close(program->process[*i].fd[1]);
	}
}

void	zi_exec(t_program *program)
{
	int	i;

	i = 0;
	// process pipe için
	// fork komut sayısı kadar
	program->p_count = pipe_count(program);
	i = 0;
	while (i < program->p_count + 1)
	{
		if (program->p_count > 0)
		{
			program->process = malloc(sizeof(t_process) * (program->p_count
						+ 1));
			pipe(program->process[i].fd);
		}
		create_fork(program, &i);
		i++;
	}
	i = 0;
	while (program->p_count > 0 && i < program->p_count)
		waitpid(program->process[i++].pid, NULL, 0);
	// close_pipe;
}
