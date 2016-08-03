/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:15:06 by qduperon          #+#    #+#             */
/*   Updated: 2016/08/03 14:38:20 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_loop_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	ft_draw(e);
	ft_display(e);
	return (0);
}

static void	ft_reset(t_env *r)
{
	r->zoom = 42;
	r->rot = 90;
	r->roty = -88;
	r->zh = -2;
}

static int	ft_mouse_hook(int button, int x, int y, t_env *m)
{
	if (button == 1)
	{
		m->off = x;
		m->off2 = y;
	}
	if (button == 2)
	{
		m->off = x;
		m->off2 = y;
	}
	ft_loop_hook(m);
	return (0);
}

static int	ft_key_hook(int keycode, t_env *e)
{
	if (keycode == ECHAP)
		exit(1);
	if (keycode == DEZOOM)
		e->zoom -= (e->zoom >= 3) ? 3 : 0;
	if (keycode == ZOOM)
		e->zoom += 3;
	if (keycode == Z_LESS)
		e->zh -= 1.5;
	if (keycode == Z_MORE)
		e->zh += 1.5;
	if (keycode == RESET)
		ft_reset(e);
	if (keycode == UP)
		e->rot += (5 * (M_PI / 180));
	if (keycode == DOWN)
		e->rot -= (5 * (M_PI / 180));
	if (keycode == RIGHT)
		e->roty += (5 * (M_PI / 90));
	if (keycode == LEFT)
		e->roty -= (5 * (M_PI / 90));
	ft_loop_hook(e);
	return (0);
}

void		ft_do_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	mlx_key_hook(e->win, ft_key_hook, e);
	e->bpp = 4;
	e->endian = 1;
	e->s_line = WIDTH;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	e->rot += 90;
	e->roty -= 90;
	e->zh -= 3;
	e->color = mlx_get_color_value(e->mlx, 0xFEFEFE);
	e->color2 = mlx_get_color_value(e->mlx, 0x8F723);
	e->color3 = mlx_get_color_value(e->mlx, 0xFF0921);
	mlx_hook(e->win, 2, 2, ft_key_hook, e);
	mlx_mouse_hook(e->win, ft_mouse_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
}
