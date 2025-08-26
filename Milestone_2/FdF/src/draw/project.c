/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:20:19 by yblanco-          #+#    #+#             */
/*   Updated: 2025/07/19 16:51:18 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	project_iso_point(int z, t_map *map, t_point *point);

void	transform_point(t_map *map)
{
	map->x = 0;
	map->y = 0;
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
		{
			project_iso_point(map->points[map->y][map->x].z, map,
				&map->points[map->y][map->x]);
			map->x++;
		}
		map->y++;
	}
}

void	project_iso_point(int z, t_map *map, t_point *point)
{
	double	cons30;
	double	sin30;
	double	x_prime;
	double	y_prime;

	cons30 = cos(M_PI / 6);
	sin30 = sin(M_PI / 6);
	x_prime = (map->x - map->y) * cons30;
	y_prime = (map->x + map->y) * sin30 - (z * Z_SCALE);
	point->x_iso = round((x_prime * map->zoom)) + map->offset_x;
	point->y_iso = round((y_prime * map->zoom)) + map->offset_y;
}
