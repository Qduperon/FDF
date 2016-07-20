/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:10:06 by qduperon          #+#    #+#             */
/*   Updated: 2016/07/20 13:51:26 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(t_map *map, t_env *e)
{
	free(map);
	free(e);
}

void	ft_exit(char *s)
{
	ft_putstr("fdf: ");
	ft_putstr(s);
	exit(1);
}

int		ft_expose_hook(t_env *e)
{
	ft_draw(e);
	ft_display(e);
	return (0);
}
