/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:39:26 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/28 21:23:28 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"


/*
** Node 0 Bottom et Top last node 
** Implementation qui demande de tout les temps parcourir la liste pour push vers b
**
*/

// Dois différencier "1 3 4 5 " et 1 2 3 4 5 entre cote c'est une string est sans c'est 5 arg
int	main(int argc, char **argv)
{
	char **split_argv;
	t_node *stacka;
	t_node *stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2) //Format Nécessitant split "1 2 3 5" un 2 arg ./push_swap et la chainne
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv || create_list(split_argv, &stacka))
			return (error_handler(split_argv, &stacka));
		if (handle_duplicate(split_argv, NULL))
			return (error_handler(split_argv, &stacka));
		free_split(split_argv);
	}
	else //Format 3 5 6 7 
	{
		if (create_list(++argv, &stacka))
			return (error_handler(NULL, &stacka));
		if (handle_duplicate(NULL, stacka))
			return (error_handler(NULL, &stacka));
	}

	if(!is_sorted(stacka))
	{
		set_min(&stacka);
		if(lst_lenght(stacka) == 2)
			sa(&stacka,1);
		else if(lst_lenght(stacka) == 3)
			sort_three(&stacka);
		else
			push_swap(&stacka, &stackb);
		/*
		if(is_sorted(stacka))
			write(1,"OK\n",3);
		else
			write(1,"KO\n",3);
		*/
		free_list(&stacka);
		/*
		if (stackb)
			free_list(&stackb);
		else
			write(1,"Pas b\n",6);
		*/
	}
	
	return (0);
}
