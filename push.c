/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:47:21 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/29 16:04:58 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **dst, t_node **src)
{
	if (!*src)
		return (1);
	if (!*dst)
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
	if (push(stackb, stacka))
		return (1);
	write(1, "pb\n", 3);
	return (0);
}

int	pa(t_node **stacka, t_node **stackb)
{
	if (push(stacka, stackb))
		return (1);
	write(1, "pa\n", 3);
	return (0);
}
