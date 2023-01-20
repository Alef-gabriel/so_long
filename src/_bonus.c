/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:45:33 by algabrie          #+#    #+#             */
/*   Updated: 2021/12/05 16:30:45 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bonus(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->steps);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFE6500, str);
	free(str);
}

t_list	*mont_enemy(t_list *pos, t_list *p)
{
	t_list	*var;

	var = NULL;
	while (p != pos && p)
	{
		if (p->content == '0')
			var = p;
		p = p->next;
	}
	if (var)
		var->content = 'N';
	return (p->next);
}

int	ft_coletable(t_list *pos)
{
	int	coletable;

	coletable = 0;
	while (pos)
	{
		if (pos->put_bool && pos->content == 'C')
			coletable++;
		pos = pos->next;
	}
	return (coletable);
}
