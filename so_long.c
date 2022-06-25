/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:28:25 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/25 11:42:40 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	board_on_window(t_mlx *main)
{
	int		fd;
	char	*str;

	main->path = xpm_names(main->path);
	main->sprite = file_to_image(main);
	fd = open(main->file, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (1);
	while (str != NULL)
	{
		if ((main->y / 2) % 48 == 0)
			even_cases(main, str);
		else if ((main->y / 2) % 48 != 0)
			odd_cases(main, str);
		main->x = 0;
		main->y += 48;
		str = get_next_line(fd);
	}
	close(fd);
	if (get_P_coordinates(main) == 1)
		return (1);
	return (0);
}

t_mlx	get_dimensions(t_mlx main)
{
	char	*str;
	int		fd;

	main.y = 0;
	fd = open(main.file, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (main);
	main.x = ft_strlen(str) * 48 - 48;
	while (str != NULL)
	{
		str = get_next_line(fd);
		main.y += 48;
	}
	free(str);
	close(fd);
	return (main);
}

int	main(int argc, char **argv)
{
	t_mlx	main;

	(void)argc;
	main.mlx = mlx_init();
	main.file = argv[1];
	main = get_dimensions(main);
	main.win = mlx_new_window(main.mlx, main.x, main.y, "so_long");
	if (board_on_window(&main) == 1)
		return (0);
	mlx_hook(main.win, KeyPress, KeyPressMask, key_hook, &main);
	mlx_loop(main.mlx);
	return (0);
}
