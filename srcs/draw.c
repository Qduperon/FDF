/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 15:14:44 by qduperon          #+#    #+#             */
/*   Updated: 2016/07/26 18:54:46 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_calc_pixel(t_env *e, int i, int j)
{
	if (i < e->coord[0][0]->size_y - 1 && j < e->coord[i + 1][0]->size_x)
		e->inc->z3 = e->coord[i + 0][j]->z;
	else
		e->inc->z3 = e->coord[i][j]->z;
	if (i < e->coord[0][0]->size_y - 1 && j < e->coord[i + 1][0]->size_x)
		e->inc->y2 = (e->coord[i + 0][j]->y * e->zoom);
	else
		e->inc->y2 = (e->coord[i][j]->y * e->zoom);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->x2 = (e->coord[i][j + 1]->x * e->zoom);
	else
		e->inc->x2 = (e->coord[i][j]->x * e->zoom);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->z2 = e->coord[i][j + 1]->z;
	else
		e->inc->z2 = e->coord[i][j]->z;
	e->inc->z1 = e->coord[i][j]->z * e->zh;
	e->inc->x1 = (e->coord[i][j]->x * e->zoom);
	e->inc->y1 = (e->coord[i][j]->y * e->zoom);
	e->inc->z2 *= e->zh;
	e->inc->z3 *= e->zh;
}

static void		ft_put_pixel(t_env *e, int i, int j)
{
	ft_calc_pixel(e, i, j);
	e->box->x1 = XA + OFF * e->off;
	e->box->y1 = YA + YOFF * e->off2;
	e->box->x2 = XB + OFF * e->off;
	e->box->y2 = YB + YOFF * e->off2;
	e->inc->z3 = 0;
	ft_vect_ab(e->box, e);
	if (e->coord[0][0]->size_y > 1)
	{
		ft_calc_pixel(e, i, j);
		e->box->x1 = XA + OFF * e->off;
		e->box->y1 = YA + YOFF * e->off2;
		e->box->x2 = XB + OFF * e->off;
		e->box->y2 = YB + YOFF * e->off2;
		e->inc->z2 = 0;
		ft_vect_ab(e->box, e);
	}
}

void			ft_draw(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(e->inc = malloc(sizeof(t_inc))))
		exit(0);
	if (!(e->box = malloc(sizeof(t_box))))
		exit(0);
	while (i < e->coord[0][0]->size_y)
	{
		j = 0;
		while (j < e->coord[i][0]->size_x)
		{
			if (i >= 0 && i <= WIDTH && j >= 0 && j <= HEIGHT)
				ft_put_pixel(e, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
