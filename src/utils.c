/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:05:39 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/04 18:53:08 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**create_tab(size_t row, size_t col)
{
	size_t	i;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (row + 1));
	if (!res)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}

	i = 0;
	while (i < row)
	{
		res[i] = (char *)malloc(sizeof(char) * (col + 1));
		ft_bzero(res[i], (col+1));
		if (!res[i])
		{
			res[i] = NULL;
			ft_free_all(res);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

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

size_t	get_nb_col(char	*path)
{
	char	*first_line;
	size_t	res;
	int		fd_map;

	fd_map = open(path, O_RDONLY);
	if (fd_map == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	first_line = ft_get_next_line(fd_map);
	close(fd_map);
	res = ft_strlen(first_line);
	free(first_line);
	return (res);
}

size_t	get_nb_row(char	*path)
{
	size_t	res;
	char	*row;
	int		fd_map;

	fd_map = open(path, O_RDONLY);
	if (fd_map == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	row = ft_get_next_line(fd_map);
	res = 0;
	while (row)
	{
		res++;
		free(row);
		row = ft_get_next_line(fd_map);
	}
	close(fd_map);
	free(row);
	return (res);
}
