/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:53:32 by vwautier          #+#    #+#             */
/*   Updated: 2025/04/06 15:39:02 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_list(char **argv, t_node **list)
{
	long	number;

	while (*argv)
	{
		if (!(ft_isdigitsign(*argv)))
			return (1);
		number = ft_atol(*argv);
		if (number > 2147483647 || number < -2147483648)
			return (1);
		if (handle_duplicate(*list, (int)number))
			return (1);
		if (append_node(list, (int)number))
			return (1);
		argv++;
	}
	return (0);
}

void	free_list(t_node **list)
{
	t_node	*currentnode;
	t_node	*tmp;

	if (!list)
		return ;
	currentnode = *list;
	while (currentnode)
	{
		tmp = currentnode->next;
		free(currentnode);
		currentnode = tmp;
	}
	*list = NULL;
}

int	create_stack(t_node **stacka, char **argv, int argc)
{
	char	**split_argv;

	split_argv = NULL;
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv || create_list(split_argv, stacka))
			return (error_handler(split_argv, stacka));
		free_split(split_argv);
	}
	else
	{
		if (create_list(++argv, stacka))
			return (error_handler(NULL, stacka));
	}
	return (0);
}

void	set_min(t_node **list)
{
	t_node	*currentnodei;
	t_node	*currentnodej;
	int		index;

	if (!list || !*list)
		return ;
	currentnodei = *list;
	while (currentnodei)
	{
		index = 0;
		currentnodej = *list;
		while (currentnodej)
		{
			if (currentnodej->data < currentnodei->data)
				index++;
			currentnodej = currentnodej->next;
		}
		currentnodei->index = index;
		currentnodei = currentnodei->next;
	}
}

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
