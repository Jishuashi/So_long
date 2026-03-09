/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:44:14 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/09 16:39:01 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	free_game(t_game *game);

void	init_assets(t_game	*game)
{
	game->assets = (t_assets *)malloc(sizeof(t_assets));
	if (!game->assets)
	{
		ft_free_all(game->map);
		free(game->mlx);
		free(game->size);
		free(game->player_pos);
		ft_putstr_fd("Error\nThe allocation failed\n", 2);
		exit (1);
	}
	game->assets->img_height = 64;
	game->assets->img_width = 64;
	game->assets->wall = mlx_xpm_file_to_image(game->mlx, WALL_PATH,
			&game->assets->img_width, &game->assets->img_height);
	game->assets->player = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH,
			&game->assets->img_width, &game->assets->img_height);
	game->assets->floor = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH,
			&game->assets->img_width, &game->assets->img_height);
	game->assets->coin = mlx_xpm_file_to_image(game->mlx, COIN_PATH,
			&game->assets->img_width, &game->assets->img_height);
	game->assets->exit = mlx_xpm_file_to_image(game->mlx, EXIT_PATH,
			&game->assets->img_width, &game->assets->img_height);
	check_textures(game);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size->x)
	{
		j = 0;
		while (j < game->size->y)
		{
			put_on_win(game->map[i][j], game, get_point(j * 64, i * 64));
			j++;
		}
		i++;
	}
}

void	put_on_win(char name, t_game *game, t_point *pos)
{
	if (name == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->assets->player,
			pos->x, pos->y);
	if (name == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->assets->exit,
			pos->x, pos->y);
	if (name == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->assets->wall,
			pos->x, pos->y);
	if (name == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->assets->floor,
			pos->x, pos->y);
	if (name == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->assets->coin,
			pos->x, pos->y);
	free(pos);
}

void	check_textures(t_game *game)
{
	if (!game->assets->wall || !game->assets->player || !game->assets->floor
		|| !game->assets->coin || !game->assets->exit)
	{
		ft_putstr_fd("Error\nImpossible de charger les textures\n", 2);
		free_game(game);
	}
}

static void	free_game(t_game *game)
{
	if (game->assets->wall)
		mlx_destroy_image(game->mlx, game->assets->wall);
	if (game->assets->player)
		mlx_destroy_image(game->mlx, game->assets->player);
	if (game->assets->floor)
		mlx_destroy_image(game->mlx, game->assets->floor);
	if (game->assets->coin)
		mlx_destroy_image(game->mlx, game->assets->coin);
	if (game->assets->exit)
		mlx_destroy_image(game->mlx, game->assets->exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->assets);
	ft_free_all(game->map);
	free(game->size);
	free(game->player_pos);
	free(game->exit_pos);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}
