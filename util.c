/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:30:30 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/01 18:22:42 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tiny_sort(t_node **list)
{
    int size;
    
    if (!list || !*list)
        return;
        
    size = lst_lenght(*list);
    
    // Pour 2 éléments
    if (size == 2)
    {
        if ((*list)->data > (*list)->next->data)
            sa(list, 1);
        return;
    }
    
    // Pour 3 éléments
    if (size == 3)
    {
        // Identifier le plus grand élément
        int max_index = 0;
        t_node *current = *list;
        t_node *max_node = current;
        int pos = 0;
        
        while (current)
        {
            if (current->data > max_node->data)
            {
                max_node = current;
                max_index = pos;
            }
            current = current->next;
            pos++;
        }
        
        // Positionner le plus grand élément en bas
        if (max_index == 0)
            ra(list, 1);
        else if (max_index == 1)
            rra(list, 1);
            
        // Si les deux premiers sont désordonnés, faire un sa
        if ((*list)->data > (*list)->next->data)
            sa(list, 1);
    }
}