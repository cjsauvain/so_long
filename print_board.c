/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:36:51 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/27 17:59:09 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	board_on_window(t_mlx *main)
{
	int		i;

	i = 0;
	main->path = xpm_names(main->path);
	main->sprite = file_to_image(main);
	while (main->file[i])
	{
		if ((main->y / 2) % 48 == 0)
			even_cases(main, main->file[i]);
		else if ((main->y / 2) % 48 != 0)
			odd_cases(main, main->file[i]);
		main->x = 0;
		main->y += 48;
		i++;
	}
	if (main->c == 0)
		print_exit_case(main);
	return (0);
}

int	count_file_lines(char *str)
{
	int		fd;
	int		i;
	char	*free_pointer;

	fd = open(str, O_RDONLY);
	i = 1;
	if (fd == -1)
		return (-1);
	free_pointer = get_next_line(fd);
	while (free_pointer)
	{
		free(free_pointer);
		free_pointer = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	get_map(t_mlx *main, char *file_path, int j)
{
	int		fd;
	int		i;

	i = 0;
	main->y = -48;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	main->file = malloc((j + 1) * sizeof(char *));
	main->file[j] = 0;
	while (i < j)
	{
		main->file[i] = get_next_line(fd);
		if (main->file[i])
			main->file[i][ft_strlen(main->file[i]) - 1] = '\0';
		main->y += 48;
		i++;
	}
	main->x = ft_strlen(main->file[0]) * 48;
	close(fd);
	return (0);
}
