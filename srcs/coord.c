/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:15:35 by qduperon          #+#    #+#             */
/*   Updated: 2016/07/19 18:44:37 by qduperon         ###   ########.fr       */
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

static	t_coord	*ft_new_coord(int x, int y, int z, t_map *map)
{
	t_coord *coord;
	
	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	coord->size_x = (map->x);
	coord->size_y = (map->y);
	coord->z = z;
	coord->x = x - coord->size_x / 2;
	coord->y = y - map->y / 2;
	return (coord);
}

static void		ft_get(int i, int j, t_map *map, t_coord ***coord)
{
	while (++j < map->x)
	{
		if (map->tmp[j] && map->tmp[j][0] != '\n')
		{
			coord[i][j] = ft_new_coord(j, i, ft_atoi(map->tmp[j]), map);
			coord[i][j]->size_y = (map->y);
		}
	}
	free(map->tmp);
}

t_coord			***ft_get_coord(t_map *map)
{
	int			i;
	int			j;
	t_coord		***coord;

	i = 0;
	ft_get_map(map);
	if (!(coord = (t_coord ***)malloc(sizeof(t_coord **) * map->y + 1)))
		return (NULL);
	while (i < map->y)
	{
		map->tmp = ft_strsplit(map->map[i], ' ');
		map->x = 0;
		while (map->tmp[map->x])
			map->x++;
		j = -1;
		if (!(coord[i] = (t_coord **)malloc(sizeof(t_coord *) * (map->x + 1))))
			return (NULL);
		ft_get(i, j, map, coord);
		i++;
	}
	map->tmp = NULL;
	return (coord);
}
