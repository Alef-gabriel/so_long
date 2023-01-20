/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:17:50 by marvin            #+#    #+#             */
/*   Updated: 2021/12/05 16:25:30 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 1200
# define HEIGHT 300
# include "../minilibx-linux/mlx.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

typedef struct s_list
{
	char			content;
	int				x;
	int				y;
	int				put_bool;
	struct s_list	*next;
}	t_list;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	char			**map;
	void			*background;
	struct s_list	*pos;
	int				coletable;
	int				steps;
	int				coll;
	int				row;
}	t_vars;

char	**matrix_in_map(char **argv);

t_list	*map_validator(char **matrix, t_list *pos, t_vars *v);

int		ft_lenmatrix(char **s);

int		ft_strlen(char *s);

int		mount_map(t_vars *vars);

int		return_put(t_list *pos, char content, t_vars *vars, int coletable);

int		finish(t_vars *vars);

int		static_image(t_vars *vars, t_list *pos);

char	*ft_itoa(int n);

void	ft_write(char *str, int bool_newline);

void	sprite(char content, t_vars *vars, t_list *obj, ...);

void	bonus(t_vars *vars);

t_list	*mont_enemy(t_list *pos, t_list *p);

t_list	*ft_quest(t_list *pos, char content);

void	ft_cheack(t_list *pos, t_vars *vars);

int		ft_coletable(t_list *pos);
#endif
