/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:50:28 by itulgar           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/29 19:05:16 by itulgar          ###   ########.fr       */
=======
/*   Updated: 2024/10/27 20:34:24 by itulgar          ###   ########.fr       */
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
<<<<<<< HEAD
#define MINISHELL_H
#define IN_HERADOC 2
#define IN_PARENT 3

#include <stdio.h>
#include "includes/libft/libft.h"
#include "readline/include/readline/history.h"
#include "readline/include/readline/readline.h"
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
=======
# define MINISHELL_H
# define IN_HERADOC 2
# define IN_PARENT 3

# include <stdio.h>
# include "includes/libft/libft.h"
# include "readline/include/readline/history.h"
# include "readline/include/readline/readline.h"
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31

enum			set_meta
{
	Tilde = 4,
	Dolar = 5,
	S_Dolar = 6,
	Redirect = 7,
	Q_Redirect = 8,
};

int				global_signal;

typedef struct s_lexer
{
	char		*cmd;
	int			key;
}				t_lexer;

typedef struct s_process
{
	pid_t		pid;
	int			fd[2];

}				t_process;

typedef struct s_program
{
<<<<<<< HEAD
	t_list *envp_list;
	t_list *export_list;
	char *input;
	char **built_cmd;
	t_lexer ***parser_input;
	int export_flag;
	int check_quote;
	int control_q_split;
	int control_p_split;
	int unset_flag;
	t_process *process;
	int p_count;
	char redi_type;
	char **env_cmd;
	char **sep_path;
	char **cmd;
	int fd_input;
	int fd_output;

} t_program;

int error_message(char *str);
void ft_init_program(t_program *program, char **envp);
void free_array(char **tmp);
int ft_parser(t_program *program, char *input);
int p_quote(t_program *program, char *input);
int p_pipe(t_program *program, char *input);
int p_redirection(t_program *program, char *input);
char **zi_split(t_program *program, char *s, char c);
char *walk_string(t_program *program, char *s, char c);
int zi_count_string(char *s, char c);
void free_program(t_program *program);
void free_parser_input(t_program *program);
int set_meta(t_program *program, char *meta);
void print_list(t_list *list);
int zi_strrchr(const char *s, int c, int i);
void quote_clean(t_program *program);
char *zi_strlcpy(char *dst, const char *src, size_t dstsize);
void zi_striteri(t_lexer *s, void f(t_lexer *));
char *in_quote_string(char *s, char c);
size_t zi_strlen(const char *s, char c, int dhand);
char *dolar_env(t_program *program, char *parser_input);
void dolar_free(char *env_str, char *after_dolar);
void dolar_handler(t_program *program, t_lexer *parser_input);
char *env_count_str(t_lexer *parser_input, int *i);
void echo(char **cmd);
void pwd(void);
void cd(t_program *program, char **cmd);
void env(t_program *program, char **cmd);
void export(t_program *program, char **cmd);
void zi_unset(t_program *program, char **cmd);
void search_set_env(t_program *program, char *key, char *content,
					t_list *envpx_list);
int check_identifier(char *parser_input);
void zi_exec(t_program *program);
void redirect(t_program *program, int *i);
int redirect_c(t_program *program, int *i);
int pipe_count(t_program *program);
char *del_quote(char *dst, const char *src, size_t dstsize);
void signal_handler(int sig);
void heredoc(t_program *program,char *s);
int heredoc_count(t_program *program);
void heredoc_run(t_program *program);

int zi_redirectchr(const char *s, char c);
int heredoc_count(t_program *program);
void equal_in_export(t_program *program, char **cmd, int *i);
int zi_strcmp(const char *s1, const char *s2);
void exec_cmd(t_program *program, int *i);
int zi_strchr(const char *s, int c, char type);

void run_input(t_program *program,char *s);
void run_output(t_program *program, char *s);
void append_output(t_program *program,char *s);
void load_redi(t_program *program, void run_redirect(t_program *program, char *), int *i,
			   int *j, int *z);
