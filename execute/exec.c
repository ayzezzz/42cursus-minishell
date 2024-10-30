/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:46 by zayaz             #+#    #+#             */
/*   Updated: 2024/10/29 19:52:42 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// bash-3.2$ / yanlış çalışıyor
// bash: /: is a directory
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
		if (access(tmp_path, F_OK) != -1)
		{
			execve(tmp_path, program->cmd, program->env_cmd);
			exec_error(program, "Command not found", 127);
			exit(0);
		}
		i++;
		free(tmp_path);
	}
}
void	create_fork(t_program *program, int *i)
{
	pid_t	pid_fork;

	exec_cmd(program, i);
	if (!program->cmd[0])
		return ;
	if (redirect_c(program, i))
		redirect(program, i);
	printf("fdfork:%d\n", program->fd_output);
	if (is_builtin(program) && program->p_count == 0)
	{
		printf("girdim\n");
		main_builtin(program);
		return ;
	}
	else
	{
		pid_fork = fork();
		if (pid_fork == -1)
			return ;
		if (pid_fork == 0)
		{
			pipe_dup(program, i);
			if (is_builtin(program) && program->p_count > 0)
				child_builtin(program);
			exec_command(program);
			exit(127);
		}
	}
	// if (pid_fork == 0)
	// 	program->process[*i].pid = pid_fork;
}

void	close_pipe(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->p_count)
	{
		close(program->process[i].fd[0]);
		close(program->process[i].fd[1]);
		i++;
	}
}
void	zi_exec(t_program *program)
{
	int	i;

	i = 0;
	// process pipe için
	// fork komut sayısı kadar
	program->p_count = pipe_count(program);
	program->process = malloc(sizeof(t_process) * (program->p_count + 1));
	while (i < program->p_count)
	{
		pipe(program->process[i].fd);
		i++;
	}
	// cd execute/ > ala olmadı
	i = 0;
	while (i < program->p_count + 1)
	{
		create_fork(program, &i);
		i++;
	}
	close_pipe(program);
		while (waitpid(-1,NULL, 0) > 0)
		;
}
