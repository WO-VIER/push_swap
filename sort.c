/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malafont <malafont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:00:00 by malafont          #+#    #+#             */
/*   Updated: 2025/02/13 11:00:00 by malafont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_numbers(t_stacks *data)
{
	if (data->stack_a[2] != 2)
	{
		if (data->stack_a[0] == 2)
			rotate(data->stack_a, data->a_size, "rotate", "a");
		else
			rotate(data->stack_a, data->a_size, "reverse rotate", "a");
	}
	if (data->stack_a[0] > data->stack_a[1])
		swap("sa", data->stack_a, data->a_size);
}

void	sort_four_or_five(t_stacks *data)
{
	while (data->b_size <= 1)
	{
		if (data->stack_a[0] == 0 || data->stack_a[0] == 1)
			push("pb", data);
		else
			rotate(data->stack_a, data->a_size, "rotate", "a");
	}
	if (data->stack_b[0] == 0)
		swap("sb", data->stack_b, data->b_size);
	if (data->stack_a[2] != 4)
	{
		if (data->stack_a[0] == 4)
			rotate(data->stack_a, data->a_size, "rotate", "a");
		else
			rotate(data->stack_a, data->a_size, "reverse rotate", "a");
	}
	if (data->stack_a[0] > data->stack_a[1])
		swap("sa", data->stack_a, data->a_size);
	push("pa", data);
	push("pa", data);
}

int	is_stack_sorted(t_stacks *data)
{
	int	i;

	i = 0;
	while (i < data->a_size - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_stack_b(t_stacks *data, int size,
							int bit_pos_max, int current_bit)
{
	while (size-- && current_bit <= bit_pos_max && !is_stack_sorted(data))
	{
		if (((data->stack_b[0] >> current_bit) & 1) == 0)
			rotate(data->stack_b, data->b_size, "rotate", "b");
		else
			push("pa", data);
	}
	if (is_stack_sorted(data))
		while (data->b_size != 0)
			push("pa", data);
}
/*
** Implémentation du tri radix pour les grandes séquences
** Trie les nombres bit par bit en commençant par le bit de poids faible
** Complexité : O(n * log(max_num))
*/

void	sort_large_stack(t_stacks *data)
{
	int	current_bit;
	int	bit_pos_max;
	int	size;

	bit_pos_max = 0;
	size = data->a_size;
	while (size > 1 && ++bit_pos_max)
		size /= 2;
	current_bit = -1;
	while (++current_bit <= bit_pos_max)
	{
		size = data->a_size;
		while (size-- && !is_stack_sorted(data))
		{
			if (((data->stack_a[0] >> current_bit) & 1) == 0)
				push("pb", data);
			else
				rotate(data->stack_a, data->a_size, "rotate", "a");
		}
		sort_stack_b(data, data->b_size, bit_pos_max, current_bit + 1);
	}
	while (data->b_size != 0)
		push("pa", data);
}
