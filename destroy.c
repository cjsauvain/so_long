/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:34:06 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/27 10:26:04 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_pointers(char **buf)
{
	int	i;

	i = 0;
	while (buf[i])
		free(buf[i++]);
	free(buf);
}

void	destroy(t_mlx *main)
{
	free_pointers(main->file);
	mlx_destroy_window(main->mlx, main->win);
	destroy_images(main);
	mlx_loop_end(main->mlx);
	mlx_destroy_display(main->mlx);
	free(main->mlx);
	exit(1);
}

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
	if (main->sprite.br_ow != NULL)
		mlx_destroy_image(main->mlx, main->sprite.br_ow);
	if (main->sprite.br_og != NULL)
		mlx_destroy_image(main->mlx, main->sprite.br_og);
	if (main->sprite.bq_ow != NULL)
		mlx_destroy_image(main->mlx, main->sprite.bq_ow);
	if (main->sprite.bq_og != NULL)
		mlx_destroy_image(main->mlx, main->sprite.bq_og);
	if (main->sprite.yk_ow != NULL)
		mlx_destroy_image(main->mlx, main->sprite.yk_ow);
	if (main->sprite.yk_og != NULL)
		mlx_destroy_image(main->mlx, main->sprite.yk_og);
}
