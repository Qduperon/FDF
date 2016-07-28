/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_octant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:35:00 by pmartine          #+#    #+#             */
/*   Updated: 2016/07/27 16:11:23 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_octant_1(t_box *b, t_env *e)
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
		if (i < 0)
		{
			b->y1++;
			i = i + dx;
		}
		b->x1++;
	}
}

void	ft_octant_2(t_box *b, t_env *e)
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
		if (i < 0)
		{
			b->x1++;
			i = i + dy;
		}
		b->y1++;
	}
}

void	ft_octant_3(t_box *b, t_env *e)
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
		if (i <= 0)
		{
			b->x1--;
			i = i + dy;
		}
		b->y1++;
	}
}

void	ft_octant_4(t_box *b, t_env *e)
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
		if (i >= 0)
		{
			b->y1++;
			i = i + dx;
		}
		b->x1--;
	}
}
