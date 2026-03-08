/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:28:20 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/08 03:10:03 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"	

int	close_game(t_game *game)
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
	free(game->size);
	free(game->player_pos);
	ft_free_all(game->map);
	free(game->assets);
	free(game->exit_pos);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 65363 || keycode == 100)
		move_player(game, get_point(game->player_pos->x,
				game->player_pos->y + 1));
	if (keycode == 65361 || keycode == 97)
		move_player(game, get_point(game->player_pos->x,
				game->player_pos->y - 1));
	if (keycode == 65362 || keycode == 119)
		move_player(game, get_point(game->player_pos->x - 1,
				game->player_pos->y));
	if (keycode == 65364 || keycode == 115)
		move_player(game, get_point(game->player_pos->x + 1,
				game->player_pos->y));
	return (0);
}
