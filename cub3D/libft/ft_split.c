/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 01:01:40 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/20 02:59:15 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *s, char c)
{
	size_t	i;
	size_t	isc;
	size_t	count;

	isc = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			isc = 1;
		else if (isc == 1)
		{
			isc = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_word_len(char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	**ft_free_words(char **words, size_t i)
{
	while (--i)
		free(words[i]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;
	size_t	j;
	size_t	words_count;
	size_t	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	words_count = ft_count_words((char *)s, c);
	words = (char **)malloc(sizeof(char *) * (words_count + 1));
	while (i < words_count)
	{
		while (s[j] == c)
			j++;
		word_len = ft_word_len((char *)s + j, c);
		words[i] = ft_substr(s, j, word_len);
		if (!words[i])
			return (ft_free_words(words, i));
		i++;
		j = j + word_len + 1;
	}
	words[words_count] = NULL;
	return (words);
}
