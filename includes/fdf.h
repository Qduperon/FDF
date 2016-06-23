/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 13:45:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/23 18:34:54 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./../libft/includes/libft.h"
# include "./../minilibx_macos/mlx.h"
# include <stdio.h>

# define WIDTH 1500
# define HEIGHT	750

typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
}				t_coord;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	t_coord		***coord;
}				t_env;

typedef struct	s_map
{
	char		**av;
	char		**map;
	int			x;
	int			y;
}				t_map;

void	ft_exit(char *s);
void	ft_free(t_map *map, t_env *e);

#endif
