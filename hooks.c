/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:28:45 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/24 10:16:08 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(void *mlx, t_imgs img)
{
	mlx_destroy_image(mlx, img.wc);
	mlx_destroy_image(mlx, img.gc);
	mlx_destroy_image(mlx, img.wp_ow);
	mlx_destroy_image(mlx, img.wp_og);
	mlx_destroy_image(mlx, img.bp_ow);
	mlx_destroy_image(mlx, img.bp_og);
	mlx_destroy_image(mlx, img.bq_ow);
	mlx_destroy_image(mlx, img.bq_og);
	mlx_destroy_image(mlx, img.yk_ow);
	mlx_destroy_image(mlx, img.yk_og);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		destroy_images(mlx->mlx, mlx->img);
		mlx_destroy_display(mlx->mlx);
		exit(1);
	}
	return (0);
}

void	hooks(t_mlx mlx)
{
		mlx_loop_hook(mlx.mlx, key_hook, &mlx);
}
