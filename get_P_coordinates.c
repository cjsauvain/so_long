/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_P_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:01:06 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/25 11:41:12 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_src(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == 'P')
			return (0);
		i++;
	}
	return (1);
}

int	get_P_coordinates(t_mlx *main)
{
	int		fd;
	int		j;
	int		i;
	char	*src;
	
	fd = open(main->file, O_RDONLY);
	i = 0;
	if (fd == -1)
		return (1);
	src = get_next_line(fd);
	j = 1;
	while (check_src(src) == 1 && src != NULL)
	{
		src = get_next_line(fd);
		j++;
	}
	while (src[i] != 'P' && src[i] && src != NULL)
		i++;
	if (src[i] == '\0' || src == NULL)
		return (1);
	main->x = i * 48;
	main->y = (j - 1) * 48;
	return (0);
}
