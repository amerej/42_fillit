/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:35:52 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/15 21:01:45 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_init_map(char *map)
{
	int		i;

	i = 0;
	while (i < (MAX_SIZE * MAX_SIZE))
	{
		*((map + (i % MAX_SIZE) * MAX_SIZE) + (i / MAX_SIZE)) = '.';
		i++;
	}
}

void	ft_print_map(char *map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(*((map + i * MAX_SIZE) + j));
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
