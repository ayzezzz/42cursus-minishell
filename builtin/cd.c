/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:23:50 by zayaz             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/29 17:48:33 by itulgar          ###   ########.fr       */
=======
/*   Updated: 2024/10/26 19:37:23 by itulgar          ###   ########.fr       */
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*search_env(char *key, t_list *envpx_lst)
{
	t_list	*current;
	char	*envpx;

	envpx = NULL;
	current = envpx_lst;
	while (current && current->key)
	{
		if (zi_strcmp(current->key, key) == 0)
		{
			envpx = current->content;
			break ;
		}
		current = current->next;
	}
	return (envpx);
}
void	search_set_env(t_program *program, char *key, char *content,
		t_list *envpx_list)
{
	t_list	*current;

	current = envpx_list;
	while (current)
	{
		if (zi_strcmp(current->key, key) == 0)
		{
			program->export_flag = 1;
			current->content = zi_strlcpy(current->content, content,
					ft_strlen(content));
			return ;
		}
		if (!current->next)
			break ;
		current = current->next;
	}
	program->export_flag = 0;
}

static void	update_env(t_program *program, char *cwd)
{
	char	*oldpwd;
	char	*oldpwd_export;

	oldpwd = search_env("PWD", program->envp_list);
	oldpwd_export = search_env("PWD", program->export_list);
	if (!oldpwd || !oldpwd_export)
	{
		search_set_env(program, "OLDPWD", "\"\"", program->envp_list);
		search_set_env(program, "OLDPWD", "\"\"", program->export_list);
	}
	else
	{
		search_set_env(program, "OLDPWD", oldpwd, program->envp_list);
		search_set_env(program, "PWD", cwd, program->envp_list);
		search_set_env(program, "OLDPWD", oldpwd_export, program->export_list);
		search_set_env(program, "PWD", cwd, program->export_list);
	}
}

static void	cd_path(t_program *program, char *cmd)
{
	char	*path;
	char	cwd[1024];

	path = cmd;
	if (access(path, F_OK) == 0)
	{
		if (chdir(path) == 0)
		{
			if (getcwd(cwd, sizeof(cwd)) != NULL)
				update_env(program, cwd);
		}
	}
	else
		printf("cd: %s No such file or directory\n", path);
}

void	cd(t_program *program, char **cmd)
{
	char	*home;
	char	cwd[1024];

	if (cmd[1] == NULL || (zi_strcmp(cmd[1], "~") == 0))
	{
		home = search_env("HOME", program->envp_list);
		if (home && chdir(home) == 0)
			getcwd(cwd, sizeof(cwd));
	}
	else if (zi_strcmp(cmd[1], "..") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			if (chdir("..") == 0)
				getcwd(cwd, sizeof(cwd));
		}
	}
	else if (cmd[1])
	{
		cd_path(program, cmd[1]);
		return ;
	}
	update_env(program, cwd);
}
