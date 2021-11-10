/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mount_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:41:20 by algabrie          #+#    #+#             */
/*   Updated: 2021/11/10 08:45:58 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mount_map(t_vars vars, int map_colls, int map_rows)
{
	int		img_widthg;
	int		img_heightg;
	void	*imgg;

	while (vars.pos)
	{
		vars.pos->height = vars.pos->x * (HEIGHT/ map_rows);
		vars.pos->width = vars.pos->y * (WIDTH / map_colls);
		/*
		if (vars.pos->content == 'P')
			imgg = mlx_xpm_file_to_image(vars.mlx, "image/1.xpm", &img_widthg, &img_heightg);
		if (vars.pos->content == 'C')
			imgg = mlx_xpm_file_to_image(vars.mlx, "image/cplayer.xpm", &img_widthg, &img_heightg);
		if (vars.pos->content == 'E')
			imgg = mlx_xpm_file_to_image(vars.mlx, "image/p1.xpm", &img_widthg, &img_heightg);
		if (vars.pos->content == '1')
			imgg = mlx_xpm_file_to_image(vars.mlx, "image/wall.xpm", &img_widthg, &img_heightg);
		mlx_put_image_to_window(vars.mlx, vars.win, imgg, vars.pos->y, vars.pos->x);
		*/
		vars.pos = vars.pos->next;
	}
}