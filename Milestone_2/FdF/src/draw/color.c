/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:18:02 by yblanco-          #+#    #+#             */
/*   Updated: 2025/08/01 18:06:58 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	search_color(t_map *map)
{
	char	**content;

	content = ft_split(map->tokens[map->x], ',');
	map->points[map->y][map->x].z = ft_atoi(content[0]);
	if (map->points[map->y][map->x].z > map->z_max)
		map->z_max = map->points[map->y][map->x].z;
	if (map->points[map->y][map->x].z < map->z_min)
		map->z_min = map->points[map->y][map->x].z;
	map->points[map->y][map->x].color = ft_atoi_base(content[1], 16);
	map->points[map->y][map->x].has_color = 1;
}

int	z_color(t_map *map, t_point point)
{
	int	z_span;
	int	z_range;

	if (point.has_color == 1)
		return (point.color);
	z_span = map->z_max - map->z_min;
	z_range = z_span / 4;
	if (point.z < z_range)
		return (AMARILLO);
	else if (point.z >= z_range && point.z < z_range * 2)
		return (NARANJA_CLARO);
	else if (point.z >= z_range * 2 && point.z < z_range * 3)
		return (NARANJA_FUERTE);
	else if (point.z >= z_range * 3)
		return (ROJO);
	return (BLANCO);
}
