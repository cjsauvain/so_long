/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:57:27 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/26 16:32:13 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_even_cases(t_mlx *main, char *str)
{
	if (*str == '0' || *str == 'E')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wc, main->x, main->y);
	else if (*str == '1')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.br_ow, main->x, main->y);
	else if (*str == 'C')
	{
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.bq_ow, main->x, main->y);
		main->c++;
	}
	else if (*str == 'P')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_ow, main->x, main->y);
}

void	null_odd_cases(t_mlx *main, char *str)
{
	if (*str == '0' || *str == 'E')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.gc, main->x, main->y);
	else if (*str == '1')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.br_og, main->x, main->y);
	else if (*str == 'C')
	{
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.bq_og, main->x, main->y);
		main->c++;
	}
	else if (*str == 'P')
		mlx_put_image_to_window(main->mlx, main->win, \
			main->sprite.wp_og, main->x, main->y);
}

void	even_cases(t_mlx *main, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{		
		if ((main->x / 2) % 48 == 0)
			null_even_cases(main, str + i);
		else if (str[i] == '0' || str[i] == 'E')
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.gc, main->x, main->y);
		else if (str[i] == '1' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.br_og, main->x, main->y);
		else if (str[i] == 'C' && ((main->x / 2) % 48 != 0))
		{
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.bq_og, main->x, main->y);
			main->c++;
		}
		else if (str[i] == 'P' && ((main->x / 2) % 48 != 0))
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.wp_og, main->x, main->y);
		main->x += 48;
		i++;
	}
}

void	odd_cases(t_mlx *main, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((main->x / 2) % 48 == 0)
			null_odd_cases(main, str + i);
		else if (str[i] == '0' || str[i] == 'E')
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.wc, main->x, main->y);
		else if (str[i] == '1')
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.br_ow, main->x, main->y);
		else if (str[i] == 'C')
		{
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.bq_ow, main->x, main->y);
			main->c++;
		}
		else if (str[i] == 'P')
			mlx_put_image_to_window(main->mlx, main->win, \
				main->sprite.wp_ow, main->x, main->y);
		main->x += 48;
		i++;
	}
}
