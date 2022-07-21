/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:28:25 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/21 13:25:15 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_if_error(t_mlx *main, char *str, int i)
{
	if (i == -1)
		exit(1);
	else if (get_map(main, str, i) == -1
		|| check_error(main, str) == 1)
	{
		free_pointers(main->file);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_mlx	main;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments.\n");
		return (0);
	}
	main = init_main_ints(main);
	i = count_file_lines(argv[1]);
	exit_if_error(&main, argv[1], i);
	main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, main.x, main.y, "so_long");
	if (board_on_window(&main) == 1)
		return (0);
	get_p_coordinates(&main);
	mlx_hook(main.win, KeyPress, KeyPressMask, key_hook, &main);
	mlx_hook(main.win, DestroyNotify, StructureNotifyMask, mouse_hook, &main);
	mlx_loop(main.mlx);
	return (0);
}
