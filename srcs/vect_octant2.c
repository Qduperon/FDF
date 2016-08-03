/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_octant2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 16:07:51 by qduperon          #+#    #+#             */
/*   Updated: 2016/07/27 16:11:53 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_octant_5(t_box *b, t_env *e)
{
	int dx;
	int dy;
	int i;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	i = dx;
	dx = i * 2;
	dy = dy * 2;
	while (b->x1 != b->x2)
	{
		ft_mlx_color(e, b->x1, b->y1);
		i = i - dy;
		if (i >= 0)
		{
			b->y1--;
			i = i + dx;
		}
		b->x1--;
	}
}

void	ft_octant_6(t_box *b, t_env *e)
{
	int dx;
	int dy;
	int i;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	i = dy;
	dy = i * 2;
	dx = dx * 2;
	while (b->y1 != b->y2)
	{
		ft_mlx_color(e, b->x1, b->y1);
		i = i - dx;
		if (i >= 0)
		{
			b->x1--;
			i = i + dy;
		}
		b->y1--;
	}
}

void	ft_octant_7(t_box *b, t_env *e)
{
	int dx;
	int dy;
	int i;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	i = dy;
	dy = i * 2;
	dx = dx * 2;
	while (b->y1 != b->y2)
	{
		ft_mlx_color(e, b->x1, b->y1);
		i = i + dx;
		if (i > 0)
		{
			b->x1++;
			i = i + dy;
		}
		b->y1--;
	}
}

void	ft_octant_8(t_box *b, t_env *e)
{
	int dx;
	int dy;
	int i;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	i = dx;
	dx = i * 2;
	dy = dy * 2;
	while (b->x1 != b->x2)
	{
		ft_mlx_color(e, b->x1, b->y1);
		i = i + dy;
		if (i < 0)
		{
			b->y1--;
			i = i + dx;
		}
		b->x1++;
	}
}