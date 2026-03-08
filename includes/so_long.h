/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:01:00 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/08 03:02:33 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "./point.h"
# include "./assets.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		**map;
	t_point		*player_pos;
	t_point		*exit_pos;
	t_point		*size;
	t_assets	*assets;
	int			nb_move;
	int			nb_collec;
}	t_game;

void	ft_free_all(char **to_free);
char	**create_tab(size_t row, size_t col);
char	**parse_map(char *path, size_t row, size_t col);
size_t	get_nb_col(char	*path);
size_t	get_nb_row(char	*path);
void	check_map_size(int fd_map);
void	free_lines(int fd_map, char *line);
char	checker(char **map, size_t row, size_t col);
char	**copy_map(char **map, size_t row);
void	flood_fill(char **map, t_point *pos);
t_point	*get_player_pos(char **map, size_t row, size_t col);
void	checker_finishable(char	**map, size_t row, size_t col);
int		key_press(int keycode, t_game *game);
int		close_game(t_game *game);
void	move_player(t_game *game, t_point *new_pos);
void	get_collectible_nb(t_game *game);
t_point	*get_exit_pos(char **map, size_t row, size_t col);

#endif