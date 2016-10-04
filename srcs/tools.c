/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:10:06 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/04 15:26:10 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	ft_display(t_env *e)
{
	char	*commands;

	commands = "fleches : rotations";
	mlx_string_put(e->mlx, e->win, 5, 5, 0xFBFBFB, commands);
	commands = "souris : deplacer la map";
	mlx_string_put(e->mlx, e->win, 5, 20, 0xFBFBFB, commands);
	commands = "+/- : zoomer / dezoomer";
	mlx_string_put(e->mlx, e->win, 5, 35, 0xFBFBFB, commands);
	commands = "pageup/pagedown : +/- Z";
	mlx_string_put(e->mlx, e->win, 5, 50, 0xFBFBFB, commands);
	commands = "clear : reset";
	mlx_string_put(e->mlx, e->win, 5, 65, 0xFBFBFB, commands);
	commands = "echap : quitter";
	mlx_string_put(e->mlx, e->win, 5, 80, 0xFBFBFB, commands);
}
