/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_add_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:41:31 by algabrie          #+#    #+#             */
/*   Updated: 2021/12/05 16:16:01 by algabrie         ###   ########.fr       */
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

static t_list	*ft_clean_list(t_list *pos)
{
	t_list	*p;

	while (pos)
	{
		p = pos;
		pos = pos->next;
		free(p);
	}
	return (NULL);
}

static t_list	*add_in_struct(char s, t_list *pos, int x, int y)
{
	static t_list	*var = NULL;

	if (var == NULL)
	{
		var = ft_lstnew(s, x, y);
		pos = var;
	}
	else
	{
		var -> next = ft_lstnew(s, x, y);
		var = var -> next;
	}
	if (s != '1' && s != 'E' && s != 'P' && s != 'C' && s != '0')
		pos->content = 'f';
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
			p++;
		if (pos->content == 'C')
			c = 1;
		if (pos->content == 'E')
			e++;
		pos = pos->next;
	}
	if (p == 1 && c && e == 1)
		return (var);
	return (ft_clean_list(var));
}

t_list	*map_validator(char **matrix, t_list *pos, t_vars *v)
{
	int		cr;
	int		cc;

	cr = 0;
	v->row = ft_lenmatrix(matrix);
	v->coll = ft_strlen(matrix[0]);
	while (matrix[cr])
	{
		cc = 0;
		while (matrix[cr][cc] && matrix[cr][cc] != '\n')
		{
			if (((cr == 0 || cr == v->row - 1) && matrix[cr][cc] != '1')
				|| (pos && pos->content == 'f'))
				return (ft_clean_list(pos));
			if (cr != 0 && cr != v->row - 1 && !(cc == v->coll - 2 || cc == 0))
				pos = add_in_struct(matrix[cr][cc], pos, cr, cc);
			cc++;
		}
		if (cc != v->coll - 1 || (pos && pos->content == 'f')
			|| (matrix[cr][0] != '1' || matrix[cr][v->coll - 2] != '1'))
			return (ft_clean_list(pos));
		cr++;
	}
	return (verify_elements_in_struct(pos));
}
