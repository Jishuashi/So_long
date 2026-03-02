/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:05:39 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/02 15:30:06 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_tab(size_t row, size_t col)
{
	size_t	i;
	char	**res;

	res = (char **)malloc(sizeof(char *) * col);
	if (!res)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	while (i < col)
	{
		res[i] = (char *)malloc(sizeof(char) * row);
		if (!res[i])
		{
			ft_free_all(res);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (res);
}

void	ft_free_all(char **to_free)
{
	while (*to_free)
	{
		free(*to_free);
		to_free++;
	}
	free(to_free);
}
