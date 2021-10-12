#include "../minishell.h"

char	*sub_dollar(char *str, int index)
{
	int		i;
	char	*tmp;

	i = index;
	while (str[++i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && i == index + 1)
			return (ft_strdup("$"));
		else if ((str[i] == ' ' || str[i] == '\t'))
		{
			tmp = ft_substr(str, index, i - index);
			dollar_handling(&tmp, 0);
			return (tmp);
		}
	}
	if (str[i - 1] == '$')
		return (ft_strdup("$"));
	tmp = ft_substr(str, index, i - index);
	dollar_handling(&tmp, 0);
	return (tmp);
}

int	dollar_len(char *str, int index)
{
	int	i;

	i = index;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (i - index);
	}
	return (i - index);
}
