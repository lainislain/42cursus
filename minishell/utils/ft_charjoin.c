#include "../minishell.h"

char	*ft_charjoin(char *str, char c)
{
	int		i;
	int		len;
	char	*ret;

	i = -1;
	len = ft_strlen(str) + 1;
	if (c != '\0')
		len++;
	ret = malloc(sizeof(char) * len);
	while (str[++i])
	{
		ret[i] = str[i];
	}
	if (c != '\0')
		ret[i++] = c;
	ret[i] = '\0';
	free(str);
	return (ret);
}
