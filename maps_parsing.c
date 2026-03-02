/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:01:37 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/02 18:48:55 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	get_nb_col(int fd_map);
static size_t	get_nb_row(int fd_map);
//static char		**fill_map(char **map, int fd_map, size_t col);

char	**parse_map(char *path)
{
	char	**res;
	size_t	row;
	size_t	col;

	col = get_nb_col(open(path, O_RDONLY));
	row = get_nb_row(open(path, O_RDONLY));
	res = create_tab(row, col);
	//return (fill_map(res, open(path, O_RDONLY), col));
	return (res);
}

static size_t	get_nb_col(int fd_map)
{
	char	*first_line;
	size_t	res;

	first_line = ft_get_next_line(fd_map);
	close(fd_map);
	res = ft_strlen(first_line);
	free(first_line);
	return (res);
}

static size_t	get_nb_row(int fd_map)
{
	//size_t	res;
	char	*row;

	printf("%d\n", fd_map);
	row = ft_get_next_line(fd_map);
	printf("%s\n", row);
	/*while (*row)
	{
		res++;
		row = ft_get_next_line(fd_map);
	}
	close(fd_map); */
	free(row);
	return (5);
}

/* static char	**fill_map(char **map, int fd_map, size_t col)
{
	char	*line;
	size_t	i;
	size_t	r;

	line = ft_get_next_line(fd_map);
	r = 0;
	while (*line)
	{
		i = 0;
		while (i < col)
		{
			map[i][r] = line[i];
			i++;
		}
		free(line);
		line = ft_get_next_line(fd_map);
		r++;
	}
	return (map);
} */
