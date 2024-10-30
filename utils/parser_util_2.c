/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:54:27 by itulgar           #+#    #+#             */
/*   Updated: 2024/10/19 13:08:37 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*walk_to_quote_pipe(t_program *program, char *s, char c)
{
	char	quote_type;

	program->control_q_split = 0;
	quote_type = *s;
	s = in_quote_string(s, quote_type);
	if ((*s != '\'' && *s != '\"') && *s != c)
	{
		while (*s && (*s != '\'' && *s != '\"') && *s != c)
			s++;
	}
	if (*s == c || *s == '\0')
	{
		if (*s)
		{
			s++;
			program->control_q_split = 1;
			return (s);
		}
	}
	return (s);
}

static char	*walk_to_pipe(t_program *program, char *s, char c)
{
	program->control_p_split = 0;
	while (*s && *s != c && (*s != '\'' && *s != '\"'))
		s++;
	if (*s == c || *s == '\0')
	{
		if (*s)
		{
			s++;
			program->control_p_split = 1;
			return (s);
		}
	}
	return (s);
}
char	*walk_string(t_program *program, char *s, char c)
{
	while (*s)
	{
		if (*s == '\'' || *s == '\"')
		{
			s = walk_to_quote_pipe(program, s, c);

			if (program->control_q_split)
				break ;
		}
		else
		{
			s = walk_to_pipe(program, s, c);
			if (program->control_p_split)
				break ;
		}
	}

	return (s);
}