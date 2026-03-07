/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:57:40 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 17:06:53 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **map, t_point *pos)
{
	if (map[pos->x][pos->y] == '1')
	{
		free(pos);
		return ;
	}
	if (map[pos->x][pos->y] == 'V')
	{
		free(pos);
		return ;
	}
	map[pos->x][pos->y] = 'V';
	flood_fill(map, get_point((pos->x + 1), pos->y));
	flood_fill(map, get_point((pos->x - 1), pos->y));
	flood_fill(map, get_point(pos->x, (pos->y + 1)));
	flood_fill(map, get_point(pos->x, (pos->y - 1)));
	free(pos);
}
