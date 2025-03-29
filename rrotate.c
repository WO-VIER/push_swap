/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:50:22 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/29 16:01:27 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return (1);
	last = last_node(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	(*stack) = last;
	last = last_node(*stack);
	return (0);
}

int	rr(t_node **stacka, t_node **stackb)
{
	if (ra(stacka, 0) || rb(stackb, 0))
		return (1);
	write(1, "rr\n", 3);
	return (0);
}

int	rra(t_node **stacka, int flag)
{
	if (rrotate(stacka))
		return (1);
	if (flag == 1)
		write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_node **stackb, int flag)
{
	if (rrotate(stackb))
		return (1);
	if (flag)
		write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_node **stacka, t_node **stackb)
{
	if (rra(stacka, 0) || rrb(stackb, 0))
		return (1);
	write(1, "rrr\n", 4);
	return (0);
}
