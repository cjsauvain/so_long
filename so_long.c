/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:28:25 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/24 10:14:51 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	even_cases(void *mlx, void *mlx_win, t_imgs img, char *str)
{
	while (*str != '\n')
	{
		if (*str == '0' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.wc, img.x, img.y);
		else if (*str == '0' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.gc, img.x, img.y);
		else if (*str == '1' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.bp_ow, img.x, img.y);
		else if (*str == '1' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.bp_og, img.x, img.y);
		else if (*str == 'C' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.bq_ow, img.x, img.y);
		else if (*str == 'C' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.bq_og, img.x, img.y);
		else if (*str == 'E' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.yk_ow, img.x, img.y);
		else if (*str == 'E' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.yk_og, img.x, img.y);
		else if (*str == 'P' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.wp_ow, img.x, img.y);
		else if (*str == 'P' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.wp_og, img.x, img.y);
		img.x += 48;
		str++;
	}
}

void	odd_cases(void *mlx, void *mlx_win, t_imgs img, char *str)
{
	while (*str != '\n')
	{
		if (*str == '0' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.gc, img.x, img.y);
		else if (*str == '0' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.wc, img.x, img.y);
		else if (*str == '1' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.bp_og, img.x, img.y);
		else if (*str == '1' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.bp_ow, img.x, img.y);
		else if (*str == 'C' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.bq_og, img.x, img.y);
		else if (*str == 'C' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.bq_ow, img.x, img.y);
		else if (*str == 'E' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.yk_og, img.x, img.y);
		else if (*str == 'E' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.yk_ow, img.x, img.y);
		else if (*str == 'P' && ((img.x / 2) % 48 == 0))
			mlx_put_image_to_window(mlx, mlx_win, img.wp_og, img.x, img.y);
		else if (*str == 'P' && ((img.x / 2) % 48 != 0))
			mlx_put_image_to_window(mlx, mlx_win, img.wp_ow, img.x, img.y);
		img.x += 48;
		str++;
	}
}

void	board_on_window(void *mlx, void *mlx_win, t_imgs img, char *file)
{
	t_xpm	xpm;
	int		fd;
	char	*str;

	xpm = xpm_names(xpm);
	img = file_to_image(mlx, img, xpm);
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return ;
	while (str != NULL)
	{
		if ((img.y / 2) % 48 == 0)
			even_cases(mlx, mlx_win, img, str);
		else if ((img.y / 2) % 48 != 0)
			odd_cases(mlx, mlx_win, img, str);
		img.y += 48;
		str = get_next_line(fd);
	}
	mlx_loop_hook(mlx, key_hook, &mlx);
	close(fd);
}

t_imgs	get_dimensions(char *file, t_imgs img)
{
	char	*str;
	int		fd;

	img.y = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (img);
	img.x = ft_strlen(str) * 48 - 48;
	while (str != NULL)
	{
		str = get_next_line(fd);
		img.y += 48;
	}
	free(str);
	close(fd);
	return (img);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	mlx.img.x = 1000;
	mlx.img.y = 1000;
	mlx.mlx = mlx_init();
	mlx.img = get_dimensions(argv[1], mlx.img);
	mlx.win = mlx_new_window(mlx.mlx, mlx.img.x, mlx.img.y, "so_long");
	board_on_window(mlx.mlx, mlx.win, mlx.img, argv[1]);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
