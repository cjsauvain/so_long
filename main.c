/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:28:25 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/27 17:58:57 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		i;
	t_mlx	main;

	(void)argc;
	main.error_c = 0;
	main.error_e = 0;
	main.error_p = 0;
	main.c = 0;
	main.step = 0;
	i = count_file_lines(argv[1]);
	if (i == -1 || get_map(&main, argv[1], i) == -1
		|| check_error(&main, argv[1]) == 1)
		return (0);
	main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, main.x, main.y, "so_long");
	if (board_on_window(&main) == 1)
		return (0);
	get_p_coordinates(&main);
	mlx_hook(main.win, KeyPress, KeyPressMask, key_hook, &main);
	mlx_loop(main.mlx);
	return (0);
}
