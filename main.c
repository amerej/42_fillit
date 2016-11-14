/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 10:08:08 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/12 16:37:32 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	char		nb_tetris;
	int			fd;
	char		size;
	char		str_tetri[BUF_SIZE + 1];
	char		map[MAX_SIZE * MAX_SIZE];
	t_tetri		*tetri;

	nb_tetris = 0;
	size = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			while (ft_get_tetri(fd, str_tetri))
			{
				ft_set_tetri(str_tetri, nb_tetris, &tetri);
				nb_tetris++;
			}
			close(fd);
			size = (tetri->height > tetri->width) ? tetri->height : tetri->width;
			ft_init_map((char *)map);
			while (!ft_depl_tetri((char *)map, tetri, size))
			{
				ft_init_map((char *)map);
				size++;
			}
		}
		ft_print_map((char *)map, size);
	}
	return (FALSE);
}
