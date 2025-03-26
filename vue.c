/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vue.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:58:53 by vwautier          #+#    #+#             */
/*   Updated: 2025/02/27 14:46:51 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void afficher_list(t_node *list, int flag)
{
    t_node *currentnode;
    int i;

    if (!list)
    {
        printf("\n=== Empty Stack ===\n");
        return;
    }

	if(!flag)
		printf("List a : \n");
	else
		printf("List b : \n");

    currentnode = last_node(list);
    i = 0;
    printf("\n=== Stack ===\n");
    while (currentnode)
    {
        if (currentnode == list)
		printf("Bottom  -> { value: %-3d | index: %-3d }\n",
			currentnode->data, currentnode->index);
        else if (currentnode->next == NULL)
		printf("Top     -> { value: %-3d | index: %-3d }\n",
			currentnode->data, currentnode->index);
        else
            printf("Node[%d] -> { value: %-3d | index: %-3d }\n",
                i, currentnode->data, currentnode->index);
        i++;
        currentnode = currentnode->prev;
    }
	//printf("Current node prev %s \n", currentnode);
    printf("============\n");
}

void afficher_list_classic(t_node *list)
{
    t_node *currentnode;
    int i = 0;
    
    if (!list)
    {
        printf("\n=== Empty List ===\n\n");
        return;
    }
    
    printf("\n+----------+----------+----------+\n");
    printf("| Position |  Value   |  Index   |\n");
    printf("+----------+----------+----------+\n");
    
    currentnode = list;
    while (currentnode)
    {
        if (currentnode == list)
            printf("| Top  %2d   |   %3d    |   %3d    |\n", i, currentnode->data, currentnode->index);
        else if (currentnode->next == NULL)
            printf("| Bottom %d  |   %3d    |   %3d    |\n", i, currentnode->data, currentnode->index);
        else
            printf("| Node %2d   |   %3d    |   %3d    |\n", i, currentnode->data, currentnode->index);
        i++;
        currentnode = currentnode->next;
    }
    
    printf("+----------+----------+----------+\n\n");
}

void afficher_list_null(t_node *list)
{
	t_node *currentnode;
	int i;

	currentnode = list;

	i = 0;

	while(currentnode)
	{
		printf("Node[%d] -> { value: %-3d | index: %-3d }\n",
			i, currentnode->data, currentnode->index);
		i++;
		currentnode = currentnode->next;
	}
	printf("\n");
}