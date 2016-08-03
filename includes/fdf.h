/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 13:45:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/07/28 18:01:52 by qduperon         ###   ########.fr       */
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

# define WIDTH	2000
# define HEIGHT	1000
# define XCENTER (WIDTH / 2)
# define YCENTER (HEIGHT / 2)
# define OFF 1.00
# define YOFF 1.00
# define CT1 0.5
# define CT2 0.5

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

# define XR1(x) (x * (cos(e->roty)))
# define XR2(x) (x * (cos((e->roty) + M_PI_2)))
# define YR1(y) (y * (sin(e->roty)) * (sin(e->rot)))
# define YR2(y) (y * (sin((e->roty) + M_PI_2)) * (sin(e->rot)))
# define XA CT1 * XR1 (e->inc->x1) + CT2 * XR2 (e->inc->y1)
# define YA2 (CT1 / 2 * YR1(e->inc->x1)) + CT2 / 2 * YR2 (e->inc->y1)
# define YA -((e->inc->z1) * sin((e->rot) + M_PI_2)) + YA2
# define XB CT1 * XR1 (e->inc->x2) + CT2 * XR2 (e->inc->y1)
# define YB2 CT1 / 2 * YR1 (e->inc->x2) + CT2 / 2 * YR2 (e->inc->y1)
# define YB -((e->inc->z2) * sin((e->rot) + M_PI_2)) + YB2
# define XC CT1 * XR1 (e->inc->x1) + CT2 * XR2 (e->inc->y2)
# define YC2 CT1 / 2 * YR1 (e->inc->x1) + CT2 / 2 * YR2 (e->inc->y2)
# define YC -((e->inc->z3) *sin ((e->rot) + M_PI_2)) +YC2

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

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	b1;
	unsigned char	g1;
	unsigned char	r1;
	unsigned char	b2;
	unsigned char	g2;
	unsigned char	r2;
}					t_color;

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
	t_color			*colorpixel;
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

int					ft_expose_hook(t_env *e);
t_coord				***ft_get_coord(t_map *map);
void				ft_crux(t_box *b, t_env *e);
void				ft_do_mlx(t_env *e);
void				ft_display(t_env *e);
void				ft_draw(t_env *e);
void				ft_exit(char *s);
void				ft_free(t_map *map, t_env *e);
void				ft_mlx_color(t_env *e, int x, int y);
void				ft_vect_ab(t_box *b, t_env *e);
void				ft_vect_crux(t_box *b, t_env *e);
void				ft_octant_1(t_box *b, t_env *e);
void				ft_octant_2(t_box *b, t_env *e);
void				ft_octant_3(t_box *b, t_env *e);
void				ft_octant_4(t_box *b, t_env *e);
void				ft_octant_5(t_box *b, t_env *e);
void				ft_octant_6(t_box *b, t_env *e);
void				ft_octant_7(t_box *b, t_env *e);
void				ft_octant_8(t_box *b, t_env *e);

#endif
