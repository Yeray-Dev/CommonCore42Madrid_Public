/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:36:39 by yblanco-          #+#    #+#             */
/*   Updated: 2025/08/01 17:10:27 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	win_confg(t_map *map)
{
	map->offset_x = WIN_WIDTH / 2;
	map->offset_y = WIN_HEIGHT / 8;
	map->zoom = 6;
}

int	close_key(int key, void *param)
{
	t_map	*map;

	(void)param;
	map = (t_map *) param;
	if (key == ESC)
	{
		mlx_destroy_window(map->mlx, map->win);
		mlx_destroy_display(map->mlx);
		clean_all(map);
		exit(CLOSE_OK);
	}
	return (0);
}

int	close_button(void *param)
{
	t_map	*map;

	(void)param;
	map = (t_map *)param;
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	clean_all(map);
	exit(CLOSE_OK);
}

void	init_windows(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		perror("mlx_init failed");
		exit(EXIT_FAILURE);
	}
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!map->win)
	{
		perror("mlx_new_window failed");
		exit(EXIT_FAILURE);
	}
	win_confg(map);
	mlx_key_hook(map->win, close_key, map);
	mlx_hook(map->win, 17, 0, close_button, map);
}
