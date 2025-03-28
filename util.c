/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:39:54 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/28 23:23:51 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long ft_atol(const char *string)
{
	int		csigne;
	long	number;
	int		i;

	i = 0;
	number = 0;
	csigne = 1;
	while ((string[i] == ' ' || (string[i] >= '\t' && string[i] <= '\r')))
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i++] == '-')
			csigne = -1;
	}
	while (string[i] >= '0' && string[i] <= '9')
		number = (number * 10) + (string[i++] - '0');
	return (number * csigne);
}

int	ft_isdigitsign(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	free_split(char **split_argv)
{
	int	i;

	i = 0;
	while (split_argv[i])
	{
		free(split_argv[i]);
		split_argv[i] = NULL;
		i++;
	}
	free(split_argv);
	split_argv = NULL;
}
