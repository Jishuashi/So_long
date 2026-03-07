/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:24:22 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 13:49:40 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	check_walls(char **map, size_t row, size_t col);

char	checker(char **map, size_t row, size_t col)
{
	if (!check_walls(map, row, col))
		return (1);
	return (0);
}

static	int	check_walls(char **map, size_t row, size_t col)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((i == 0 || i == (row - 1)) && map[i][j] != '1'
			&& map[i][j] != '\n' && map[i][j] != '\0')
				return (0);
			if ((j == 0 || j == (col - 1)) && map[i][j] != '1'
			&& map[i][j] != '\n' && map[i][j] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
