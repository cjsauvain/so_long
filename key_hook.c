/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:13:34 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/27 10:42:47 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_exit_case(t_mlx *main)
{
	int		i;
	int		j;

	i = 0;
	while (main->file[i])
	{
		j = 0;
		while (main->file[i][j])
		{
			if (main->file[i][j] == 'E')
			{
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 && j % 2))
					mlx_put_image_to_window(main->mlx, main->win, \
					main->sprite.yk_ow, j * 48, i * 48);
				else if ((i % 2 == 0 && j % 2) || (i % 2 && j % 2 == 0))
					mlx_put_image_to_window(main->mlx, main->win, \
					main->sprite.yk_og, j * 48, i * 48);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	key_hook(int keycode, t_mlx *main)
{
	if (keycode == 'w' && check_coordinates(main, 1, 0) == 0)
		w_move(main);
	else if (keycode == 's' && check_coordinates(main, -1, 0) == 0)
		s_move(main);
	else if (keycode == 'a' && check_coordinates(main, 0, 1) == 0)
		a_move(main);
	else if (keycode == 'd' && check_coordinates(main, 0, -1) == 0)
		d_move(main);
	else if (keycode == XK_Escape)
		destroy(main);
	if (main->c == 0)
		print_exit_case(main);
	return (0);
}
