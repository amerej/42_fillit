/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:10:11 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/15 21:19:41 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_new_tetri(void)
{
	t_tetri		*tetri;

	tetri = (t_tetri *)malloc(sizeof(*tetri));
	if (tetri)
		tetri->next = NULL;
	return (tetri);
}

void	ft_push_back_tetri(t_tetri **begin_list, t_tetri *tetri)
{
	t_tetri		*list;

	list = *begin_list;
	if (!list)
	{
		list = tetri;
		*begin_list = list;
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = tetri;
	}
}

int		ft_get_tetri(int fd, char *tetri)
{
	int		count;
	char	tmp[1];

	count = read(fd, tetri, BUF_SIZE);
	tetri[count] = '\0';
	read(fd, tmp, 1);
	return (count);
}

void	ft_set_tetri(char *str_tetri, int nb_tetris, t_tetri **list)
{
	int			i;
	int			j;
	t_tetri		*tetri;

	i = 0;
	j = 0;
	tetri = ft_new_tetri();
	tetri->id = 'A' + nb_tetris;
	ft_set_tetri_coord(str_tetri, tetri);
	while (str_tetri[i])
	{
		if (str_tetri[i] == '#')
		{
			tetri->coord[j].x = (i % 5) - tetri->min.x;
			tetri->coord[j].y = (i / 5) - tetri->min.y;
			j++;
		}
		i++;
	}
	tetri->height = (tetri->max.y - tetri->min.y) + 1;
	tetri->width = (tetri->max.x - tetri->min.x) + 1;
	ft_push_back_tetri(list, tetri);
}

void	ft_set_tetri_coord(char *str_tetri, t_tetri *tetri)
{
	int	i;

	tetri->min.x = 3;
	tetri->min.y = 3;
	tetri->max.x = 0;
	tetri->max.y = 0;
	i = 0;
	while (str_tetri[i])
	{
		if (str_tetri[i] == '#')
		{
			if ((i % 5) < tetri->min.x)
				tetri->min.x = i % 5;
			if ((i / 5) < tetri->min.y)
				tetri->min.y = i / 5;
			if ((i % 5) > tetri->max.x)
				tetri->max.x = i % 5;
			if ((i / 5) > tetri->max.y)
				tetri->max.y = i / 5;
		}
		i++;
	}
}
