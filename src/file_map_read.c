/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:42:37 by algabrie          #+#    #+#             */
/*   Updated: 2021/11/06 20:42:38 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**dinamic_matrix(char *line, char **matrix)
{
	char	**new_matrix;
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	new_matrix = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (matrix[i])
	{
		new_matrix[i] = matrix[i];
		i++;
	}
	if (matrix[0])
		free(matrix);
	new_matrix[i++] = line;
	new_matrix[i++] = 0;
	return (new_matrix);
}

char	**matrix_in_map(void)
{
	int		fd;
	char	**matrix;
	char	*line;

	fd = open("map/map.ber", O_RDONLY);
	line = get_next_line(fd);
	matrix[0] = NULL;
	while (line)
	{
		matrix = dinamic_matrix(line, matrix);
		line = get_next_line(fd);
	}
	close(fd);
	return (matrix);
}
