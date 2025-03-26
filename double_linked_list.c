/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:29 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/26 22:25:07 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_node(long long data)
{
	t_node *node;
	
	node = malloc(sizeof(t_node));
	if(!node)
		return(NULL);
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

int append_node(t_node **list, int nbr)
{
	t_node *node;
	t_node *last;

	if(!list)
		return (1);
	node = create_node(nbr);
	if(!node)
		return (1);

	if(!*list)
		*list = node;
	else
	{
		last = last_node(*list);
		last->next = node;
		node->prev = last;
	}
	return (0);
}

t_node *last_node(t_node *list)
{
	if(!list)
		return (NULL);

	while(list->next)
		list = list->next;
	return (list);
}

int add_node(t_node **list, t_node *node)
{
	t_node *last;

	if(!list || !node)
		return (1);
	last = last_node(*list);
	if(!last)
		return (1);

	last->next = node;
	node->prev = last;
	node->next = NULL;

	return (0);
}

void free_list(t_node **list)
{
	t_node *currentnode;
	t_node *tmp;

	if(!*list)
		return ;
	
	currentnode = *list;
	while(currentnode)
	{
		tmp = currentnode->next;
		free(currentnode);
		currentnode = tmp;
	}
	*list = NULL;
}

int lst_lenght(t_node *list)
{
	t_node *currentnode;
	int i;

	if(!list)
		return (0);
	i = 0;
	currentnode = list;
	while(currentnode)
	{
		i++;
		currentnode = currentnode->next;
	}

	return(i);
}
/*
void find_index(t_node **list)
{
	t_node	*currentnodei;
	t_node	*currentnodej;
	int		min;	
	
	currentnode = *list;

	while(currentnodei)
	{
		while(currentnodej)
		{
			if(currentnodej->index == -1 && currentnodej->data < min)
				min = currentnodej->data;
		}
		currentnodei = currentnodei->next;
	}
}
*/
void	set_min(t_node **list)
{
	t_node	*currentnodei;
	t_node	*currentnodej;
	int		index;

	if(!list || !*list)
		return ;
	currentnodei = *list;
	while(currentnodei)
	{
		index = 0;
		currentnodej = *list;
		while(currentnodej)
		{
			if(currentnodej->data < currentnodei->data)
				index++;
			currentnodej = currentnodej->next;
		}
		currentnodei->index = index;
		currentnodei = currentnodei->next;
	}
}

t_node	*last_node_with_content(t_node *list)
{
	t_node *currentnode;
	
	if(!list)
		return(NULL);

	currentnode = list;
	while(currentnode->next && currentnode->index != -1)
		currentnode = currentnode->next;

	printf("Last Node with content fnt index : %d\n", currentnode->index);
	return (currentnode);
}