/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:28:40 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/21 14:44:26 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

typedef struct s_imgs
{
	void	*wc;
	void	*gc;
	void	*wp_ow;
	void	*wp_og;
	void	*br_ow;
	void	*br_og;
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
	char	*br_ow;
	char	*br_og;
	char	*bq_ow;
	char	*bq_og;
	char	*yk_ow;
	char	*yk_og;
}	t_xpm;

typedef struct s_mlx
{
	int		error_c;
	int		error_e;
	int		error_p;
	int		c;
	int		x;
	int		y;
	int		step;
	void	*mlx;
	void	*win;
	char	**file;
	t_imgs	sprite;
	t_xpm	path;
}	t_mlx;

//check_errors.c
int		strlen_double(char **str);
int		check_inside_map2(t_mlx *main);
int		check_error(t_mlx *main, char *file);

//check_errors_2.c
int		check_file_format(char *file);
int		check_dimension(char **buf);
int		check_walls(char **buf);
int		check_inside_map(t_mlx *main);
int		check_map_letters(char **buf);

//initializations.c
t_mlx	init_main_ints(t_mlx main);
t_xpm	xpm_names(t_xpm path);
t_imgs	file_to_image(t_mlx *main);

//print_board.c
int		board_on_window(t_mlx *main);
int		count_file_lines(char *str);
int		get_map(t_mlx *main, char *file_path, int i);

//print_cases.c
void	null_even_cases(t_mlx *main, char *str);
void	null_odd_cases(t_mlx *main, char *str);
void	even_cases(t_mlx *main, char *str);
void	odd_cases(t_mlx *main, char *str);

//hooks.c
int		print_exit_case(t_mlx *main);
int		key_hook(int keycode, t_mlx *mlx);
int		mouse_hook(t_mlx *main);

//move_functions.c
void	w_move(t_mlx *main);
void	s_move(t_mlx *main);
void	a_move(t_mlx *main);
void	d_move(t_mlx *main);

//coordinates.c
int		check_coordinates(t_mlx *main, int k, int l);
int		get_p_coordinates(t_mlx *main);

//destroy.c
void	free_pointers(char **buf);
void	destroy(t_mlx *main);
void	destroy_images(t_mlx *mlx);

#endif
