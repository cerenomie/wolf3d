/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <fteuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 14:48:13 by fteuber           #+#    #+#             */
/*   Updated: 2014/05/17 13:48:25 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "wolf3d.h"

void				put_column(t_env *e, float len, int color, int col)
{
	int		wall_height;
	int		i;

	i = 0;
	if (len > 1)
		wall_height = HEIGHT / (2 * len);
	else
		wall_height = HEIGHT / 2 + 1;
	col += WIDTH / 2;
	while (i < wall_height)
	{
		mlx_put_px_img(e, col, HEIGHT / 2 + i, color);
		mlx_put_px_img(e, col, HEIGHT / 2 - i, color);
		i++;
	}
}

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (s2 <= s1)
	{
		i = 0;
		while (i < n)
		{
			*((char *)s1 + i) = *((char *)s2 + i);
			i++;
		}
		return (s1);
	}
	return (NULL);
}

void				mlx_put_px_img(t_env *e, int x, int y, int px_color)
{
	char			*color;
	unsigned int	pixel_color;

	pixel_color = mlx_get_color_value(e->mlx, px_color);
	color = (char *)&pixel_color;
	e->data[x * (e->bpp / 8) + y * e->sizeline] = color[0];
	e->data[x * (e->bpp / 8) + y * e->sizeline + 1] = color[1];
	e->data[x * (e->bpp / 8) + y * e->sizeline + 2] = color[2];
}

void				map(int map[15][15])
{
	int	 hard[15][15];

	{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
	ft_memcpy(map, hard, 15 * 15 * 4);
}
