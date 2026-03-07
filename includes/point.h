/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:07:13 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 17:00:00 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "../libft/libft.h"


typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

t_point	*get_point(int x, int y);
t_point	*set_point(t_point *point, int x, int y);

#endif