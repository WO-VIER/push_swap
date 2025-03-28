/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 23:26:15 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/28 23:26:26 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_top(t_node **stacka, t_node **stackb, t_node *cheapest)
{
	while(*stacka != cheapest->target && *stackb != cheapest)
		rr(stacka, stackb);
	position(*stacka);
	position(*stackb);
}

void rrotate_top(t_node **stacka, t_node **stackb, t_node *cheapest)
{
	while(*stacka != cheapest->target && *stackb != cheapest)
		rrr(stacka, stackb);
	position(*stacka);
	position(*stackb);
}

void final_rotate(t_node **stack, t_node *top_node, char c)
{
	while(*stack != top_node)
	{
		if(c == 'a')
		{
			if(top_node->med)
				ra(stack, 1);
			else
			{
				//printf("Stack data finale rotate: %d\n", (*stack)->data);
				rra(stack, 1);
			}
		}
		else if(c == 'b')
		{
			if(top_node->med)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
	
}


void move(t_node **stacka, t_node **stackb)
{
	t_node *cheap;

	if(!stacka || !stackb)
		return;
	cheap = find_cheapest(*stackb);
	//printf("Cheapest : %d\n", cheap->cheapest);
	//printf("Cheapest : %d\n", cheap->index);
	//afficher_list_null(*stackb);
	//exit(1);
	
	if (cheap->med && cheap->target->med)
		rotate_top(stacka, stackb, cheap);
	else if(!(cheap->med) && !(cheap->target->med))
		rrotate_top(stacka, stackb, cheap);
	//afficher_list_null(*stacka);
	//afficher_list_null(*stackb);
	//printf("Cheapest target : %d\n", cheap->target->index);
	//exit(1);
	//position(*stacka);
	//position(*stackb);
	
	//exit(1);
	final_rotate(stackb, cheap, 'b');
	final_rotate(stacka, cheap->target, 'a');
	//afficher_list_null(*stacka);
	//afficher_list_null(*stackb);

	pa(stacka, stackb);
}