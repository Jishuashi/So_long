/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:01:37 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/06 15:23:48 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char		**fill_map(char **map, int fd_map, size_t col);

char	**parse_map(char *path, size_t row, size_t col)
{
	char	**res;

	res = create_tab(row, col);
	return (fill_map(res, open(path, O_RDONLY), col));
	return (res);
}

static char	**fill_map(char **map, int fd_map, size_t col)
{
	char	*line;
	size_t	i;
	size_t	r;

	line = ft_get_next_line(fd_map);
	r = 0;
	while (line)
	{
		i = 0;
		while (i < col && line[i])
		{
			if (line[i] == '\n')
				break ;
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
