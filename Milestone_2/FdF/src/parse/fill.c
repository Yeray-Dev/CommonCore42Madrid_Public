/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:14:32 by yblanco-          #+#    #+#             */
/*   Updated: 2025/08/01 18:08:34 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	allocate_points(t_map *map)
{
	int	i;

	i = 0;
	map->points = ft_calloc(map->height, sizeof(t_point *));
	if (!map->points)
		return ;
	while (map->height > i)
	{
		map->points[i] = ft_calloc(map->width, sizeof(t_point));
		if (!map->points[i])
		{
			while (--i >= 0)
				free(map->points[i]);
			free(map->points);
			return ;
		}
		i++;
	}
}

void	error_tokens(t_map *map, int count)
{
	int	new_count;

	new_count = 0;
	new_count = count_tokens(map->line);
	if (count != new_count)
	{
		write(1, "ERROR: Invalid map format -> the column arent same\n", 50);
		exit(MAP_ERROR);
	}
}

int	count_tokens(char *line)
{
	int		count;
	int		in_token;

	count = 0;
	in_token = 0;
	while (*line)
	{
		if (*line != ' ' && in_token == 0)
		{
			in_token = 1;
			count++;
		}
		else if (*line == ' ')
			in_token = 0;
		line++;
	}
	return (count);
}

void	count_dimensions(t_map *map, int fd)
{
	map->line = get_next_line(fd);
	while (map->line != NULL)
	{
		map->height++;
		if (map->height == 1)
			map->count = count_tokens(map->line);
		else if (map->height > 1)
			error_tokens(map, map->count);
		map->width = map->count;
		free(map->line);
		map->line = get_next_line(fd);
	}
}

void	fill_points(t_map *map, int fd)
{
	map->y = 0;
	map->line = get_next_line(fd);
	while (map->line != NULL)
	{
		map->tokens = ft_split_fdf(map->line, ' ', map->count);
		map->x = 0;
		while (map->x < map->width)
		{
			if (ft_strchr(map->tokens[map->x], ',') != NULL)
				search_color(map);
			else
			{
				map->points[map->y][map->x].z = ft_atoi(map->tokens[map->x]);
				if (map->points[map->y][map->x].z > map->z_max)
					map->z_max = map->points[map->y][map->x].z;
				if (map->points[map->y][map->x].z < map->z_min)
					map->z_min = map->points[map->y][map->x].z;
			}
			map->x++;
		}
		free_tokens(map->tokens);
		free(map->line);
		map->y++;
		map->line = get_next_line(fd);
	}
}
