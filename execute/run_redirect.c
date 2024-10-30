/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:04:12 by zayaz             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/29 19:33:27 by itulgar          ###   ########.fr       */
=======
/*   Updated: 2024/10/27 20:29:20 by itulgar          ###   ########.fr       */
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_output(t_program *program, char *s)
{
<<<<<<< HEAD
	program->fd_output = open(s, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (program->fd_output == -1)
=======
	int	fd;

	fd = open(s, O_CREAT | O_RDWR | O_TRUNC, 0644);
	program->fd = dup(fd);
	if (fd == -1)
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
	{
		perror("Error opening file");
		exit(1);
	}
<<<<<<< HEAD
	// if (dup2(fd, STDOUT_FILENO) == -1)
	// {
	// 	perror("Error opening file");
	// 	close(fd);
	// 	exit(1);
	// }
	// close_pipe(program);
=======
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Error opening file");
		close(fd);
		return ;
	}
	close(fd);
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
}

void	run_input(t_program *program, char *s)
{
<<<<<<< HEAD
	program->fd_input = open(s, O_RDONLY);
	if (program->fd_input == -1)
=======
	int	fd;

	fd = open(s, O_RDONLY);
	program->fd = dup(fd);
	if (fd == -1)
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
	{
		write(0, "minishell: ", 14);
		perror(s);
		return ;
	}
<<<<<<< HEAD
	// if (dup2(fd, STDIN_FILENO) == -1)
	// {
	// 	perror("Error opening file");
	// 	close(fd);
	// 	return ;
	// }
	// close(fd);
	// close_pipe(program);
=======
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Error opening file");
		close(fd);
		return ;
	}
	close(fd);
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
}

void	append_output(t_program *program, char *s)
{
<<<<<<< HEAD
	program->fd_output = open(s, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (program->fd_output == -1)
=======
	int	fd;

	fd = open(s, O_CREAT | O_RDWR | O_APPEND, 0644);
	program->fd = dup(fd);
	if (fd == -1)
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
	{
		perror("Error opening file");
		return ;
	}
<<<<<<< HEAD
	// if (dup2(fd, STDOUT_FILENO) == -1)
	// {
	// 	perror("Error opening file");
	// 	close(fd);
	// 	return ;
	// }
	// close(fd);
	// close_pipe(program);
=======
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Error opening file");
		close(fd);
		return ;
	}
	close(fd);
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
}
