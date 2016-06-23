/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:10:06 by qduperon          #+#    #+#             */
/*   Updated: 2016/06/23 18:34:00 by qduperon         ###   ########.fr       */
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
	ft_putendl("fdf: ");
	ft_putstr(s);
	exit(1);
}
