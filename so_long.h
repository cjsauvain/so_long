/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:28:40 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/25 11:44:23 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"

typedef struct s_imgs
{
	void	*wc;
	void	*gc;
	void	*wp_ow;
	void	*wp_og;
	void	*bp_ow;
	void	*bp_og;
	void	*bq_ow;
	void	*bq_og;
	void	*yk_ow;
	void	*yk_og;
}	t_imgs;

typedef struct s_xpm
{	
	char	*wc;
	char	*gc;
	char	*wp_ow;
	char	*wp_og;
	char	*bp_ow;
	char	*bp_og;
	char	*bq_ow;
	char	*bq_og;
	char	*yk_ow;
	char	*yk_og;
}	t_xpm;

typedef struct s_mlx
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	char	*file;
	t_imgs	sprite;
	t_xpm	path;
}	t_mlx;

//so_long.c
void	put_board_on_window(t_mlx *main, char *file);
t_mlx	get_dimensions(t_mlx main);

//initializations.c
t_xpm	xpm_names(t_xpm path);
t_imgs	file_to_image(t_mlx *main);

//print_cases.c
void	null_even_cases(t_mlx *main, char *str);
void	even_cases(t_mlx *main, char *str);
void	null_odd_cases(t_mlx *main, char *str);
void	odd_cases(t_mlx *main, char *str);

//hooks.c
void	destroy_images(t_mlx *mlx);
int		check_coordinates(t_mlx main);
int		key_hook(int keycode, t_mlx *mlx);

//move_functions.c
void	w_move(t_mlx *main);
void	s_move(t_mlx *main);
void	a_move(t_mlx *main);
void	d_move(t_mlx *main);

//get_P_coordinates.c
int	check_src(char *src);
int	get_P_coordinates(t_mlx *main);

#endif
