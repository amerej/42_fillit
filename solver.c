/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:15:22 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/15 20:59:24 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid_pos(char *map, t_tetri *tetri)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (*((map + ((tetri->coord[i].y + tetri->pos.y) * MAX_SIZE))
			+ (tetri->coord[i].x + tetri->pos.x)) != '.')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_set_tetri_map(char *map, t_tetri *tetri)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		*((map + ((tetri->coord[i].y + tetri->pos.y) * MAX_SIZE))
		+ (tetri->coord[i].x + tetri->pos.x)) = tetri->id;
		i++;
	}
}

void	ft_delete_tetri(char *map, t_tetri *tetri)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		*((map + ((tetri->coord[i].y + tetri->pos.y) * MAX_SIZE))
		+ (tetri->coord[i].x + tetri->pos.x)) = '.';
		i++;
	}
}

int		ft_depl_tetri(char *map, t_tetri *tetri, int size)
{
	if (tetri == NULL)
		return (TRUE);

	tetri->pos.y = 0;
	while (tetri->pos.y <= size - tetri->height)
	{
		tetri->pos.x = 0;
		while (tetri->pos.x <= size - tetri->width)
		{
			if (ft_valid_pos((char *)map, tetri))
			{
				ft_set_tetri_map((char *)map, tetri);
				if (ft_depl_tetri((char *)map, tetri->next, size))
					return (TRUE);
				ft_delete_tetri((char *)map, tetri);
			}
			tetri->pos.x++;
		}
		tetri->pos.y++;
	}
	return (FALSE);
}
