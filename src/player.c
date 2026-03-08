/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:02:44 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/08 03:20:23 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_player_position(t_game *game, t_point *new_pos);

void	move_player(t_game *game, t_point *new_pos)
{
	if (game->map[new_pos->x][new_pos->y] == '1')
	{
		free(new_pos);
		return ;
	}
	else if (game->map[new_pos->x][new_pos->y] == 'C')
		game->nb_collec--;
	game->nb_move++;
	ft_printf("Move : %d\n", game->nb_move);
	update_player_position(game, new_pos);
	free(new_pos);
	if (game->player_pos->x == game->exit_pos->x
		&& game->player_pos->y == game->exit_pos->y && game->nb_collec == 0)
	{
		close_game(game);
	}
}

static void	update_player_position(t_game *game, t_point *new_pos)
{
	game->map[game->player_pos->x][game->player_pos->y] = '0';
	if (game->exit_pos->x == game->player_pos->x
		&& game->exit_pos->y == game->player_pos->y)
		game->map[game->player_pos->x][game->player_pos->y] = 'E';
	game->map[new_pos->x][new_pos->y] = 'P';
	set_point(game->player_pos, new_pos->x, new_pos->y);
	render_map(game);
}
