/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:18:45 by vwautier          #+#    #+#             */
/*   Updated: 2025/04/06 15:39:08 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stacka)
{
	t_node	*big;

	if (!stacka)
		return ;
	big = find_max(*stacka);
	if ((*stacka) == big)
		ra(stacka, 1);
	else if ((*stacka)->next == big)
		rra(stacka, 1);
	if ((*stacka)->data > (*stacka)->next->data)
		sa(stacka, 1);
}

static void	sort_five(t_node **stacka, t_node **stackb)
{
	int	lena;

	if (!stacka || !stackb)
		return ;
	lena = lst_lenght(*stacka);
	while (lena > 3)
	{
		node_routine(*stacka, *stackb);
		final_rotate(stacka, find_min(*stacka), 'a');
		pb(stacka, stackb);
		lena--;
	}
}

void	push_swap(t_node **stacka, t_node **stackb)
{
	t_node	*smallest;
	int		lena;

	lena = lst_lenght(*stacka);
	if (lena == 5)
		sort_five(stacka, stackb);
	else
	{
		while (lena-- > 3)
			pb(stacka, stackb);
	}
	sort_three(stacka);
	while (*stackb)
	{
		node_routine(*stacka, *stackb);
		move(stacka, stackb);
	}
	position(*stacka);
	smallest = find_min(*stacka);
	if (smallest->med)
		while (*stacka != smallest)
			ra(stacka, 1);
	else
		while (*stacka != smallest)
			rra(stacka, 1);
}
