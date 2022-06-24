/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:28:40 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/24 10:13:53 by jsauvain         ###   ########.fr       */
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
	char	*wp_ow;
	char	*wp_og;
	char	*bp_ow;
	char	*bp_og;
	char	*bq_ow;
	char	*bq_og;
	char	*yk_ow;
	char	*yk_og;
	int		x;
	int		y;
}	t_imgs;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_imgs	img;
}	t_mlx;

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

//so_long.c
void	even_cases(void *mlx, void *mlx_win, t_imgs img, char *str);
void	odd_cases(void *mlx, void *mlx_win, t_imgs img, char *str);
void	put_board_on_window(void *mlx, void *mlx_win, t_imgs img, char *file);

//initializations.c
t_xpm	xpm_names(t_xpm xpm);
t_imgs	file_to_image(void *mlx, t_imgs img, t_xpm xpm);

//hooks.c
void	destroy_images(void *mlx, t_imgs img);
int		key_hook(int keycode, t_mlx *mlx);
void	hooks(t_mlx mlx);

#endif
