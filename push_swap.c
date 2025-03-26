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
		// Réduire la gestion faire
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
		free_list(&list);
	}
	// acceder aux index de la liste
	// printf("Node data : %d\n", list->data);
	// printf("Node data : %d\n", list->next->data);
	// printf("Node data : %d\n", list->next->next->data);
	//set_min(&list);
	//insertion_sort(&list, &stackb);
	//afficher_list_null(list);
	//sort(&list, &stackb);
	//radix_sort(&list, &stackb);
	//butterfly_sort(&list,&stackb);
	//optimized_sort(&list, &stackb);
	//cost_optimized_sort(&list, &stackb);
	//sort(&list, &stackb);
	//(&list, &stackb);
	//min_max_100_improved(&list, &stackb);
	//algo(&list, &stackb);
	printf("Lst_lenght : %d\n",lst_lenght(list));
	afficher_list_null(stackb);
	afficher_list_null(list);
	//printf("Sizeof %d\n", sizeof(t_node));
	//printf("Lst_lenght : %d",lst_lenght(list));
	//chunk_sort(&list, &stackb);
	//afficher_list_null(list);
	//int i = is_sorted(list);
	//printf("Is sorted : %d\n", i);
	/*
	push(&stackb,&list);
	push(&stackb,&list);
	push(&stackb,&list);

	pb(&list, &stackb);
	pa(&list, &stackb);
	
	afficher_list_null(list);
	rra(&list,1);
	rra(&list,1);
	*/

	//rra(&list,1);
	//afficher_list_null(list);
	//rra(&list, 1);
	//radix_sort(&list, &stackb);
	//afficher_list(list,0);
	//afficher_list_classic(list);
	//afficher_list_null(list);
	//afficher_list_null(stackb);
	/*	
	find_min(&list);
	afficher_list(list,1);
	
	pb(&list, &stackb);
	afficher_list(list,1);
	afficher_list(stackb,0);
	pa(&list, &stackb);
	afficher_list(list,1);
	afficher_list(stackb,0);
	rra(&list,1);
	afficher_list(list,1);
	ra(&list,1);
	afficher_list(list,1);
	sa(&list,1);
	afficher_list(list,1);
	pb(&list, &stackb);
	afficher_list(list,1);
	afficher_list(stackb,0);
	//printf("Node 0 %d", list->data);
	*/



	return (0);
}
