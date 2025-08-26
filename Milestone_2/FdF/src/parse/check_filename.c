/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:48:25 by yblanco-          #+#    #+#             */
/*   Updated: 2025/08/01 18:10:38 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	check_filename(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || ft_strncmp(dot + 1, "fdf", 3) != 0)
	{
		write(1, "FILE ERROR: UNSOPORTED FILE EXTENSION\n", 38);
		exit(FILE_ERROR);
	}
}
