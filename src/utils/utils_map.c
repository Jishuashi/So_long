/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:10:29 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 20:29:07 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

size_t	get_nb_col(char *path)
{
	char	*line;
	size_t	res;
	int		fd_map;

	fd_map = open(path, O_RDONLY);
	line = NULL;
	if (fd_map >= 0)
		line = ft_get_next_line(fd_map);
	if (!line)
	{
		ft_putstr_fd("Error\nFile Empty or Invalid\n", 2);
		exit(1);
	}
	res = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
	while (line)
	{
		free(line);
		line = ft_get_next_line(fd_map);
	}
	close(fd_map);
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
		ft_putstr_fd("Error\nNo such file or directory\n", 2);
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
	return (res);
}

void	check_map_size(int fd_map)
{
	char	*line;
	size_t	col;

	if (fd_map == -1)
	{
		ft_putstr_fd("Error\nNo such file or directory.\n", 2);
		exit(1);
	}
	line = ft_get_next_line(fd_map);
	if (!line)
	{
		ft_putstr_fd("Error\nThe allocation failed.\n", 2);
		exit(1);
	}
	col = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
	free(line);
	line = ft_get_next_line(fd_map);
	while (line)
	{
		if ((ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n')) != col)
			free_lines(fd_map, line);
		free(line);
		line = ft_get_next_line(fd_map);
	}
	close(fd_map);
}

void	free_lines(int fd_map, char *line)
{
	while (line)
	{
		free(line);
		line = ft_get_next_line(fd_map);
	}
	ft_putstr_fd("Error\n", 2);
	close (fd_map);
	exit(1);
}

t_point	*get_player_pos(char **map, size_t row, size_t col)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == 'P')
				return (get_point(i, j));
			j++;
		}
		i++;
	}
	return (get_point(0, 0));
}
