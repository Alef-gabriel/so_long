/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mount_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:41:20 by algabrie          #+#    #+#             */
/*   Updated: 2021/12/05 14:58:09 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	callc(t_list *pos, int map_rows, int map_colls)
{
	int		i;
	t_list	*p;

	i = 0;
	if (HEIGHT / map_rows < 34 || WIDTH / map_colls < 34)
	{
		ft_write("Erro\nInconpatble line nuber or columns nuber", 1);
		return (0);
	}
	p = pos;
	while (pos)
	{
		if (pos->content == 'C' && pos->y != 1)
		{
			i++;
			p = mont_enemy(pos, p);
		}
		pos->x = pos->x * (HEIGHT / map_rows);
		pos->y = pos->y * (WIDTH / map_colls);
		pos->put_bool = 1;
		pos = pos->next;
	}
	return (i);
}

int	mount_map(t_vars *vars)
{
	static int	first = 1;
	int			i;

	if (first == 1)
	{
		i = callc(vars->pos, vars->row, vars->coll - 2);
		if (!(i))
			finish(vars);
		vars->coletable = i;
		first = 0;
	}
	static_image(vars, vars->pos);
	vars->steps = 0;
	bonus(vars);
	return (0);
}
