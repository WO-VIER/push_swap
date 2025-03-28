/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:40:48 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/26 21:55:35 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int cheapest;
	int data;
	int	index;
	int position;
	int med;
	int price;
	struct s_node *target;
	struct s_node *prev;
	struct s_node *next;
} t_node;

typedef struct s_cost
{
    int index;         // Index de l'élément
    int cost_a;        // Coût pour amener l'élément au sommet de A
    int cost_b;        // Coût pour positionner dans B
    int total_cost;    // Coût total
} t_cost;

void tiny_sort(t_node **list);


int append_node(t_node **list, int nbr);
t_node *create_node(long long data);
t_node *last_node(t_node *list);
int		add_node(t_node **list, t_node *node);
t_node	*last_node_with_content(t_node *list);
void	free_list(t_node **list);
int		create_list(char **argv, t_node **list);
void 	free_split(char **argv_split);
int 	error_handler(char **split_argv, t_node **list);
int 	handle_duplicate(char **split_argv, t_node *list);
long 	ft_atol(const char *string);
void 	afficher_list(t_node *list, int flag);
void afficher_list_classic(t_node *list);
void	afficher_list_null(t_node *list);
void	set_min(t_node **list);
int		max_bit(t_node *list);
int		get_max_bits(t_node *list);
int		swap(t_node **stack);
int 	sa(t_node **stacka, int print);
int 	sb(t_node **stackb, int print);
int 	ss(t_node **stacka, t_node **stackb);
int push(t_node **dst, t_node **src);
int	pb(t_node **stacka, t_node **stackb);
int	pa(t_node **stacka, t_node **stackb);

int rotate(t_node **stack);
int ra(t_node **stack, int flag);
int rb(t_node **stack, int flag);
int rrotate(t_node **stack);
int rra(t_node **stacka, int flag);
int rrb(t_node **stackb, int flag);
int rrr(t_node **stacka, t_node **stackb);
int rr(t_node **stacka, t_node **stackb);
int 	lst_lenght(t_node *list);
int		create_stackb(t_node *list, t_node **stackb);
int	radix_sort(t_node **stacka, t_node **stackb);
int max_index(t_node *stack);
int min_index(t_node *stack);
void sort(t_node **stacka, t_node **stackb);
int	is_sorted(t_node *stack);
void sort_stack_b(t_node **stacka, t_node **stackb, int maxbit, int current_bit);

int chunk_sort(t_node **stacka, t_node **stackb);
int get_chunk_count(int size);
t_node *find_in_chunk(t_node *stack, int chunk_start, int chunk_end);
int find_max_index(t_node *stack);

int chunked_sort(t_node **stacka, t_node **stackb);
int butterfly_sort(t_node **stacka,t_node **stackb);
int find_position(t_node *stack, int index_value);
int optimized_sort(t_node **stacka, t_node **stackb);
int cost_optimized_sort(t_node **stacka, t_node **stackb);


// Nouveaux prototypes pour l'algorithme d'insertion
void tiny_sort(t_node **list);
int insertion_sort(t_node **stack_a, t_node **stack_b);
int find_target_position(t_node *stack_a, int index_b);
void execute_rotations(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b);

int min_max_sort(t_node **stacka, t_node **stackb);

int get_cost(int pos, int size);
void move_to_top(t_node **stack, int pos, int size);

int optimized_chunk_sort(t_node **stacka, t_node **stackb);

int ultra_optimized_sort(t_node **stacka, t_node **stackb);
int radix_optimized_100(t_node **stacka, t_node **stackb);
int radix_optimized_500(t_node **stacka, t_node **stackb);
int min_max_100(t_node **stacka, t_node **stackb);

void sort_three(t_node **stacka);
void sort_five(t_node **stack, t_node **stackb);
t_node *find_min(t_node *stack);
void push_swap(t_node **stacka, t_node **stackb);
void sort_tree(t_node **stacka);
void position(t_node *stack);
t_node *find_cheapest(t_node *stack);