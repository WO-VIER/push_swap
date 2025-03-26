/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:34:23 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/01 18:21:46 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **stack)
{
	if (lst_lenght(*stack) < 2)
		return (0);
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->prev->next;
	(*stack)->prev->next = *stack;
	(*stack) = (*stack)->prev;
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

int push(t_node **dst, t_node **src)
{
    if (!src || !*src)
        return (1);
	if(!*dst)
	{
		(*dst) = (*src);
		(*src) = (*src)->next;
		(*src)->prev = NULL;
		(*dst)->next = NULL;
		(*dst)->prev = NULL;
	}
	else
	{
		(*dst)->prev = (*src);
		(*src) = (*src)->next;
		(*dst)->prev->next = (*dst);
		(*dst) = (*dst)->prev;
		(*dst)->prev = NULL;
	}

    return (0);
}

int	pb(t_node **stacka, t_node **stackb)
{
	if(push(stackb, stacka))
		return (1);
	write(1,"pb\n",4);
	return (0);
}

int	pa(t_node **stacka, t_node **stackb)
{
	if(push(stacka, stackb))
		return (1);
	write(1,"pa\n",4);
	return (0);
}

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

int rrotate(t_node **stack)
{
	t_node *tmp;
	t_node *last;

	/*
	Décale d’une position vers le haut tous les élements de la pile .
	Le premier élément devient le dernier.
	*/

	if(!*stack || !(*stack)->next)
		return (1);
	last = last_node(*stack);

	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	(*stack) = last;

	last = last_node(*stack);
	
	return(0);
}

int rr(t_node **stacka, t_node **stackb)
{
	if(ra(stacka,0) || rb(stackb,0))
		return(1);
	write(1,"rr\n",3);
	return(0);
}

int rra(t_node **stacka,int flag)
{
	if(rrotate(stacka))
		return(1);
	if(flag == 3)
		write(1,"ra\n",3);
	if(flag == 1)
		write(1,"rra\n",4);
	return(0);
}

int rrb(t_node **stackb,int flag)
{
	if(rrotate(stackb))
		return(1);
	if(flag)
		write(1,"rrb\n",4);
	return(0);
}

int rrr(t_node **stacka, t_node **stackb)
{
	if(rra(stacka, 0) || rrb(stackb,0))
		return(1);
	write(1,"rrr\n",4);
	return(0);
}