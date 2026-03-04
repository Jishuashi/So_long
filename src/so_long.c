/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:38:08 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/04 18:47:26 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char *av[])
{
	char	**map;
	size_t	col;
	size_t	row;
	size_t	i;
	size_t	j;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1]))
		|| !ft_strchr(av[1], 47))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	col = get_nb_col(av[1]);
	row = get_nb_row(av[1]);
	map = parse_map(av[1], row, col);
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_free_all(map);
	return (0);
}
