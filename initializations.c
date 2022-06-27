/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:02:02 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/25 16:49:38 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_xpm	xpm_names(t_xpm path)
{
	path.wc = "image/white_case.xpm";
	path.gc = "image/green_case.xpm";
	path.wp_ow = "image/white_pawn_on_white.xpm";
	path.wp_og = "image/white_pawn_on_green.xpm";
	path.br_ow = "image/black_rook_on_white.xpm";
	path.br_og = "image/black_rook_on_green.xpm";
	path.bq_ow = "image/blue_queen_on_white.xpm";
	path.bq_og = "image/blue_queen_on_green.xpm";
	path.yk_ow = "image/yellow_king_on_white.xpm";
	path.yk_og = "image/yellow_king_on_green.xpm";
	return (path);
}

t_imgs	file_to_image(t_mlx *main)
{
	int	l;

	main->sprite.wc = mlx_xpm_file_to_image(main->mlx, main->path.wc, &l, &l);
	main->sprite.gc = mlx_xpm_file_to_image(main->mlx, main->path.gc, &l, &l);
	main->sprite.wp_ow = mlx_xpm_file_to_image(main->mlx, \
		main->path.wp_ow, &l, &l);
	main->sprite.wp_og = mlx_xpm_file_to_image(main->mlx, \
		main->path.wp_og, &l, &l);
	main->sprite.br_ow = mlx_xpm_file_to_image(main->mlx, \
		main->path.br_ow, &l, &l);
	main->sprite.br_og = mlx_xpm_file_to_image(main->mlx, \
		main->path.br_og, &l, &l);
	main->sprite.bq_ow = mlx_xpm_file_to_image(main->mlx, \
		main->path.bq_ow, &l, &l);
	main->sprite.bq_og = mlx_xpm_file_to_image(main->mlx, \
		main->path.bq_og, &l, &l);
	main->sprite.yk_ow = mlx_xpm_file_to_image(main->mlx, \
		main->path.yk_ow, &l, &l);
	main->sprite.yk_og = mlx_xpm_file_to_image(main->mlx, \
		main->path.yk_og, &l, &l);
	main->x = 0;
	main->y = 0;
	return (main->sprite);
}
