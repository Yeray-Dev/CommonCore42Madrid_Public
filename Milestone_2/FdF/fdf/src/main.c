/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:12:41 by yblanco-          #+#    #+#             */
/*   Updated: 2025/08/01 18:17:15 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	char	*file_name;

	if (argc != 2)
	{
		perror("Numero de argumentos INVALIDO MAXIMO 2");
		return (0);
	}
	check_filename(argv[1]);
	file_name = argv[1];
	map.width = 0;
	map.height = 0;
	map.z_min = INT_MAX;
	map.z_max = INT_MIN;
	load_map(file_name, &map);
	init_windows(&map);
	transform_point(&map);
	render(&map);
	mlx_loop(map.mlx);
}
