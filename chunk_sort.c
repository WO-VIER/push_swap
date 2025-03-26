/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:08:51 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/01 17:09:11 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int chunked_sort(t_node **stacka, t_node **stackb)
{
    int size = lst_lenght(*stacka);
    int chunk_size = size / 5;  // Pour 100 nombres, 5 chunks de 20
    
    // Pour chaque chunk (des plus petits indices aux plus grands)
    for (int chunk_start = 0; chunk_start < size; chunk_start += chunk_size) 
    {
        int chunk_end = chunk_start + chunk_size - 1;
        
        // Nombre d'éléments à pousser dans ce chunk
        int elements_to_push = chunk_size;
        
        // Pousse tous les éléments du chunk actuel vers B
        while (elements_to_push > 0) 
        {
            // Si l'élément du dessus est dans le chunk actuel
            if ((*stacka)->index >= chunk_start && (*stacka)->index <= chunk_end) 
            {
                pb(stacka, stackb);
                elements_to_push--;
            }
            else 
            {
                ra(stacka, 1);
            }
        }
    }
    
    // Ramène les éléments de B vers A par ordre décroissant d'index
    while (*stackb)
    {
        // Trouve le plus grand index dans B
        t_node *current = *stackb;
        int max_index = -1;
        int position = 0;
        int max_pos = 0;
        
        while (current)
        {
            if (current->index > max_index)
            {
                max_index = current->index;
                max_pos = position;
            }
            position++;
            current = current->next;
        }
        
        // Déplace le plus grand élément en haut de B
        int size_b = lst_lenght(*stackb);
        if (max_pos <= size_b / 2)
        {
            while (max_pos--)
                rb(stackb, 1);
        }
        else
        {
            while (max_pos++ < size_b)
                rrb(stackb, 1);
        }
        
        // Push vers A
        pa(stacka, stackb);
    }
    
    return (0);
}