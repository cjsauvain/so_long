/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:17:05 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/25 11:44:46 by jsauvain         ###   ########.fr       */
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
	if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
	|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
	|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_og, main->x, main->y);
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
	if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
	|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
	|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_og, main->x, main->y);
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
	if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
	|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
	|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_og, main->x, main->y);
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
	if ((main->x / 2 % 48 == 0 && main->y / 2 % 48 == 0)
	|| (main->x / 2 % 48 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
	else if ((main->x / 2 % 48 && main->y / 2 % 48 == 0)
	|| (main->x / 2 % 48 == 0 && main->y / 2 % 48))
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_og, main->x, main->y);
}
