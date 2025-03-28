/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vue.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:58:53 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/28 23:30:20 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
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