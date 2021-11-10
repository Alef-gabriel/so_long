/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:17:50 by marvin            #+#    #+#             */
/*   Updated: 2021/11/10 08:44:44 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 1200
# define HEIGHT 300
# include "mlx.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

typedef struct	s_list
{
	char	content;
	int		x;
	int		y;
	int		height;
	int		width;
	struct s_list	*next;
}	t_list;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
    char		**map;
	struct s_list	*pos;
}   t_vars;

char	**matrix_in_map(void);

t_list	*map_validator(char **matrix, t_list *pos);

int		ft_lenmatrix(char **s);

int		ft_strlen(char *s);

void	mount_map(t_vars vars, int map_colls, int map_rows);
#endif
