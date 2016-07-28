/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 16:02:43 by qduperon          #+#    #+#             */
/*   Updated: 2016/07/27 16:04:12 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vect_ab(t_box *b, t_env *e)
{
	int dx;
	int dy;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	if (dx == 0 || dy == 0)
		ft_crux(b, e);
	if (dx > 0 && dy > 0 && dx >= dy)
		ft_octant_1(b, e);
	if (dx > 0 && dy > 0 && dx < dy)
		ft_octant_2(b, e);
	if (dx < 0 && dy > 0 && -dx < dy)
		ft_octant_3(b, e);
	if (dx < 0 && dy > 0 && -dx >= dy)
		ft_octant_4(b, e);
	if (dx < 0 && dy < 0 && dx <= dy)
		ft_octant_5(b, e);
	if (dx < 0 && dy < 0 && dx > dy)
		ft_octant_6(b, e);
	if (dx > 0 && dy < 0 && dx < -dy)
		ft_octant_7(b, e);
	if (dx > 0 && dy < 0 && dx >= -dy)
		ft_octant_8(b, e);
}
