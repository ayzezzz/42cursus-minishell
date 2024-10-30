/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:33:29 by itulgar           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/28 12:15:36 by itulgar          ###   ########.fr       */
=======
/*   Updated: 2024/10/27 16:11:57 by itulgar          ###   ########.fr       */
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_env_cmd(t_program *program)
{
	char	*tmp;
	int		env_size;
	int		i;
	t_list	*list;

	list = program->envp_list;
	i = 0;
	env_size = ft_lstsize(program->envp_list);
	program->env_cmd = malloc(sizeof(char *) * (env_size + 1));
	if (!program->env_cmd)
		return ;
	while (list != NULL)
	{
		tmp = ft_strjoin(list->key, "=");
		program->env_cmd[i] = ft_strjoin(tmp, list->content);
		free(tmp);
		list = list->next;
		i++;
	}
	program->env_cmd[i] = NULL;
<<<<<<< HEAD
=======
	// i = 0;
	// while (program->env_cmd[i])
	// {
	//  printf("%s\n", program->env_cmd[i]);
	//  i++;
	// }
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
}

void	find_path(t_program *program)
{
	int		i;
	char	*content;

	i = 0;
	content = search_env("PATH", program->envp_list);
	if (content == NULL)
		program->sep_path = NULL;
	program->sep_path = ft_split(content, ':');
	while (program->sep_path[i])
	{
		program->sep_path[i] = ft_strjoin(program->sep_path[i], "/");
		i++;
	}
}

void	exec_error(t_program *program, char *s, int exit_code)
{
	printf("minishell: %s: %s\n", program->cmd[0], s);
	exit(exit_code);
}

void	relative_path(t_program *program)
{
	struct stat	file_stat;

	if (stat(program->cmd[0], &file_stat) == 0)
	{
		if (S_ISREG(file_stat.st_mode) == 1)
		{
			if (file_stat.st_mode & S_IXUSR)
			{
				execve(program->cmd[0], program->cmd, program->env_cmd);
				exit(0);
			}
			else
				exec_error(program, "permission denied", 126);
		}
		else if (zi_strcmp(program->cmd[0], ".") == 0)
			exec_error(program, "filename argument required", 2);
		else if (zi_strcmp(program->cmd[0], "..") == 0)
			exec_error(program, "Command not found", 127);
		else
			exec_error(program, "is a directory", 126);
	}
	else
	{
		if (access(program->cmd[0], F_OK) == -1 && ft_strchr(program->cmd[0],
				47))
			exec_error(program, "No such file or directory", 127);
		else
			exec_error(program, "command not found", 127);
	}
}
