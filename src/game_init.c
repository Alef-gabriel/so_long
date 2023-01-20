/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:45:51 by algabrie          #+#    #+#             */
/*   Updated: 2021/12/05 16:26:51 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	game_move(t_list *p, int bool_move, char con, t_vars *var)
{
	if (bool_move)
	{
		if (con == 's' && !(p->x + 20 >= HEIGHT - (HEIGHT / var->row) - 34))
		{
			p->x = p->x + 20;
			return (1);
		}
		if (con == 'w' && !(p->x - 20 <= (HEIGHT / var->row) - 10))
		{
			p->x = p->x - 20;
			return (1);
		}
		if (con == 'd' && !(p->y + 20 >= WIDTH - (WIDTH / var->coll)))
		{
			p->y = p->y + 20;
			return (1);
		}
		if (con == 'a' && !(p->y - 20 <= (WIDTH / var->coll)))
		{
			p->y = p->y - 20;
			return (1);
		}
		return (0);
	}
	return (0);
}

static int	moviment_valid(t_list *pos, char con, t_vars *vars, int c)
{
	t_list	*p;
	int		bool_move;

	p = pos;
	bool_move = 1;
	p = ft_quest(pos, 'P');
	while (pos)
	{
		if (pos->content == '1' || pos->content == 'C' || pos->content == 'E'
			|| pos->content == 'N')
		{
			if (((con == 's' && p->x + 20 > pos->x - 30 && p->x <= pos->x - 30)
					|| (con == 'w' && p->x - 30 < pos->x + 30
						&& p->x >= pos->x + 30)) && (p->y < pos->y + 30
					&& p->y >= pos->y - 30))
				bool_move = return_put(pos, pos->content, vars, c);
			if (((con == 'd' && p->y + 20 > pos->y - 30 && p->y <= pos->y - 30)
					|| (con == 'a' && p->y - 20 <= pos->y + 30
						&& p->y >= pos->y + 30)) && (p->x >= pos->x - 30
					&& p->x <= pos->x + 30))
				bool_move = return_put(pos, pos->content, vars, c);
		}
		pos = pos->next;
	}
	return (game_move(p, bool_move, con, vars));
}

static int	key_hook(int keycode, t_vars *vars)
{
	char		*str;
	int			i;

	i = ft_coletable(vars->pos);
	if (keycode == 'w')
		vars->steps += moviment_valid(vars->pos, 'w', vars, i);
	if (keycode == 'd')
		vars->steps += moviment_valid(vars->pos, 'd', vars, i);
	if (keycode == 's')
		vars->steps += moviment_valid(vars->pos, 's', vars, i);
	if (keycode == 'a')
		vars->steps += moviment_valid(vars->pos, 'a', vars, i);
	if (keycode == 65307)
		finish (vars);
	static_image(vars, vars->pos);
	str = ft_itoa(vars->steps);
	ft_write("steps : ", 0);
	ft_write(str, 1);
	free(str);
	bonus(vars);
	return (keycode);
}

static int	render_next_frame(t_vars *vars)
{
	sprite('P', vars, vars->pos, "image/1.xpm", "image/2.xpm", "image/3.xpm");
	sprite('E', vars, vars->pos, "image/p1.xpm", "image/p2.xpm",
		"image/p3.xpm");
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		img_width;
	int		img_height;

	if (argc < 2)
		return (0);
	vars.map = matrix_in_map(argv);
	vars.pos = NULL;
	vars.mlx = NULL;
	vars.pos = map_validator(vars.map, vars.pos, &vars);
	ft_cheack(vars.pos, &vars);
	vars.mlx = mlx_init();
	vars.background = mlx_xpm_file_to_image(vars.mlx, "image/Space01.xpm",
			&img_width, &img_height);
	vars.win = mlx_new_window(vars.mlx, img_width, img_height, "so_long");
	mlx_put_image_to_window(vars.mlx, vars.win, vars.background, 0, 0);
	mlx_hook(vars.win, 9, 1L << 21, mount_map, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_hook(vars.win, 02, (1L << 0), key_hook, &vars);
	mlx_hook(vars.win, 33, 1L << 2, finish, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
