/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:13:34 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/25 11:45:15 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_mlx *main)
{
	if (main->sprite.wc != NULL)
		mlx_destroy_image(main->mlx, main->sprite.wc);
	if (main->sprite.gc != NULL)
		mlx_destroy_image(main->mlx, main->sprite.gc);
	if (main->sprite.wp_ow != NULL)
		mlx_destroy_image(main->mlx, main->sprite.wp_ow);
	if (main->sprite.wp_og != NULL)
		mlx_destroy_image(main->mlx, main->sprite.wp_og);
	if (main->sprite.bp_ow != NULL)
		mlx_destroy_image(main->mlx, main->sprite.bp_ow);
	if (main->sprite.bp_og != NULL)
		mlx_destroy_image(main->mlx, main->sprite.bp_og);
	if (main->sprite.bq_ow != NULL)
		mlx_destroy_image(main->mlx, main->sprite.bq_ow);
	if (main->sprite.yk_ow != NULL)
		mlx_destroy_image(main->mlx, main->sprite.yk_ow);
	if (main->sprite.yk_og != NULL)
		mlx_destroy_image(main->mlx, main->sprite.yk_og);
}
/*
int	check_coordinates(t_mlx main)
{

}
*/
int	key_hook(int keycode, t_mlx *main)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(main->mlx, main->win);
		destroy_images(main);
		mlx_loop_end(main->mlx);
		mlx_destroy_display(main->mlx);
		exit(1);
	}
	if (keycode == 'w')
		w_move(main);
	else if (keycode == 's')
		s_move(main);
	else if (keycode == 'a')
		a_move(main);
	else if (keycode == 'd')
		d_move(main);
	return (0);
}
