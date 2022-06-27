/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:58:40 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/27 18:03:51 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_inside_map2(t_mlx *main)
{
	if (main->error_e == 0)
	{
		ft_printf("Error\nYou must have at least one exit.\n");
		return (1);
	}
	else if (main->error_c == 0)
	{
		ft_printf("Error\nYou must have at least one collectable item.\n");
		return (1);
	}
	if (main->error_p == 0)
	{
		ft_printf("Error\nYou must have at least one starting position.\n");
		return (1);
	}
	return (0);
}

int	check_error(t_mlx *main, char *file)
{
	if (check_file_format(file) == 1)
		return (1);
	else if (check_dimension(main->file) == 1)
		return (1);
	else if (check_walls(main->file) == 1)
		return (1);
	else if (check_inside_map(main) == 1)
		return (1);
	else if (check_map_letters(main->file) == 1)
		return (1);
	return (0);
}


// Faire une fonction qui verifie les extra characters
