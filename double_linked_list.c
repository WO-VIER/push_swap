/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:29 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/29 16:35:35 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(long long data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->cheapest = 0;
	node->index = -1;
	node->position = -1;
	node->med = -1;
	node->price = 0;
	node->target = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	append_node(t_node **list, int nbr)
{
	t_node	*node;
	t_node	*last;

	if (!list)
		return (1);
	node = create_node(nbr);
	if (!node)
		return (1);
	if (!*list)
		*list = node;
	else
	{
		last = last_node(*list);
		last->next = node;
		node->prev = last;
	}
	return (0);
}

t_node	*last_node(t_node *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	lst_lenght(t_node *list)
{
	t_node	*currentnode;
	int		i;

	if (!list)
		return (0);
	i = 0;
	currentnode = list;
	while (currentnode)
	{
		i++;
		currentnode = currentnode->next;
	}
	return (i);
}
