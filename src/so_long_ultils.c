/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ultils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:14:14 by algabrie          #+#    #+#             */
/*   Updated: 2021/11/29 20:44:37 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_lenmatrix(char **s)
{
	int		cont;

	cont = 0;
	while (s[cont])
		cont++;
	return (cont);
}

void	ft_write(char *str, int bool_newline)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	if (bool_newline)
		write(1, "\n", 1);
}

t_list	*ft_quest(t_list *pos, char content)
{
	while (pos->content != content && pos)
		pos = pos->next;
	return (pos);
}

void	ft_cheack(t_list *pos, t_vars *vars)
{
	if (pos == NULL)
	{
		ft_write("Error\nCheak the itens at map", 1);
		finish(vars);
	}
}
