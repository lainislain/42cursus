#include "../minishell.h"

char	*init_args(char **args, int *types, int index)
{
	char	*arg;
	char	*tmp;

	tmp = ft_strdup(args[index]);
	while (args[++index] && types[index] < 0)
	{
		arg = ft_strjoin(tmp, args[index]);
		free(tmp);
		tmp = ft_strdup(arg);
		free(arg);
	}
	return (tmp);
}

int	get_next_index(char **args, int *types, int index)
{
	while (args[++index])
	{
		if (types[index] > 0)
		{
			return (index);
		}
	}
	return (index);
}

char	**append_arg(char *arg, char **arr)
{
	int		i;
	char	**new_arr;

	i = count(arr);
	new_arr = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (arr && arr[++i])
	{
		new_arr[i] = ft_strdup(arr[i]);
	}
	new_arr[i++] = ft_strdup(arg);
	new_arr[i] = NULL;
	if (arr != NULL)
		free_arr(arr);
	free(arg);
	arr = new_arr;
	return (arr);
}

char	**join_args(char **args, int *types)
{
	int		index;
	char	*arg;
	char	**new_args;

	index = 0;
	new_args = malloc(sizeof(char *) * 1);
	new_args[0] = NULL;
	arg = init_args(args, types, index);
	new_args = append_arg(arg, new_args);
	index = get_next_index(args, types, index);
	while (args[index])
	{
		arg = init_args(args, types, index);
		new_args = append_arg(arg, new_args);
		index = get_next_index(args, types, index);
	}
	return (new_args);
}
