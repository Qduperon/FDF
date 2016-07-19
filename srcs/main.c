/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:18:45 by qduperon          #+#    #+#             */
/*   Updated: 2016/07/19 14:19:10 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{	
	t_map	*map;
	t_env	*e;

	if (ac != 2 || ft_strstr(av[1], "dev") != 0)
		ft_exit("Usage: ./fdf <mapfile.fdf>");
	e = (t_env *)malloc(sizeof(t_env));
	map = (t_map *)malloc(sizeof(t_map));
	e->off = XCENTER;
	e->off2 = YCENTER;
	e->zoom = 42;
	e->zh = 1;
	e->rot = 0;
	e->roty = M_PI / 2;
	map->av = av;
	e->coord = ft_get_coord(map);
	ft_do_mlx(e);
	ft_free(map, e);
	return (0);
}
