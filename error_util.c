/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:41:33 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/28 23:35:11 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_handler(char **split_argv, t_node **list)
{
	if (split_argv)
		free_split(split_argv);
	if (list)
		free_list(list);
	write(2, "Error\n", 6);
	exit(1);
}

int	handle_duplicate(char **split_argv, t_node *list)
{
	t_node	*currentnodej;
	t_node	*basei;
	int		i;
	int		j;

	currentnodej = NULL;
	basei = NULL;
	i = 0;
	if (split_argv && split_argv[i])
	{
		while (split_argv[i])
		{
			j = 0;
			while (split_argv[j])
			{
				if ((ft_atol(split_argv[i]) == ft_atol(split_argv[j]))
					&& i != j)
					return (1);
				j++;
			}
			i++;
		}
	}
	else if (list)
	{
		basei = list;
		while (basei)
		{
			currentnodej = basei->next;
			while (currentnodej)
			{
				if (basei->data == currentnodej->data)
					return (1);
				currentnodej = currentnodej->next;
			}
			basei = basei->next;
		}
	}
	return (0);
}
