/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:16:19 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/07 19:24:32 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

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

#endif