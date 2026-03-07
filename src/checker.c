/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:24:22 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 17:15:51 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_walls(char **map, size_t row, size_t col);
static void	check_playable(char **map, size_t row, size_t col);
static void	check_value(char **map, int player, int collec, int exit);


char	checker(char **map, size_t row, size_t col)
{
	if (!check_walls(map, row, col))
		return (1);
	check_playable(map, row, col);
	return (0);
}

static	int	check_walls(char **map, size_t row, size_t col)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((i == 0 || i == (row - 1)) && map[i][j] != '1'
			&& map[i][j] != '\n' && map[i][j] != '\0')
				return (0);
			if ((j == 0 || j == (col - 1)) && map[i][j] != '1'
			&& map[i][j] != '\n' && map[i][j] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static	void	check_playable(char **map, size_t row, size_t col)
{
	size_t	i;
	size_t	j;
	int		check[3];

	i = 0;
	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == 'P')
				check[0]++;
			if (map[i][j] == 'C')
				check[1]++;
			if (map[i][j] == 'E')
				check[2]++;
			j++;
		}
		i++;
	}
	check_value(map, check[0], check[1], check[2]);
}

static void	check_value(char **map, int player, int collec, int ex)
{
	if (player != 1)
	{
		ft_free_all(map);
		ft_putstr_fd("Error\nMore or less one Player in map\n", 2);
		exit(1);
	}
	if (ex != 1)
	{
		ft_free_all(map);
		ft_putstr_fd("Error\nMore or less one Exit in map\n", 2);
		exit(1);
	}
	if (collec < 1)
	{
		ft_free_all(map);
		ft_putstr_fd("Error\nLess one Collection in map\n", 2);
		exit(1);
	}
}

void	checker_finishable(char	**map, size_t row, size_t col)
{
	size_t	i;
	size_t	j;
	char	**visited;

	visited = copy_map(map, row);
	flood_fill(visited, get_player_pos(map, row, col));
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (visited[i][j] == 'P' || visited[i][j] == 'E'
				|| visited[i][j] == 'C')
			{
				ft_free_all(map);
				ft_free_all(visited);
				ft_putstr_fd("Error\nThe map cannot be completed\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
	ft_free_all(visited);
}

