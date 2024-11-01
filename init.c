/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:32:15 by itulgar           #+#    #+#             */
/*   Updated: 2024/10/29 19:16:10 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%s=%s\n", (char *)list->key, (char *)list->content);
		list = list->next;
	}
}

static t_list	*set_env(char **envp)
{
	int		i;
	t_list	*tmp_list;
	char	**tmp;

	tmp_list = NULL;
	i = 0;
	while (envp[i])
	{
		tmp = ft_split(envp[i], '=');
		if (tmp[0] && tmp[1])
			ft_lstadd_back(&tmp_list, ft_lstnew(tmp[1], tmp[0]));
		free_array(tmp);
		i++;
	}
	return (tmp_list);
}

void	signal_handler(int sig)
{
	(void)sig;
		 if (global_signal == 0)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else if (global_signal == IN_HERADOC)
		{
			exit(0);
		}
	
	global_signal = 0;
}

static void	init_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_init_program(t_program *program, char **envp)
{
	program->input = NULL;
	program->envp_list = set_env(envp);
	program->export_list = set_env(envp);
	global_signal = 0;
	program->check_quote = 1;
	program->p_count=0;
	program->fd_input=0;
	program->fd_output=0;
	program->control_q_split = 0;
	program->control_p_split = 0;
	init_signal();
}