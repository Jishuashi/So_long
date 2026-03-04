/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:01:00 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/04 18:29:02 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

void	ft_free_all(char **to_free);
char	**create_tab(size_t row, size_t col);
char	**parse_map(char *path, size_t row, size_t col);
size_t	get_nb_col(char	*path);
size_t	get_nb_row(char	*path);

#endif