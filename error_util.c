/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:41:33 by vwautier          #+#    #+#             */
/*   Updated: 2025/04/06 15:38:49 by vwautier         ###   ########.fr       */
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

int	handle_duplicate(t_node *stack, int nb)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->data == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
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
