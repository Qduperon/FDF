/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:15:35 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/27 17:01:35 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_up_y(t_map *map)
{
	map->y++;
	if (map->y == 1000000)
		ft_exit("no data found.");
}

static void		ft_get_map(t_map *map)
{
	int		i;
	int		fd;
	char	*line;
	
	i = 0;
	map->y = 0;
	if ((fd = open(map->av[1], O_RDONLY)) < 0)
		ft_exit("file cannot be read");
	while (get_next_line(fd, &line))
		ft_up_y(map);
	close(fd);
	fd = open(map->av[1], O_RDONLY);
	if ((map->map = (char **)malloc(sizeof(char *) * (map->y + 1))) == NULL)
		exit(0);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
			map->map[i++] = line;
		else
			map->y--;
	}
	free(line);
	close(fd);
}

t_coord			***ft_get_coord(t_map *map)
{
	t_coord		***coord;

	ft_get_map(map);
}
