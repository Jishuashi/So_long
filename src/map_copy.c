/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:23:19 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/09 16:01:26 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(char **map, size_t row)
{
	char	**copy;
	size_t	i;

	copy = (char **)malloc(sizeof(char *) * (row + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < row)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			ft_free_all(copy);
			ft_putstr_fd("Error\nThe allocation failed.\n", 2);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
