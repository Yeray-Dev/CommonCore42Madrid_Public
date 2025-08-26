/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:18:18 by yblanco-          #+#    #+#             */
/*   Updated: 2025/07/25 22:35:55 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_def(t_point a, t_point b, t_line *line)
{
	line->dy = abs(a.y_iso - b.y_iso);
	line->dx = abs(a.x_iso - b.x_iso);
	if (line->dx >= line->dy)
		line->err = line->dx / 2;
	else
		line->err = line->dy / 2;
}

void	sign_def(t_point a, t_point b, t_line *line)
{
	if (b.x_iso > a.x_iso)
		line->sign_x = 1;
	else
		line->sign_x = -1;
	if (b.y_iso > a.y_iso)
		line->sign_y = 1;
	else
		line->sign_y = -1;
}

void	count_steps(t_point a, t_point b, t_map *map, t_line	*line)
{
	int		steps;

	steps = 0;
	while ((a.x_iso != b.x_iso || a.y_iso != b.y_iso) && steps < line->max_step)
	{
		if (a.x_iso >= 0 && a.x_iso < WIN_WIDTH && \
			a.y_iso >= 0 && a.y_iso < WIN_HEIGHT)
			mlx_pixel_put(map->mlx, map->win, a.x_iso, a.y_iso, \
			z_color(map, a));
		line->err2 = line->err;
		if (line->err2 > -line->dx)
		{
			line->err -= line->dy;
			a.x_iso += line->sign_x;
		}
		if (line->err2 < line->dy)
		{
			line->err += line->dx;
			a.y_iso += line->sign_y;
		}
		steps++;
	}
	mlx_pixel_put(map->mlx, map->win, a.x_iso, a.y_iso, z_color(map, a));
}

void	draw_line(t_point a, t_point b, t_map *map)
{
	t_line	line;

	error_def(a, b, &line);
	sign_def(a, b, &line);
	if (line.dx > line.dy)
		line.max_step = line.dx;
	else
		line.max_step = line.dy;
	count_steps(a, b, map, &line);
}

int	render(void *param)
{
	int		y;
	t_map	*map;
	int		x;

	y = 0;
	map = (t_map *)param;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(map->points[y][x], map->points[y][x + 1], map);
			if (y < map->height - 1)
				draw_line(map->points[y][x], map->points[y + 1][x], map);
			x++;
		}
		y++;
	}
	return (0);
}
