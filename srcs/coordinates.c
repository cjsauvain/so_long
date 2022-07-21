/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:01:06 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/27 10:21:26 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coordinates(t_mlx *main, int k, int l)
{
	if (main->file[(main->y / 48) - k][(main->x / 48) - l] != '1')
	{
		if (main->file[(main->y / 48) - k][(main->x / 48) - l] == 'C')
		{
			main->file[(main->y / 48) - k][(main->x / 48) - l] = '0';
			main->c--;
		}
		return (0);
	}
	return (1);
}

int	get_p_coordinates(t_mlx *main)
{
	int		j;
	int		i;

	i = 0;
	while (main->file[i])
	{
		j = 0;
		while (main->file[i][j])
		{
			if (main->file[i][j] == 'P')
			{
				main->x = j * 48;
				main->y = i * 48;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
