/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:34:32 by vwautier          #+#    #+#             */
/*   Updated: 2025/04/06 15:38:45 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mallocverif(char **strArray, size_t strlen, int position)
{
	int	i;

	strArray[position] = malloc(strlen);
	if (strArray[position] == NULL)
	{
		i = 0;
		while (i < position)
			free(strArray[i++]);
		free(strArray);
		return (1);
	}
	return (0);
}

static size_t	cont_word(char const *s, char c)
{
	size_t	word;
	char	inword;

	word = 0;
	while (*s)
	{
		inword = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			if (!inword)
			{
				word++;
				inword = 1;
			}
			s++;
		}
	}
	return (word);
}

static int	populate(char const *s, char c, char **strArray)
{
	size_t	strlen;
	int		i;

	i = 0;
	while (*s)
	{
		strlen = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			strlen++;
			s++;
		}
		if (strlen)
		{
			if (mallocverif(strArray, strlen + 1, i))
				return (1);
			ft_strlcpy(strArray[i], (char *)s - strlen, strlen + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**strarray;

	if (!s)
		return (NULL);
	words = cont_word(s, c);
	strarray = malloc((words + 1) * sizeof(char *));
	if (!strarray)
		return (NULL);
	strarray[words] = NULL;
	if (populate(s, c, strarray))
	{
		return (NULL);
	}
	return (strarray);
}
