/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:48:16 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/28 22:48:31 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_node **stack)
{
	int len;

	len = lst_lenght(*stack);
	if(!*stack || !stack || len == 1)
		return (1);
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
	return (0);
}

int sa(t_node **stacka, int print)
{
	if(swap(stacka))
		return (1);
	if (print)
		write(1,"sa\n",3);
	return (0);
}


int sb(t_node **stackb, int print)
{
	int datatmp;
	int indextmp;

	if(swap(stackb))
		return (1);
	if (print)
		write(1,"sb\n",3);
	return (0);
}

int ss(t_node **stack, t_node **stackb)
{
	if(sa(stack,0) || sb(stackb,0))
		return (1);
	write(1,"ss\n",3);
	return(0);	
}