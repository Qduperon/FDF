/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 13:45:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/07/19 18:15:09 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./../libft/includes/libft.h"
# include "./../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define WIDTH	1500
# define HEIGHT	750
# define XCENTER (WIDTH / 2)
# define YCENTER (HEIGHT / 2)

# define ECHAP	53
# define UP		126
# define DOWN	125
# define RIGHT	124
# define LEFT	123
# define ZOOM	69
# define DEZOOM	78
# define Z_LESS	116
# define Z_MORE	121
# define RESET	71

typedef struct		s_box
{
	float			xc;
	float			yc;
	float			coeff;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
}					t_box;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_coord;

typedef struct		s_inc
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	int				z3;
	int				color;
	int				color2;
	int				color3;
}					t_inc;

typedef	struct		s_env
{
	char			*data;
	float			rot;
	float			roty;
	int				bpp;
	int				endian;
	int				max_x;
	int				max_y;
	int				off;
	int				off2;
	int				s_line;
	int				z;
	int				zoom;
	int				zh;
	t_box			*box;
	t_coord			***coord;
	t_inc			*inc;
	unsigned long	color;
	unsigned long	color2;
	unsigned long	color3;
	void			*img;
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_map
{
	char			**av;
	char			**map;
	char			**tmp;
	int				x;
	int				y;
}					t_map;

t_coord	***ft_get_coord(t_map *map);
void	ft_do_mlx(t_env *e);
void	ft_exit(char *s);
void	ft_free(t_map *map, t_env *e);

#endif
