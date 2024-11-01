
#include "../minishell.h"

static void	export_add_list(t_program *program, char *key, char *content)
{
	t_list	*node;
	t_list	*node2;

	if (program->export_flag == 0)
	{
		node = ft_lstnew(content, key);
		node2 = ft_lstnew(content, key);
		ft_lstadd_back(&program->envp_list, node);
		ft_lstadd_back(&program->export_list, node2);
	}
	free(key);
	free(content);
}

void	equals(char *cmd, int *k)
{
	while (cmd[*k] != '\0' && cmd[*k] != 61)
		(*k)++;
	if (cmd && cmd[*k] == 61)
		(*k)++;
}

void	equal_in_export(t_program *program, char **cmd, int *i)
{
	char *key;
	int k;
	char *content;
	int equal;
	k = 0;
	equal = 0;

	equals(cmd[*i], &k);
	equal = k;
	key = ft_substr(cmd[*i], 0, k - 1);
	equals(cmd[*i], &k);
	content = ft_substr(cmd[*i], equal, k);
	search_set_env(program, key, content, program->export_list);
	export_add_list(program, key, content);
}