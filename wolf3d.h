/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <fteuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 11:37:01 by fteuber           #+#    #+#             */
/*   Updated: 2014/05/10 15:51:14 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define	WIDTH	 900
# define	HEIGHT	 500
# define	WALL_HEIGHT	40
# define	FOV	 60
# define	MOVESPEED	1
# define	RAY_ACCURACY	0.001
# define	RAY_FAST	0.05
# define	COEF_ROTATION	4
# define	COEF_DARK	15

typedef struct	 s_env
{
	void	        *mlx;
	void            *win;
	void            *img;
	char            *data;
	int             endian;
	int             bpp;
	int             sizeline;
	float           x;
	float           y;
	float           j;
	float           k;
	float           angle;
	int             color_c;
	int             map[15][15];
}                   t_env;

typedef struct       s_color
{
	int             r;
	int             v;
	int             b;
}                   t_color;

void                wall_orientation(t_env *e, float x, float y, int c);
int                 manage_color(t_env *e, float len);
void                background(t_env *e);
int                 color(int r, int v, int b, float len);

int                 expose_hook(t_env *e);
void                up(t_env *e);
void                down(t_env *e);
int                 key(int key, t_env *e);

void                put_column(t_env *e, float len, int color, int col);
void                mlx_put_col_img(t_env *e, float len, int color, int col);
void                mlx_put_px_img(t_env *e, int x, int y, int px_color);
void                map(int map[15][15]);

void                screen(t_env *e);
float               rc(int col, t_env *e);
int                 eyes(t_env **e, float a, float t);

#endif
