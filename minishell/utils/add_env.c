#include "../minishell.h"

char	*join_varvalue(char *var, char *value)
{
	char	*new_value;
	int		i;
	int		j;

	i = -1;
	new_value = malloc(sizeof(char) * (ft_strlen(var) + ft_strlen(value) + 2));
	while (var[++i])
	{
		new_value[i] = var[i];
	}
	new_value[i++] = '=';
	j = -1;
	while (value[++j])
	{
		new_value[i++] = value[j];
	}
	new_value[i] = '\0';
	return (new_value);
}

void	resize_env(char *var, char *value)
{
	int		i;
	int		size;
	char	**new_env;
	char	*new_value;

	i = -1;
	size = count(g_env.env);
	new_env = malloc(sizeof(char *) * (size + 2));
	while (g_env.env[++i])
	{
		new_env[i] = ft_strdup(g_env.env[i]);
	}
	new_value = join_varvalue(var, value);
	new_env[i] = ft_strdup(new_value);
	new_env[i + 1] = NULL;
	free(new_value);
	free_arr(g_env.env);
	free_arr(g_env.sorted);
	g_env.env = new_env;
	sort_env();
}

void	export_add_env(char *var, char *value)
{
	int		i;
	int		var_len;

	i = -1;
	var_len = ft_strlen(var);
	while (g_env.env[++i])
	{
		if (ft_strncmp(var, g_env.env[i], var_len) == 0)
		{
			set_env(var, value);
			return ;
		}
	}
	resize_env(var, value);
}
