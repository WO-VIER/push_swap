/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:49:23 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/28 22:49:31 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rotate(t_node **stack)
{
	t_node *last;
	t_node *tmp;

	if(!*stack || !(*stack)->next)
		return (1);
	last = last_node(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	tmp = (*stack)->next; //Node [1]
	tmp ->prev = NULL;
	(*stack)->next = NULL;
	*stack = tmp;
	//node 0 next = NULL;
	return(0);
}

int ra(t_node **stacka, int flag)
{
	if(rotate(stacka))
		return(1);
	if(flag)
		write(1,"ra\n",3);
	return(0);
}

int rb(t_node **stackb, int flag)
{
	if(rotate(stackb))
		return(1);
	if(flag)
		write(1,"rb\n",3);
	return(0);
}