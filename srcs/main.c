/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:18:45 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/23 15:12:10 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int		ft_shutdown(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit (1);
	return (0);
}

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
//	void	*img;
	int		x;
	int		y;
	int		z;
	int 	w;
	t_map	*map;
	t_env	*e;

	if (ac != 2 || ft_strstr(av[1], "dev") != 0)
		ft_exit("Usage : ./fdf <mapfile.fdf>");
	e = (t_env *)malloc(sizeof(t_env));
	map = (t_map *)malloc(sizeof(t_map));
	mlx = mlx_init();
	map->map = av;
	win = mlx_new_window(mlx, 400, 400, "test Qduperon");
	w = 0;
	while (w < 400)
	{
		z = 0;
		while (z < 400)
		{
			mlx_pixel_put(mlx, win, z, w, 0x00FF00FF);
			z = z + 40;
		}
		w = w + 1;
	}
	y = 0;
	while (y  < 399)
	{
		x = 0;
			while (x  < 399)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x = x + 1;
		}
		y = y + 40;
	}
	//img = mlx_new_image(mlx, x, y);
	//mlx_get_color_value(mlx, 0x00FF00FF);
	//mlx_put_image_to_window(mlx, win, img, x, y);
	mlx_key_hook(win, ft_shutdown, 0);
	mlx_loop(mlx);
	ft_free(map, e);
}
