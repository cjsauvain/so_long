/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:17:05 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/27 10:52:40 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_move(t_mlx *main)
{
	if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wc, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.gc, main->x, main->y);
	main->y -= 48;
	if (main->file[main->y / 48][main->x / 48] == 'E' && main->c == 0)
	{
		main->step++;
		ft_printf("%d\n", main->step);
		destroy(main);
	}
	else if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
		main->sprite.wp_og, main->x, main->y);
	main->step++;
	ft_printf("%d\n", main->step);
}

void	s_move(t_mlx *main)
{
	if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wc, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.gc, main->x, main->y);
	main->y += 48;
	if (main->file[main->y / 48][main->x / 48] == 'E' && main->c == 0)
	{
		main->step++;
		ft_printf("%d\n", main->step);
		destroy(main);
	}
	else if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_og, main->x, main->y);
	main->step++;
	ft_printf("%d\n", main->step);
}

void	a_move(t_mlx *main)
{
	if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wc, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.gc, main->x, main->y);
	main->x -= 48;
	if (main->file[main->y / 48][main->x / 48] == 'E' && main->c == 0)
	{
		main->step++;
		ft_printf("%d\n", main->step);
		destroy(main);
	}
	else if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_og, main->x, main->y);
	main->step++;
	ft_printf("%d\n", main->step);
}

void	d_move(t_mlx *main)
{
	if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wc, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.gc, main->x, main->y);
	main->x += 48;
	if (main->file[main->y / 48][main->x / 48] == 'E' && main->c == 0)
	{
		main->step++;
		ft_printf("%d\n", main->step);
		destroy(main);
	}
	else if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
		|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_og, main->x, main->y);
	main->step++;
	ft_printf("%d\n", main->step);
}
