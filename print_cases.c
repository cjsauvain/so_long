/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:57:27 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/25 09:37:57 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_even_cases(t_mlx *main, char *str)
{
	if (*str == '0')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wc, main->x, main->y);
	else if (*str == '1')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.bp_ow, main->x, main->y);
	else if (*str == 'C')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.bq_ow, main->x, main->y);
	else if (*str == 'E')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.yk_ow, main->x, main->y);
	else if (*str == 'P')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
}

void	even_cases(t_mlx *main, char *str)
{
	while (*str != '\n')
	{		
		if ((main->x / 2) % 48 == 0)
			null_even_cases(main, str);
		else if (*str == '0' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.gc, main->x, main->y);
		else if (*str == '1' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.bp_og, main->x, main->y);
		else if (*str == 'C' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.bq_og, main->x, main->y);
		else if (*str == 'E' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.yk_og, main->x, main->y);
		else if (*str == 'P' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.wp_og, main->x, main->y);
		main->x += 48;
		str++;
	}
}

void	null_odd_cases(t_mlx *main, char *str)
{
	if (*str == '0')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.gc, main->x, main->y);
	else if (*str == '1')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.bp_og, main->x, main->y);
	else if (*str == 'C')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.bq_og, main->x, main->y);
	else if (*str == 'E')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.yk_og, main->x, main->y);
	else if (*str == 'P')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_og, main->x, main->y);
}

void	odd_cases(t_mlx *main, char *str)
{
	while (*str != '\n')
	{
		if ((main->x / 2) % 48 == 0)
			null_odd_cases(main, str);
		else if (*str == '0' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.wc, main->x, main->y);
		else if (*str == '1' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.bp_ow, main->x, main->y);
		else if (*str == 'C' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.bq_ow, main->x, main->y);
		else if (*str == 'E' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.yk_ow, main->x, main->y);
		else if (*str == 'P' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.wp_ow, main->x, main->y);
		main->x += 48;
		str++;
	}
}
