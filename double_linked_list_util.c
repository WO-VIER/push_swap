/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 23:28:06 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/29 16:07:08 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *stack)
{
	long long	min;
	t_node		*minnode;

	if (!stack)
		return (NULL);
	min = LLONG_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			minnode = stack;
		}
		stack = stack->next;
	}
	return (minnode);
}

t_node	*find_max(t_node *stack)
{
	t_node	*big;
	int		max;

	if (!stack)
		return (NULL);
	big = stack;
	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			big = stack;
		}
		stack = stack->next;
	}
	return (big);
}

t_node	*find_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