void find_loc(char *cmd, int *z);
void quote_skip(char *cmd, int *z);
int pwd_cmp(t_program *program);
void find_path(t_program *program);
void fill_env_cmd(t_program *program);
char *search_env(char *key, t_list *envpx_lst);
void exec_command(t_program *program);
void relative_path(t_program *program);
void create_fork(t_program *program, int *i);
void exec_error(t_program *program, char *s, int exit_code);
void pipe_dup(t_program *program, int *i);
int is_builtin(t_program *program);
void main_builtin(t_program *program);
void child_builtin(t_program *program);
int is_m_builtin(t_program *program);

int is_builtin(t_program *program);
int run_built_cmd(t_program *program);
int built_strcmp(const char *s1, const char *s2, size_t dest_size);
void close_pipe(t_program *program);
int	is_builtin(t_program *program);
=======
	t_list		*envp_list;
	t_list		*export_list;
	char		*input;
	t_lexer		***parser_input;
	int			export_flag;
	int			check_quote;
	int			control_q_split;
	int			control_p_split;
	int			unset_flag;
	t_process	*process;
	int			p_count;
	char		redi_type;
	char		**env_cmd;
	char		**sep_path;
	char		**cmd;
	int			fd;
}				t_program;

int				error_message(char *str);
void			ft_init_program(t_program *program, char **envp);
void			free_array(char **tmp);
int				ft_parser(t_program *program, char *input);
int				p_quote(t_program *program, char *input);
int				p_pipe(t_program *program, char *input);
int				p_redirection(t_program *program, char *input);
char			**zi_split(t_program *program, char *s, char c);
char			*walk_string(t_program *program, char *s, char c);
int				zi_count_string(char *s, char c);
void			free_program(t_program *program);
void			free_parser_input(t_program *program);
int				set_meta(t_program *program, char *meta);
void			print_list(t_list *list);
int				zi_strrchr(const char *s, int c, int i);
void			quote_clean(t_program *program);
char			*zi_strlcpy(char *dst, const char *src, size_t dstsize);
void			zi_striteri(t_lexer *s, void f(t_lexer *));
char			*in_quote_string(char *s, char c);
size_t			zi_strlen(const char *s, char c, int dhand);
char			*dolar_env(t_program *program, char *parser_input);
void			dolar_free(char *env_str, char *after_dolar);
void			dolar_handler(t_program *program, t_lexer *parser_input);
char			*env_count_str(t_lexer *parser_input, int *i);
void			echo(char **cmd);
void			pwd(void);
void			cd(t_program *program, char **cmd);
void			env(t_program *program, char **cmd);
void			export(t_program *program, char **cmd);
void			zi_unset(t_program *program, char **cmd);
void			search_set_env(t_program *program, char *key, char *content,
					t_list *envpx_list);
int				check_identifier(char *parser_input);
void			zi_exec(t_program *program);
void			redirect(t_program *program, int *i);
int				redirect_c(t_program *program, int *i);
int				pipe_count(t_program *program);
char			*del_quote(char *dst, const char *src, size_t dstsize);
void			signal_handler(int sig);
void			heredoc(char *s);
int				heredoc_count(t_program *program);
void			heredoc_run(t_program *program);

int				zi_redirectchr(const char *s, char c);
int				heredoc_count(t_program *program);
void			equal_in_export(t_program *program, char **cmd, int *i);
int				zi_strcmp(const char *s1, const char *s2);
void			exec_cmd(t_program *program, int *i);
int				zi_strchr(const char *s, int c, char type);

void			run_input(t_program *program, char *s);
void			run_output(t_program *program, char *s);
void			append_output(t_program *program, char *s);
void			load_redi(t_program *program, void run_redirect(char *), int *i,
					int *j, int *z);
void			find_loc(char *cmd, int *z);
void			quote_skip(char *cmd, int *z);
int				pwd_cmp(t_program *program);
void			find_path(t_program *program);
void			fill_env_cmd(t_program *program);
char			*search_env(char *key, t_list *envpx_lst);
void			exec_command(t_program *program);
void			relative_path(t_program *program);
void			create_fork(t_program *program, int *i);
void			exec_error(t_program *program, char *s, int exit_code);
void			pipe_dup(t_program *program, int *i);
>>>>>>> 7ba66fc41fd5f7ef1db2ee4c8d18837c7f952e31
#endif