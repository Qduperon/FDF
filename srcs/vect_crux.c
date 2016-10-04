/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_crux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:40:08 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/04 15:26:39 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_crux_x(int x1, int y1, int x2, t_env *e)
{
	int	dx;

	dx = x2 - x1;
	if (dx > 0)
	{
		while (x1 != x2)
		{
			ft_mlx_color(e, x1, y1);
			x1++;
		}
	}
	else
	{
		while (x1 != x2)
		{
			ft_mlx_color(e, x1, y1);
			x1--;
		}
	}
}

static void	ft_crux_y(int x1, int y1, int y2, t_env *e)
{
	int dy;

	dy = y2 - y1;
	if (dy > 0)
	{
		while (y1 != y2)
		{
			ft_mlx_color(e, x1, y1);
			y1++;
		}
	}
	else
	{
		while (y1 != y2)
		{
			ft_mlx_color(e, x1, y1);
			y1--;
		}
	}
}

void		ft_crux(t_box *b, t_env *e)
{
	int dx;
	int	dy;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	if (dy == 0)
		ft_crux_x(b->x1, b->y1, b->x2, e);
	if (dx == 0)
		ft_crux_y(b->x1, b->y1, b->y2, e);
}
