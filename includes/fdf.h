/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 13:45:13 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/21 13:48:14 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./../libft/includes/libft.h"
# include "./../minilibx_macos/mlx.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_env;

typedef struct	s_map
{
	char		**map;
}				t_map;

#endif
