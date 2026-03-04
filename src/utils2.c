/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:21:02 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/04 20:07:37 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_lines(int fd_map, char *line)
{
	while (line)
	{
		free(line);
		line = ft_get_next_line(fd_map);
	}
	ft_putstr_fd("Error\n", 2);
	close (fd_map);
	exit(1);
}
