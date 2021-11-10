/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_add_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:41:31 by algabrie          #+#    #+#             */
/*   Updated: 2021/11/09 13:37:38 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*ft_lstnew(char content, int x, int y)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	p->content = content;
	p->x = x;
	p->y = y;
	p->next = NULL;
	return (p);
}

static t_list	*add_in_struct(char s, t_list *pos, int x, int y)
{
	static t_list	*var = NULL;

	if (s != '1'&& s != 'E' && s != 'P' && s != 'C' && s != '0')
		return (NULL); //creat function to delete the struct
	if (s != '0')
	{
		if (var == NULL)
		{
			var = ft_lstnew(s, x, y);
			return (var);
		}
		var -> next = ft_lstnew(s, x, y);
		var = var -> next;
	}
	return (pos);
}

static t_list	*verify_elements_in_struct(t_list *pos)
{
	int		e;
	int		c;
	int		p;
	t_list	*var;

	var = pos;
	e = 0;
	c = 0;
	p = 0;
	while (pos)
	{
		if (pos->content == 'P')
			p = 1;
		if (pos->content == 'C')
			c = 1;
		if (pos->content == 'E')
			e = 1;
		pos = pos->next;
	}
	if (p && c && e)
		return(var);
	return (NULL);
}

t_list	*map_validator(char **matrix, t_list *pos)
{
	#define MAX_ROWS ft_lenmatrix(matrix)
	#define MAX_COLUMNS ft_strlen(matrix[0])
	int		crows;
	int		ccols;

	crows = 0;
	while (matrix[++crows])
	{
		ccols = 0;
		while (matrix[crows][ccols] && matrix[crows][ccols] != '\n')
		{
			if ((crows == 0 || crows == MAX_ROWS - 1) && matrix[crows][ccols] != '1')
				return (NULL);
			if (crows != 0 && crows != MAX_ROWS - 1)
			{
				pos = add_in_struct(matrix[crows][ccols], pos, crows, ccols);
				if (pos == NULL || ((ccols == MAX_COLUMNS -2
						|| ccols == 0)&& matrix[crows][ccols] != '1'))
					return (NULL);
			}
			ccols++;
		}
		if (ccols != MAX_COLUMNS - 1)
			return (NULL);
	}
	return (verify_elements_in_struct(pos));
}
