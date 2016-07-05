/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:18:45 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/29 14:34:53 by qduperon         ###   ########.fr       */
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
	map->av = av;
	e->coord = ft_get_coord(map);
	ft_do_mlx(e);
	ft_free(map, e);
	return (0);
}
