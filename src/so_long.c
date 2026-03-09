/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:38:08 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/09 16:42:38 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	so_long(char **map, size_t row, size_t col);
static void	launch_game(char **map, size_t row, size_t col);
static void	check_files(char *path);

int	main(int ac, char *av[])
{
	char	**map;
	size_t	col;
	size_t	row;

	if (ac < 2)
	{
		ft_putstr_fd("Error\nNo map has been provided.\n", 2);
		exit(1);
	}
	if (ac > 2)
	{
		ft_putstr_fd("Error\nTo much argument was given\n", 2);
		exit(1);
	}
	check_files(av[1]);
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
	launch_game(map, row, col);
}

static void	launch_game(char **map, size_t row, size_t col)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_free_all(map);
		ft_putstr_fd("Error\nThe minilibx cannot be loaded.\n", 2);
		exit(1);
	}
	game.map = map;
	game.width = (col * 64);
	game.height = (row * 64);
	game.size = get_point(row, col);
	game.win = mlx_new_window(game.mlx, game.width, game.height, "So Long");
	game.player_pos = get_player_pos(game.map, game.size->x, game.size->y);
	game.exit_pos = get_exit_pos(game.map, game.size->x, game.size->y);
	game.nb_move = 0;
	game.nb_collec = 0;
	init_assets(&game);
	get_collectible_nb(&game);
	render_map(&game);
	mlx_hook(game.win, 17, 0, (int (*)())(void *)close_game, &game);
	mlx_key_hook(game.win, (int (*)())(void *)key_press, &game);
	mlx_loop(game.mlx);
}

static void	check_files(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid map extension (must be .ber)\n", 2);
		exit(1);
	}
	if (len == 4 || path[len - 5] == '/')
	{
		ft_putstr_fd("Error\nThe map .ber has no name\n", 2);
		exit(1);
	}
}
