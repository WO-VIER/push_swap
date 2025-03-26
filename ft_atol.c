/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:59:55 by vwautier          #+#    #+#             */
/*   Updated: 2025/02/17 15:06:02 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ft_atol(const char *string)
{
	int		csigne;
	long	number;
	int		i;

	i = 0;
	number = 0;
	csigne = 1;
	while ((string[i] == ' ' || (string[i] >= '\t' && string[i] <= '\r')))
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i++] == '-')
			csigne = -1;
	}
	while (string[i] >= '0' && string[i] <= '9')
		number = (number * 10) + (string[i++] - '0');
	return (number * csigne);
}
/*
int main (int argc, char **argv)
{
	long number;

	
	if(argc == 1)
		return(1);
	number = ft_atol(argv[1]);
	printf("Atol : %ld", number); //%ld
	return(0);
}*/