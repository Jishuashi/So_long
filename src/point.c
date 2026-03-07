/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:08:47 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 17:06:41 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

t_point	*get_point(int x, int y)
{
	t_point	*res;

	res = (t_point *)malloc(sizeof(t_point));
	if (!res)
		exit(1);
	res = set_point(res, x, y);
	return (res);
}

t_point	*set_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
	return (point);
}
