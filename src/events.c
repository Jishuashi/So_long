/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:28:20 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/08 01:04:54 by hchartie         ###   ########.fr       */
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
	return (0);
}
