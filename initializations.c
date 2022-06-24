/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:02:02 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/21 15:54:25 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_xpm	xpm_names(t_xpm xpm)
{
	xpm.wc = "image/white_case.xpm";
	xpm.gc = "image/green_case.xpm";
	xpm.wp_ow = "image/white_pawn_on_white.xpm";
	xpm.wp_og = "image/white_pawn_on_green.xpm";
	xpm.bp_ow = "image/black_pawn_on_white.xpm";
	xpm.bp_og = "image/black_pawn_on_green.xpm";
	xpm.bq_ow = "image/blue_queen_on_white.xpm";
	xpm.bq_og = "image/blue_queen_on_green.xpm";
	xpm.yk_ow = "image/yellow_king_on_white.xpm";
	xpm.yk_og = "image/yellow_king_on_green.xpm";
	return (xpm);
}

t_imgs	file_to_image(void *mlx, t_imgs img, t_xpm xpm)
{
	int	l;

	img.wc = mlx_xpm_file_to_image(mlx, xpm.wc, &l, &l);
	img.gc = mlx_xpm_file_to_image(mlx, xpm.gc, &l, &l);
	img.wp_ow = mlx_xpm_file_to_image(mlx, xpm.wp_ow, &l, &l);
	img.wp_og = mlx_xpm_file_to_image(mlx, xpm.wp_og, &l, &l);
	img.bp_ow = mlx_xpm_file_to_image(mlx, xpm.bp_ow, &l, &l);
	img.bp_og = mlx_xpm_file_to_image(mlx, xpm.bp_og, &l, &l);
	img.bq_ow = mlx_xpm_file_to_image(mlx, xpm.bq_ow, &l, &l);
	img.bq_og = mlx_xpm_file_to_image(mlx, xpm.bq_og, &l, &l);
	img.yk_ow = mlx_xpm_file_to_image(mlx, xpm.yk_ow, &l, &l);
	img.yk_og = mlx_xpm_file_to_image(mlx, xpm.yk_og, &l, &l);
	img.x = 0;
	img.y = 0;
	return (img);
}
