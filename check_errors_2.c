/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:37:19 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/28 15:38:49 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_format(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (i && file[i] == '.')
		{
			if (file[i + 1] != 'b' || file[i + 2] != 'e' || file[i + 3] != 'r')
			{
				ft_printf("Error\nWrong file format.\n");
				return (1);
			}
			else if (file[i + 4])
			{
				ft_printf("Error\nWrong file format.\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	check_dimension(char **buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (i && ft_strlen(buf[i - 1]) != ft_strlen(buf[i]))
		{
			ft_printf("Error\nThe shape is not rectangular.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_walls(char **buf)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (buf[i])
	{
		j = 0;
		while (buf[i][j])
		{
			if ((i == 0 || i == strlen_double(buf)) && buf[i][j] != '1')
				n = 1;
			if (buf[i][0] != '1' || buf[i][ft_strlen(buf[i]) - 1] != '1')
				n = 1;
			j++;
		}
		i++;
	}
	if (n == 1)
		ft_printf("Error\nNot surrounded by walls.\n");
	return (n);
}

int	check_inside_map(t_mlx *main)
{
	int	i;
	int	j;

	i = 1;
	while (i < strlen_double(main->file) - 1)
	{
		j = 0;
		while (main->file[i][j])
		{
			if (main->file[i][j] == 'E')
				main->error_e++;
			else if (main->file[i][j] == 'C')
				main->error_c++;
			else if (main->file[i][j] == 'P')
				main->error_p++;
			j++;
		}
		i++;
	}
	if (check_inside_map2(main) == 1)
		return (1);
	return (0);
}

int	check_map_letters(char **buf)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i])
	{
		j = 0;
		while (buf[i][j])
		{
			if (buf[i][j] != '1' && buf[i][j] != '0' && buf[i][j] != 'E'
				&& buf[i][j] != 'C' && buf[i][j] != 'P')
			{
				ft_printf("Error\nA '%c' has been found at (%d;%d).\n" \
				, buf[i][j], i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
