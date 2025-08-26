/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:14:19 by yblanco-          #+#    #+#             */
/*   Updated: 2025/08/01 18:03:04 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	read_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == FILE_ERROR)
	{
		perror("EMPTY FILE .FDF");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	load_map(char *file_name, t_map *map)
{
	int	fd;

	fd = read_file(file_name);
	count_dimensions(map, fd);
	close(fd);
	fd = read_file(file_name);
	allocate_points(map);
	close(fd);
	fd = read_file(file_name);
	fill_points(map, fd);
	close(fd);
}
