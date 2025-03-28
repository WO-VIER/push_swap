/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:11:59 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/26 21:11:10 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	is_sorted(t_node *stack)
{	
	if(!stack)
		return(1);

	while(stack->next)
	{
		if(stack->data > stack->next->data)
			return(0);
		stack = stack->next;
	}
	return(1);
}

t_node *find_min(t_node *stack)
{
	long long min;
	t_node *minnode;

	if(!stack)
		return(NULL);
	min = LLONG_MAX;
	while(stack)
	{
		if(stack->data < min)
		{
			min = stack->data;
			minnode = stack;
		}
		stack = stack->next;
	}
	return(minnode);
}
void target(t_node *stacka, t_node *stackb)
{
	t_node *current;
	t_node *target;
	long long	bigger;

	while(stackb)
	{
		bigger = LLONG_MAX;
		current = stacka;
		while(current)
		{
			if(current->data > stackb->data && current->data < bigger)
			{
				bigger = current->data;
				target = current;
			}
			current = current->next;
		}
		if(bigger == LLONG_MAX)
			stackb->target = find_min(stacka);
		else
			stackb->target = target;
		stackb = stackb->next; 
	}
}	
void position(t_node *stack)
{
	int i;
	int med;

	if(!stack)
		return;
	i = 0;
	med = lst_lenght(stack) / 2;
	while(stack)
	{
		stack->position = i;
		if(i <= med)
			stack->med = 1;
		else
			stack->med = 0;		
		i++;
		stack = stack->next;
	}
}

void price(t_node *stacka, t_node *stackb)
{
	int lena;
	int lenb;

	lena = lst_lenght(stacka);
	lenb = lst_lenght(stackb);
	while(stackb)
    {
        stackb->price = stackb->position;
        if(stackb->med == 0)
            stackb->price = lenb - (stackb->position);
        if(stackb->target->med == 1)
            stackb->price += stackb->target->position;
        else
            stackb->price += lena - stackb->target->position;
        stackb = stackb->next;
    }
}
void cheapest(t_node *stackb)
{
	t_node *cheapest;
	long price;

	if(!stackb)
		return ;
	
	price = LONG_MAX;
	while(stackb)
	{
		stackb->cheapest = 0;
		if(stackb->price < price)
		{
			price = stackb->price;
			cheapest = stackb;
		}
		stackb = stackb->next;
	}
	cheapest->cheapest = 1;
}

t_node *find_cheapest(t_node *stack)
{
	if(!stack)
		return(NULL);
	while(stack)
	{
		if(stack->cheapest == 1)
			return(stack);
		stack = stack->next;
	}
	return(NULL);
}

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

void node_routine(t_node *stacka, t_node *stackb)
{
	if(!stacka || !stackb)
		return;
	position(stacka);
	position(stackb);
	target(stacka, stackb);
	price(stacka, stackb);
	cheapest(stackb);
}
t_node *find_max(t_node *stack)
{
	t_node *big;
	int max;

	if(!stack)
		return(NULL);
	big = stack;
	max = -2147483648;
	while(stack)
	{
		if(stack->data > max)
		{
			max = stack->data;
			big = stack; 
		}
		stack = stack->next;
	}
	return(big);
}

void sort_three(t_node **stacka)
{
	t_node *big;

	if(!stacka)
		return;
	big = find_max(*stacka);
	if((*stacka) == big)
		ra(stacka, 1);
	else if((*stacka)->next == big)
		rra(stacka,1);
	if((*stacka)->data > (*stacka)->next->data)
		sa(stacka, 1);
}

void sort_five(t_node **stacka, t_node **stackb)
{
	int lena;

	if(!stacka || !stackb)
		return;

	lena = lst_lenght(*stacka);
	while(lena > 3)
	{
		node_routine(*stacka, *stackb);
		final_rotate(stacka,find_min(*stacka), 'a');
		pb(stacka, stackb);
		lena--;
	}
}

void push_swap(t_node **stacka, t_node **stackb)
{
	t_node *smallest;
	int lena;

	//printf("Smallest %d",find_min(*stacka)->data);
	lena = lst_lenght(*stacka);
	if(lena == 5)
		sort_five(stacka, stackb);
	else
	{
		while (lena > 3)
		{
			pb(stacka, stackb);
			lena--;
		}
		
	}
	sort_three(stacka);
	while(*stackb)
	{
		node_routine(*stacka, *stackb);
		move(stacka, stackb);
	}
	position(*stacka);
	smallest = find_min(*stacka);
	if(smallest->med)
		while(*stacka != smallest)
			ra(stacka, 1);
	else
		while(*stacka != smallest)
			rra(stacka, 1);
}