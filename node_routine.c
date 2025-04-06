/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 23:26:56 by vwautier          #+#    #+#             */
/*   Updated: 2025/04/06 15:37:32 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target(t_node *stacka, t_node *stackb)
{
	t_node	*current;
	t_node	*target;
	long	bigger;

	while (stackb)
	{
		bigger = LONG_MAX;
		current = stacka;
		while (current)
		{
			if (current->data > stackb->data && current->data < bigger)
			{
				bigger = current->data;
				target = current;
			}
			current = current->next;
		}
		if (bigger == LONG_MAX)
			stackb->target = find_min(stacka);
		else
			stackb->target = target;
		stackb = stackb->next;
	}
}

void	position(t_node *stack)
{
	int	i;
	int	med;

	if (!stack)
		return ;
	i = 0;
	med = lst_lenght(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= med)
			stack->med = 1;
		else
			stack->med = 0;
		i++;
		stack = stack->next;
	}
}

static void	price(t_node *stacka, t_node *stackb)
{
	int	lena;
	int	lenb;

	lena = lst_lenght(stacka);
	lenb = lst_lenght(stackb);
	while (stackb)
	{
		stackb->price = stackb->position;
		if (stackb->med == 0)
			stackb->price = lenb - (stackb->position);
		if (stackb->target->med == 1)
			stackb->price += stackb->target->position;
		else
			stackb->price += lena - stackb->target->position;
		stackb = stackb->next;
	}
}

static void	cheapest(t_node *stackb)
{
	t_node	*cheapest;
	long	price;

	if (!stackb)
		return ;
	price = LONG_MAX;
	while (stackb)
	{
		stackb->cheapest = 0;
		if (stackb->price < price)
		{
			price = stackb->price;
			cheapest = stackb;
		}
		stackb = stackb->next;
	}
	cheapest->cheapest = 1;
}

void	node_routine(t_node *stacka, t_node *stackb)
{
	if (!stacka || !stackb)
		return ;
	position(stacka);
	position(stackb);
	target(stacka, stackb);
	price(stacka, stackb);
	cheapest(stackb);
}
