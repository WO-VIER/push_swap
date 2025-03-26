/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:53:32 by vwautier          #+#    #+#             */
/*   Updated: 2025/03/26 22:22:10 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>
#include "push_swap.h"

int	ft_isdigitsign(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}


int	create_list(char **argv, t_node **list)
{
	int i;
	long 	number;


	while (*argv)
	{
		if (!(ft_isdigitsign(*argv)))
			return (1);
		number = ft_atol(*argv); // probleme signe
		//printf("Number : %ld\n", number);
		if(number > 2147483647 || number < -2147483648)
			return(1);
		if(append_node(list, (int)number))
			return (1);
		argv++;
	}
	return (0);
}
/*
int	create_stackb(t_node *list, t_node **stackb)
{
	int lenght;
	t_node *currentnode;

	if(!list)
		return (1);
	lenght = lst_lenght(list);
	while(lenght > 0)
	{
		currentnode = create_node(0);
		if (!currentnode)
			return (1);
		if (!*stackb)
		{
			*stackb = currentnode;
		}
		else
		{
			if(add_node(*stackb, currentnode))
				return (1);
		}
		lenght--;
	}
	
	//printf("Lst lenghtb : %d\n", lst_lenght(*stackb));
	return(0);
}
*/
void	free_split(char **split_argv)
{
	int	i;

	i = 0;
	while (split_argv[i])
	{
		free(split_argv[i]);
		split_argv[i] = NULL;
		i++;
	}
	free(split_argv);
	split_argv = NULL;
}

int	error_handler(char **split_argv, t_node *list)
{
	//printf("Jse suis la ");
	//printf("\nList first node content -> %d",&list->data);
	if (split_argv)
		free_split(split_argv);
	if (list)
		free_list(&list);
	write(1, "Error\n", 6);
	return (1);
}

int handle_duplicate(char **split_argv, t_node *list)
{
	int i;
	int j;
	
	t_node *currentnodej;
	t_node *basei;

	currentnodej = NULL;
	basei = NULL;
	i = 0;
	// Alerte verifier les signes aussi 
	/*atoi les chaines et parcourir toute la chaine */
	if(split_argv && split_argv[i])
	{
		//printf("Atoi 3 : %d et 5 : %d \n",ft_atoi(split_argv[2]), ft_atoi(split_argv[4]));
		while(split_argv[i])
		{
			j = 0;
			while (split_argv[j])
			{
				if((ft_atol(split_argv[i]) == ft_atol(split_argv[j])) && i != j)
					return (1);
				j++;
			}
			i++;
		}
	}
	else if(list)
	{
		basei = list;
		while(basei)
		{
			currentnodej = basei->next;
			while(currentnodej)
			{
				if(basei->data == currentnodej->data)
					return (1);
				currentnodej = currentnodej->next;
			}
			basei = basei->next;
		}
	}
	//printf("Ok");
	return (0);
}