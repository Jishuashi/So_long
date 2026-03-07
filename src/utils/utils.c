/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:09:41 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 20:39:29 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_free_all(char **to_free)
{
	size_t	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

char	**create_tab(size_t row, size_t col)
{
	size_t	i;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (row + 1));
	if (!res)
	{
		ft_putstr_fd("Error\nThe allocation failed.\n", 2);
		exit(1);
	}
	i = 0;
	while (i < row)
	{
		res[i] = (char *)malloc(sizeof(char) * (col + 1));
		ft_bzero(res[i], (col + 1));
		if (!res[i])
		{
			res[i] = NULL;
			ft_free_all(res);
			ft_putstr_fd("Error\nThe allocation failed.\n", 2);
			exit(1);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
