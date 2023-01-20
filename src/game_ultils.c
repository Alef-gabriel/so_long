/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ultils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:46:00 by algabrie          #+#    #+#             */
/*   Updated: 2021/11/30 21:46:01 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	return_put(t_list *pos, char content, t_vars *vars, int coletable)
{
	if (content == 'N')
	{
		ft_write("!!!!You Lost!!!!", 1);
		finish (vars);
	}
	if (content == 'C')
	{
		pos->put_bool = 0;
		return (1);
	}
	if (content == 'E' && (vars->coletable - coletable) == vars->coletable)
	{
		ft_write("!!!!You Win!!!!", 1);
		finish (vars);
	}
	return (0);
}

int	finish(t_vars *vars)
{
	int		cont;
	t_list	*p;

	cont = 0;
	while (vars->map[cont])
	{
		free(vars->map[cont]);
		cont++;
	}
	free(vars->map);
	vars->map = NULL;
	while (vars->pos)
	{
		p = vars->pos;
		vars->pos = vars->pos->next;
		free(p);
	}
	if (vars->mlx)
	{
		mlx_destroy_image(vars->mlx, vars->background);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit (0);
}

static int	put_image(t_vars *vars, t_list *pos)
{
	int		iw;
	int		ih;
	void	*img;
	int		coletable;

	coletable = 0;
	if (pos->content == '1')
		img = mlx_xpm_file_to_image(vars->mlx, "image/w.xpm", &iw, &ih);
	if (pos->content == 'C')
	{
		img = mlx_xpm_file_to_image(vars->mlx, "image/c.xpm", &iw, &ih);
		coletable++;
	}
	if (pos->content == 'N')
		img = mlx_xpm_file_to_image(vars->mlx, "image/e5.xpm", &iw, &ih);
	mlx_put_image_to_window(vars->mlx, vars->win, img, pos->y, pos->x);
	mlx_destroy_image(vars->mlx, img);
	return (coletable);
}

int	static_image(t_vars *vars, t_list *pos)
{
	int	coletable;

	coletable = 0;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->background, 0, 0);
	while (pos)
	{
		if (pos->put_bool && (pos->content == '1' || pos->content == 'C'
				|| pos->content == 'N'))
			coletable += put_image(vars, pos);
		pos = pos->next;
	}
	return (coletable);
}

void	sprite(char content, t_vars *vars, t_list *obj, ...)
{
	int		iwg;
	int		ihg;
	void	*img;
	va_list	ap;
	int		cont_img;

	va_start(ap, obj);
	cont_img = 0;
	obj = ft_quest(obj, content);
	while (cont_img < 3)
	{
		img = mlx_xpm_file_to_image(vars->mlx, va_arg(ap, char *), &iwg,
				&ihg);
		mlx_put_image_to_window(vars->mlx, vars->win, img, obj->y, obj->x);
		mlx_destroy_image(vars->mlx, img);
		va_end(ap);
		cont_img++;
	}
}
