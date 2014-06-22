/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <fteuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 11:49:50 by fteuber           #+#    #+#             */
/*   Updated: 2014/05/17 13:44:55 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			wall_orientation(t_env *e, float x, float y, int c)
{
	static int	key;

	if (c == 0)
		key = 0;
	if (e->map[(int)(round(x))] [(int)(round(y))] == 1 && c == 0)
	{
		if (y < round(y))
			e->color_c = 1;
		else
			e->color_c = 2;
		key = 1;
	}
	if (e->map[(int)(round(x))] [(int)(round(y))] == 1 && c == 1 && key == 0)
	{
		if (x < round(x))
			e->color_c = 3;
		else
			e->color_c = 4;
	}
}

int				manage_color(t_env *e, float len)
{
	if (e->color_c == 1)
		return (color(255, 203, 96, len));
	if (e->color_c == 2)
		return (color(255, 127, 0, len));
	if (e->color_c == 3)
		return (color(255, 90, 90, len));
	if (e->color_c == 4)
		return (color(253, 241, 184, len));
	return (0);
}

void			background(t_env *e)
{
	int			x;
	float		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			mlx_put_px_img(e, x, y, color(119, 181, 254, y / 25));
			y++;
		}
		x++;
	}
	x = -1;
	while (x++ < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
		{
			mlx_put_px_img(e, x, y,
					color(84, 249, 141, WIDTH * 9 / (2 * y)));
			y++;
		}
	}
}

int				color(int r, int v, int b, float len)
{
	t_color	c;

	c.r = r - (r * len * COEF_DARK) / 256;
	c.v = v - (v * len * COEF_DARK) / 256;
	c.b = b - (b * len * COEF_DARK) / 256;
	return ((c.r * 256 * 256) + (c.v * 256) + c.b);
}
