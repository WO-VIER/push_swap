/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:40:48 by vwautier          #+#    #+#             */
/*   Updated: 2025/04/06 15:40:35 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				cheapest;
	int				data;
	int				index;
	int				position;
	int				med;
	int				price;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				**ft_split(char const *s, char c);
int					ft_isdigitsign(char *str);
void				free_split(char **split_argv);
int					error_handler(char **split_argv, t_node **list);
int					handle_duplicate(t_node *list, int nb);
int					handle_duplicate2(char **split_argv, t_node *list);
int					append_node(t_node **list, int nbr);
t_node				*last_node(t_node *list);
void				free_list(t_node **list);
int					lst_lenght(t_node *list);
void				set_min(t_node **list);
long				ft_atol(const char *string);
int					sa(t_node **stacka, int print);
int					ss(t_node **stack, t_node **stackb);
int					pb(t_node **stacka, t_node **stackb);
int					pa(t_node **stacka, t_node **stackb);
int					ra(t_node **stacka, int flag);
int					rb(t_node **stackb, int flag);
int					rr(t_node **stacka, t_node **stackb);
int					rra(t_node **stacka, int flag);
int					rrb(t_node **stackb, int flag);
int					rrr(t_node **stacka, t_node **stackb);
int					is_sorted(t_node *stack);
t_node				*find_min(t_node *stack);
void				position(t_node *stack);
t_node				*find_cheapest(t_node *stack);
void				final_rotate(t_node **stack, t_node *top_node, char c);
void				move(t_node **stacka, t_node **stackb);
void				node_routine(t_node *stacka, t_node *stackb);
t_node				*find_max(t_node *stack);
void				sort_three(t_node **stacka);
void				push_swap(t_node **stacka, t_node **stackb);
int					create_stack(t_node **stacka, char **argv, int argc);