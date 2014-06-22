/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <fteuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 11:50:28 by fteuber           #+#    #+#             */
/*   Updated: 2014/05/17 13:45:42 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void		up(t_env *e)
{
	e->y = e->y + MOVESPEED * cos(e->angle);
	if (e->map[(int)(round(e->x))] [(int)(round(e->y))] != 0)
		e->y = e->y - MOVESPEED * cos(e->angle);
	e->x = e->x - MOVESPEED * sin(e->angle);
	if (e->map[(int)(round(e->x))] [(int)(round(e->y))] != 0)
		e->x = e->x + MOVESPEED * sin(e->angle);
}

void		down(t_env *e)
{
	e->y = e->y - MOVESPEED * cos(e->angle);
	if (e->map[(int)(round(e->x))] [(int)(round(e->y))] != 0)
		e->y = e->y + MOVESPEED * cos(e->angle);
	e->x = e->x + MOVESPEED * sin(e->angle);
	if (e->map[(int)(round(e->x))] [(int)(round(e->y))] != 0)
		e->x = e->x - MOVESPEED * sin(e->angle);
}

int			key(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362 || keycode == 119)
		up(e);
	if (keycode == 65364 || keycode == 115)
		down(e);
	if (keycode == 65361 || keycode == 97)
		e->angle = e->angle + ((COEF_ROTATION * M_PI) / 180);
	if (keycode == 65363 || keycode == 100)
		e->angle = e->angle - ((COEF_ROTATION * M_PI) / 180);
	background(e);
	screen(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
