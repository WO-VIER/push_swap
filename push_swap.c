/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:39:26 by vwautier          #+#    #+#             */
/*   Updated: 2025/04/06 21:26:41 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stacka;
	t_node	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	create_stack(&stacka, argv, argc);
	if (!is_sorted(stacka))
	{
		set_min(&stacka);
		if (lst_lenght(stacka) == 2)
			sa(&stacka, 1);
		else if (lst_lenght(stacka) == 3)
			sort_three(&stacka);
		else
			push_swap(&stacka, &stackb);
	}
	free_list(&stacka);
	free_list(&stackb);
	return (0);
}
