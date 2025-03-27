/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:39:26 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/26 22:29:16 by vwautier         ###   ########.fr       */
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
	t_node *list;
	t_node *stackb;

	list = NULL;
	stackb = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (error_handler(NULL, NULL));
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv || create_list(split_argv, &list))
			return (error_handler(split_argv, list));
		if (handle_duplicate(split_argv, NULL))
			return (error_handler(split_argv, list));
		free_split(split_argv);
	}
	else
	{
		if (create_list(++argv, &list))
			return (error_handler(NULL, list));
		if (handle_duplicate(NULL, list))
			return (error_handler(NULL, list));
		//create_stackb(list, &stackb);
	}

	if(!is_sorted(list))
	{
		set_min(&list);
		if(lst_lenght(list) == 2)
			sa(&list,1);
		else if(lst_lenght(list) == 3)
			sort_tree(&list);
		else
			algo(&list, &stackb);
		afficher_list_null(list);
		free_list(&list);
	}
	
	return (0);
}
