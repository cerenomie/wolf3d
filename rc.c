/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <fteuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 11:50:54 by fteuber           #+#    #+#             */
/*   Updated: 2014/05/17 14:30:55 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		screen(t_env *e)
{
	int		col;
	float	len;

	col = -WIDTH / 2;
	while (col < (WIDTH / 2 + WIDTH % 2))
	{
		len = rc(col, e);
		put_column(e, len, manage_color(e, len), col);
		col++;
	}
}

float		rc(int col, t_env *e)
{
	float	len;
	float	t;

	t = FOV * M_PI * (-col) / (WIDTH * 180);
	e->j = e->x;
	e->k = e->y;
	eyes(&e, RAY_FAST, t);
	while (e->map[(int)(round(e->j))] [(int)(round(e->k))] == 0)
	{
		e->k = e->k + RAY_ACCURACY * cos(e->angle + t);
		wall_orientation(e, e->j, e->k, 0);
		e->j = e->j + RAY_ACCURACY * sin(e->angle + t);
		wall_orientation(e, e->j, e->k, 1);
	}
	len = sqrt(pow(e->k - e->y, 2) + pow(e->j - e->x, 2));
	return (len * cos(t));
}

int			eyes(t_env **e, float a, float t)
{
	if (a < RAY_ACCURACY)
		return (0);
	while ((*e)->map[(int)(round((*e)->j))] [(int)(round((*e)->k))] == 0)
	{
		(*e)->k = (*e)->k + a * cos((*e)->angle + t);
		(*e)->j = (*e)->j - a * sin((*e)->angle + t);
	}
	(*e)->k = (*e)->k - a * cos((*e)->angle + t);
	(*e)->j = (*e)->j + a * sin((*e)->angle + t);
	return (eyes(e, a / 2, t));
}
