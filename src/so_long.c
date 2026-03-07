/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:38:08 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 16:52:39 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	so_long(char **map, size_t row, size_t col);

int	main(int ac, char *av[])
{
	char	**map;
	size_t	col;
	size_t	row;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nNo map has been provided.\n", 2);
		exit(1);
	}
	else if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1]))
		|| !ft_strchr(av[1], 47))
	{
		ft_putstr_fd("Error\nThe map is not in .ber format.\n", 2);
		exit(1);
	}
	check_map_size(open(av[1], O_RDONLY));
	col = get_nb_col(av[1]);
	row = get_nb_row(av[1]);
	map = parse_map(av[1], row, col);
	so_long(map, row, col);
	ft_free_all(map);
	return (0);
}

static	void	so_long(char **map, size_t row, size_t col)
{
	if (checker(map, row, col))
	{
		ft_free_all(map);
		ft_putstr_fd("Error\nThe map is not surrounded by walls.\n", 2);
		exit (1);
	}
	checker_finishable(map, row, col);
}
