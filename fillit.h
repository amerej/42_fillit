/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 02:42:18 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/15 21:53:17 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

# define BUF_SIZE 20
# define MAX_TETRIS 26
# define MAX_SIZE 16
# define TRUE 1
# define FALSE 0

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tetri
{
	char			id;
	t_point			min;
	t_point			max;
	t_point			coord[4];
	t_point			pos;
	int				height;
	int				width;
	struct s_tetri	*next;
}					t_tetri;

t_tetri				*ft_new_tetri(void);
void				ft_push_back_tetri(t_tetri **begin_list, t_tetri *tetri);
int					ft_get_tetri(int fd, char *tetri);
void				ft_set_tetri(char *str_tetri, int nb_tetris,
					t_tetri **list);
void				ft_set_tetri_coord(char *str_tetri, t_tetri *tetri);
void				ft_init_map(char *map);
void				ft_print_map(char *map, int size);
void				ft_set_tetri_map(char *map, t_tetri *tetri);
int					ft_valid_pos(char *map, t_tetri *tetri);
void				ft_delete_tetri(char *map, t_tetri *tetri);
int					ft_depl_tetri(char *map, t_tetri *tetri, int size);
#endif
