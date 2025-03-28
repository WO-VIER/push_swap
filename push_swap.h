/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:40:48 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/28 22:33:57 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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

int	ft_isdigit(int c);
int	ft_isdigitsign(char *str);
int	create_list(char **argv, t_node **list);
void	free_split(char **split_argv);
int	error_handler(char **split_argv, t_node **list);
int handle_duplicate(char **split_argv, t_node *list);
t_node *create_node(long long data);
int append_node(t_node **list, int nbr);
t_node *last_node(t_node *list);
int add_node(t_node **list, t_node *node);
void free_list(t_node **list);
int lst_lenght(t_node *list);
void	set_min(t_node **list);
long ft_atol(const char *string);
int swap(t_node **stack);
int sa(t_node **stacka, int print);
int sb(t_node **stackb, int print);
int ss(t_node **stack, t_node **stackb);
int push(t_node **dst, t_node **src);
int	pb(t_node **stacka, t_node **stackb);
int	pa(t_node **stacka, t_node **stackb);
int rotate(t_node **stack);
int ra(t_node **stacka, int flag);
int rb(t_node **stackb, int flag);
int rrotate(t_node **stack);
int rr(t_node **stacka, t_node **stackb);
int rra(t_node **stacka,int flag);
int rrb(t_node **stackb,int flag);
int rrr(t_node **stacka, t_node **stackb);
int	is_sorted(t_node *stack);
t_node *find_min(t_node *stack);
void target(t_node *stacka, t_node *stackb);
void position(t_node *stack);
void price(t_node *stacka, t_node *stackb);
void cheapest(t_node *stackb);
t_node *find_cheapest(t_node *stack);
void rotate_top(t_node **stacka, t_node **stackb, t_node *cheapest);
void rrotate_top(t_node **stacka, t_node **stackb, t_node *cheapest);
void final_rotate(t_node **stack, t_node *top_node, char c);
void move(t_node **stacka, t_node **stackb);
void node_routine(t_node *stacka, t_node *stackb);
t_node *find_max(t_node *stack);
void sort_three(t_node **stacka);
void sort_five(t_node **stacka, t_node **stackb);
void push_swap(t_node **stacka, t_node **stackb);
int create_stack(t_node **stacka, char **argv, int argc);