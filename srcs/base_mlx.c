/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:15:06 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/29 14:38:49 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_key_hook(int keycode, t_env *e)
{
	if (keycode == ECHAP)
		exit(1);
}

void		ft_do_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	mlx_key_hook(e->win, ft_key_hook, e);
}
