/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:46:48 by zayaz             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/29 18:16:00 by itulgar          ###   ########.fr       */
=======
/*   Updated: 2024/10/26 16:14:56 by itulgar          ###   ########.fr       */
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(t_program *program, char **cmd)
{
	t_list *current;
	int i;
	i = 0;

	while (cmd[i] != NULL && ft_strncmp(cmd[i],
			"env", ft_strlen("env")) == 0 && cmd[i][3] == '\0')
		i++;
	if (cmd[i] == NULL)
	{
		current = program->envp_list;
		while (current != NULL)
		{
				printf("%s=%s\n", (char *)current->key,
					(char *)current->content);
			
			current = current->next;
		}
	}
	else
		printf("env: %s No such file or directory\n", cmd[i]);
<<<<<<< HEAD
			
			
=======
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
}
