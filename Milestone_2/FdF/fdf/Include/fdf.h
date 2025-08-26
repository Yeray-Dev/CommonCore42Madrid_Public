/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:32:48 by yblanco-          #+#    #+#             */
/*   Updated: 2025/08/01 18:07:47 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Definitions
# define WIN_WIDTH 3800
# define WIN_HEIGHT 2200
# define ESC 65307
# define KEY_PLUS 61
# define KEY_MINUS 45
# define ISO_ANGLE 0.523599
# define Z_SCALE 0.1
# define AMARILLO 0xfffb00
# define NARANJA_CLARO 0xffbc00
# define NARANJA_FUERTE 0xff7d00
# define ROJO 0xEE0000
# define BLANCO 0xffffff
# define MAP_ERROR 1
# define FILE_ERROR -1
# define CLOSE_OK 0

//Library
# include "../Libft/libft.h"
# include <stdio.h> //! TESTING
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "math.h"
# include "X11/X.h"
# include "X11/keysym.h"

// STRUCS
typedef struct s_point
{
	int		z;
	int		x_iso;
	int		y_iso;
	int		color;
	int		has_color;
}			t_point;

typedef struct s_map
{
	// File
	int		width;
	int		height;
	t_point	**points;
	int		z_min;
	int		z_max;
	int		x;
	int		y;
	char	*line;
	char	**tokens;
	int		count;
	// MiniLibx
	void	*mlx;
	void	*win;

	//ISO
	int		zoom;
	int		offset_x;
	int		offset_y;
}			t_map;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		sign_x;
	int		sign_y;
	int		err;
	int		err2;
	int		max_step;
}			t_line;

//FUNCTIONS

//FILL.c
void	allocate_points(t_map *map);
void	error_tokens(t_map *map, int count);
int		count_tokens(char *line);
void	count_dimensions(t_map *map, int fd);
void	fill_points(t_map *map, int fd);

//FILE.c
void	free_tokens(char **tokens);
int		read_file(char *file_name);
void	load_map(char *file_name, t_map *map);

//CLEAN.c
void	clean_all(t_map *map);

//CHEAK_FILENAME.c
void	check_filename(char *filename);	

//FT_SPLIT_FDF.c
char	**ft_split_fdf(char const *s, char c, int words);

//WINDOWS.c
void	win_confg(t_map *map);
int		close_key(int key, void *param);
int		close_button(void *param);
void	init_windows(t_map *map);

//PROJECT.c
void	transform_point(t_map *map);
void	project_iso_point(int z, t_map *map, t_point *point);

//COLOR.c
void	search_color(t_map *map);
int		z_color(t_map *map, t_point point);

//DRAW.c
void	error_def(t_point a, t_point b, t_line *line);
void	sign_def(t_point a, t_point b, t_line *line);
void	draw_line(t_point a, t_point b, t_map *map);
void	count_steps(t_point a, t_point b, t_map *map, t_line	*line);
int		render(void *param);

#endif

/*

xhost + 127.0.0.1

docker run --rm -it \
	-e DISPLAY=host.docker.internal:0 \
	-v /tmp/.X11-unix:/tmp/.X11-unix \
	-v "$(pwd)":/app \
	-w /app \
	--name fdf-container \
	mlx42

	https://github.com/42paris/minilibx-linux.git
*/