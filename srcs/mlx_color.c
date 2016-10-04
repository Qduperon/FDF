/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:34:40 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/04 15:25:55 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_mlx_pixel(t_env *e, int x, int y, unsigned int place)
{
	place = y * (WIDTH * 4);
	place += x * 4;
	if (place < ((WIDTH * HEIGHT) * (sizeof(char) * 4)))
	{
		if (e->inc->z1 == 0 && e->inc->z2 == 0 && e->inc->z3 == 0)
		{
			e->data[place] = e->colorpixel->b;
			e->data[place + 1] = e->colorpixel->g;
			e->data[place + 2] = e->colorpixel->r;
		}
		else if (e->inc->z1 <= 0 && e->inc->z2 <= 0 && e->inc->z3 <= 0)
		{
			e->data[place] = e->colorpixel->b2;
			e->data[place + 1] = e->colorpixel->g2;
			e->data[place + 2] = e->colorpixel->r2;
		}
		else
		{
			e->data[place] = e->colorpixel->b1;
			e->data[place + 1] = e->colorpixel->g1;
			e->data[place + 2] = e->colorpixel->r1;
		}
	}
}

void			ft_mlx_color(t_env *e, int x, int y)
{
	unsigned int	place;

	e->colorpixel = malloc(sizeof(t_color));
	place = y * (WIDTH * 4);
	place += x * 4;
	e->colorpixel->r = (e->color & 0xFF0000) >> 16;
	e->colorpixel->g = (e->color & 0xFF00) >> 8;
	e->colorpixel->b = (e->color & 0xFF);
	e->colorpixel->r1 = (e->color2 & 0xFF0000) >> 16;
	e->colorpixel->g1 = (e->color2 & 0xFF00) >> 8;
	e->colorpixel->b1 = (e->color2 & 0xFF);
	e->colorpixel->r2 = (e->color3 & 0xFF0000) >> 16;
	e->colorpixel->g2 = (e->color3 & 0xFF00) >> 8;
	e->colorpixel->b2 = (e->color3 & 0xFF);
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		ft_mlx_pixel(e, x, y, place);
}
