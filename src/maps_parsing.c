/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:01:37 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 13:30:09 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**fill_map(char **map, int fd_map, size_t row, size_t col);

char	**parse_map(char *path, size_t row, size_t col)
{
	char	**res;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	res = create_tab(row, col);
	if (!res)
	{
		close(fd);
		return (NULL);
	}
	return (fill_map(res, fd, row, col));
}

static char	**fill_map(char **map, int fd_map, size_t row, size_t col)
{
	char	*line;
	size_t	i;
	size_t	r;

	r = 0;
	line = ft_get_next_line(fd_map);
	while (line && r < row)
	{
		i = 0;
		while (i < col && line[i])
		{
			map[r][i] = line[i];
			i++;
		}
		map[r][i] = '\0';
		free(line);
		line = ft_get_next_line(fd_map);
		r++;
	}
	close(fd_map);
	return (map);
}
