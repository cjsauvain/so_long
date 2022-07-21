/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:36:51 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/21 14:39:31 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_if_error2(int i, char *free_pointer)
{
	if (i == 1 || i == 2 || i == 3)
	{
		if (!free_pointer && i == 1)
			ft_printf("Error\nEmpty map.\n");
		else if (i == 1 || i == 2 || i == 3)
			ft_printf("Error\nInvalid map size.\n");
		exit(1);
	}
}

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
	{
		ft_printf("Error\nFile could not be opened\n");
		return (-1);
	}
	free_pointer = get_next_line(fd);
	while (free_pointer != NULL)
	{
		free(free_pointer);
		free_pointer = get_next_line(fd);
		i++;
	}
	exit_if_error2(i, free_pointer);
	close(fd);
	return (i);
}

int	get_map(t_mlx *main, char *file_path, int j)
{
	int		fd;
	int		i;
	int		len;

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
		len = ft_strlen(main->file[i]);
		if (main->file[i] && main->file[i][len - 1] == '\n')
			main->file[i][len - 1] = '\0';
		main->y += 48;
		i++;
	}
	main->x = ft_strlen(main->file[0]) * 48;
	close(fd);
	return (0);
}
