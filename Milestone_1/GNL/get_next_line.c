/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:28:38 by yblanco-          #+#    #+#             */
/*   Updated: 2025/02/08 19:36:22 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buffer_aux;
	int		b_leido;

	buffer_aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer_aux)
		return (NULL);
	b_leido = 1;
	while (!ft_strchr(str, '\n') && b_leido != 0)
	{
		b_leido = read(fd, buffer_aux, BUFFER_SIZE);
		if (b_leido == -1)
		{
			free(buffer_aux);
			free(str);
			return (NULL);
		}
		buffer_aux[b_leido] = '\0';
		str = ft_strjoin(str, buffer_aux);
	}
	free(buffer_aux);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	int			*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (0);
	rest = malloc((sizeof(int) * 1));
	*rest = 0;
	line = ft_line(str, rest);
	str = ft_next_str(str, rest);
	free(rest);
	return (line);
}
