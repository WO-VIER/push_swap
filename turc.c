/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:01:00 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/01 17:02:51 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// Trouve l'élément avec l'index le plus élevé dans la pile
int find_max_index(t_node *stack)
{
    int max_index = -1;
    t_node *current = stack;
    
    while (current)
    {
        if (current->index > max_index)
            max_index = current->index;
        current = current->next;
    }
    return (max_index);
}

// Calcule le nombre de chunks basé sur la taille de la pile
int get_chunk_count(int size)
{
    if (size <= 100)
        return (5);  // Pour 100 nombres: 5 chunks
    else
        return (11); // Pour 500 nombres: 11 chunks
}

// Trouve le noeud avec index dans le chunk actuel
t_node *find_in_chunk(t_node *stack, int chunk_start, int chunk_end)
{
    t_node *current = stack;
    
    while (current)
    {
        if (current->index >= chunk_start && current->index <= chunk_end)
            return (current);
        current = current->next;
    }
    return (NULL);
}

// Calcule les mouvements nécessaires pour amener un noeud au sommet
int moves_to_top(t_node *stack, t_node *target)
{
    int pos = 0;
    t_node *current = stack;
    
    while (current != target)
    {
        pos++;
        current = current->next;
    }
    
    int size = lst_lenght(stack);
    if (pos <= size / 2)
        return (pos);           // Utiliser ra
    else
        return (pos - size);    // Utiliser rra
}

// Déplace le noeud au sommet de la pile
void move_to_top(t_node **stack, t_node *target, int flag)
{
    int moves = moves_to_top(*stack, target);
    
    if (moves >= 0)
    {
        while (moves--)
            ra(stack, flag);
    }
    else
    {
        moves = -moves;
        while (moves--)
            rra(stack, flag);
    }
}

// Trouve le meilleur élément à pousser de B vers A
int find_best_to_push(t_node *stackb)
{
    t_node *current = stackb;
    int max_idx = find_max_index(stackb);
    int best_index = -1;
    int min_moves = INT_MAX;
    
    while (current)
    {
        int moves = abs(moves_to_top(stackb, current));
        if (moves < min_moves)
        {
            min_moves = moves;
            best_index = current->index;
        }
        current = current->next;
    }
    return (best_index);
}

// L'algorithme principal de tri par chunks
int chunk_sort(t_node **stacka, t_node **stackb)
{
    if (!stacka || !*stacka || is_sorted(*stacka))
        return (0);
    
    int size = lst_lenght(*stacka);
    int chunk_count = get_chunk_count(size);
    int chunk_size = (size / chunk_count) + 1;
    
    // Pousse les éléments vers B en chunks
    for (int i = 0; i < chunk_count; i++)
    {
        int chunk_start = i * chunk_size;
        int chunk_end = chunk_start + chunk_size - 1;
        if (chunk_end >= size)
            chunk_end = size - 1;
        
        // Pousse tous les éléments du chunk actuel vers B
        while (1)
        {
            t_node *target = find_in_chunk(*stacka, chunk_start, chunk_end);
            if (!target)
                break;
            
            move_to_top(stacka, target, 1);
            pb(stacka, stackb);
        }
    }
    
    // Ramène les éléments de B vers A dans l'ordre
    while (*stackb)
    {
        t_node *current = *stackb;
        int max_idx = find_max_index(*stackb);
        
        while (current && current->index != max_idx)
            current = current->next;
        
        move_to_top(stackb, current, 1);
        pa(stacka, stackb);
    }
    
    return (0);
}