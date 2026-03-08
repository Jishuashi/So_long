/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:16:19 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/08 00:32:38 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H
# define WALL_PATH "./textures/wall.xpm"
# define PLAYER_PATH "./textures/player.xpm"
# define FLOOR_PATH "./textures/floor.xpm"
# define COIN_PATH "./textures/coin.xpm"
# define EXIT_PATH "./textures/exit.xpm"

typedef struct s_game	t_game;
typedef struct s_point	t_point;

typedef struct s_assets
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
	int		img_width;
	int		img_height;
}	t_assets;

void	init_assets(t_game	*game);
void	put_on_win(char name, t_game *game, t_point *pos);
void	render_map(t_game *game);
void	check_textures(t_game *game);

#endif