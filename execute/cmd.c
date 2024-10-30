/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:45:31 by itulgar           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/29 19:42:14 by itulgar          ###   ########.fr       */
=======
/*   Updated: 2024/10/26 14:19:32 by itulgar          ###   ########.fr       */
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fillable_cmd(t_program *program, char *cmd, int *z, int *start, int *k)
{
	*start = *z;
	while (cmd[*z] && (cmd[*z] != '<' && cmd[*z] != '>'))
	{
		if (cmd[*z] != '\'' && cmd[*z] != '\"')
			(*z)++;
		else
			quote_skip(cmd, z);
	}
	if (cmd[*z] == '\0' || (cmd[*z] == '<' || cmd[*z] == '>'))
	{
		program->cmd[*k] = ft_substr(cmd, *start, (*z - *start));
		(*k)++;
	}
}

void	fillable_count(char *cmd, int *z, int *count)
{
	while (cmd[*z] && (cmd[*z] != '<' && cmd[*z] != '>'))
	{
		if (cmd[*z] != '\'' && cmd[*z] != '\"')
			(*z)++;
		else
			quote_skip(cmd, z);
	}
	if (cmd[*z] == '\0' || (cmd[*z] == '<' || cmd[*z] == '>'))
		(*count)++;
}
void	redi_skip(t_lexer **parser_input, int *z, int *j)
{
	char	redi_type;

	redi_type = parser_input[*j]->cmd[*z];
	(*z)++;
	if (parser_input[*j]->cmd[*z] == redi_type)
		(*z)++;
	if (parser_input[*j]->cmd[*z] == '\0')
	{
		(*j)++;
		*z = 0;
	}
	while (parser_input[*j]->cmd[*z] && (parser_input[*j]->cmd[*z] != '<'
			&& parser_input[*j]->cmd[*z] != '>'))
	{
		if (parser_input[*j]->cmd[*z] != '\''
			&& parser_input[*j]->cmd[*z] != '\"')
			(*z)++;
		else
			quote_skip(parser_input[*j]->cmd, z);
	}
}
int	cmd_counter(t_program *program, int *i)
{
	int	j;
	int	count;
	int	z;

	j = 0;
	count = 0;
	z = 0;
	while (program->parser_input[*i] != NULL && program->parser_input[*i][j]
		&& program->parser_input[*i][j]->cmd)
	{
		z = 0;
		while (program->parser_input[*i][j]->cmd[z])
		{
			if (program->parser_input[*i][j]->cmd[z] != '<'
				&& program->parser_input[*i][j]->cmd[z] != '>')
				fillable_count(program->parser_input[*i][j]->cmd, &z, &count);
			else
			
				redi_skip(program->parser_input[*i], &z, &j);
			
		}
		j++;
	}
	return (count);
}
<<<<<<< HEAD
=======
// gel"sene">">>a"<<susma
//>echo a> r.txt >b.txt
//<"<<"gi <<abu">"a"p""da">el">>" gel<"se">">>m"<<k >>s "<<"
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31

void	fill_cmd(t_program *program, int *i)
{
	int	z;
	int	k;
	int	start;
	int	j;

	z = 0;
	k = 0;
	start = 0;
	j = 0;
	j = 0;
	while (program->parser_input[*i] && program->parser_input[*i][j]
		&& program->parser_input[*i][j]->cmd)
	{
		z = 0;
		while (program->parser_input[*i][j]->cmd[z])
		{
			if (program->parser_input[*i][j]->cmd[z] != '<'
				&& program->parser_input[*i][j]->cmd[z] != '>')
				fillable_cmd(program, program->parser_input[*i][j]->cmd, &z,
					&start, &k);
			else
				redi_skip(program->parser_input[*i], &z, &j);
		}
		j++;
	}
	program->cmd[k] = NULL;
}

void	exec_cmd(t_program *program, int *i)
{
	int	cmd_len;
<<<<<<< HEAD


	cmd_len = cmd_counter(program, i);
=======
	int	k;

	cmd_len = cmd_counter(program, i);
	//printf("cmd_len:%d  ", cmd_len);
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
	program->cmd = malloc(sizeof(char **) * (cmd_len + 1));
	if (!program->cmd)
	{
		perror("memory failure allocation");
		exit(1);
	}
	fill_cmd(program, i);
<<<<<<< HEAD
=======
	k = 0;
	// if (!program->cmd[k])
	// 	printf("NULLIM\n");
	// while (program->cmd[k])
	// {
	// 	printf("cmd:%s--- ", program->cmd[k]);
	// 	k++;
	// }
	// 	printf("\n");
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
}