/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:20:42 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/27 21:05:30 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	shifting(int keycode, t_fractol *vars)
{
	if (keycode == XK_Down)
	{
		vars->i_max -= vars->shift;
		vars->i_min -= vars->shift;
	}
	if (keycode == XK_Up)
	{
		vars->i_max += vars->shift;
		vars->i_min += vars->shift;
	}
	if (keycode == XK_Right)
	{
		vars->r_max -= vars->shift;
		vars->r_min -= vars->shift;
	}
	if (keycode == XK_Left)
	{
		vars->r_max += vars->shift;
		vars->r_min += vars->shift;
	}
}

void	etiration(int keycode, t_fractol *vars)
{
	if (vars->max < 200)
	{
		if (keycode == 78)
			vars->max += 5;
		if (keycode == 69)
			vars->max -= 5;
	}
}

void	reset(int keycode, t_fractol *vars)
{
	if (keycode == XK_space)
	{
		vars->i_max = 2;
		vars->i_min = -2;
		vars->r_max = 2;
		vars->r_min = -2;
		vars->c = 'o';
		vars->max = 0;
		vars->shift = 1.0;
	}
}

void	colors(int keycode, t_fractol *vars)
{
	if (keycode == XK_r)
		vars->c = 'r';
	if (keycode == XK_b)
		vars->c = 'b';
	if (keycode == XK_w)
		vars->c = 'w';
	if (keycode == XK_o)
		vars->c = 'o';
	if (keycode == XK_v)
		vars->c = 'v';
}

int	key_hook(int keycode, t_fractol *vars)
{
	if (keycode == XK_Escape)
	{
		ft_free(vars);
		exit(0);
	}
	mlx_clear_window(vars->mlx, vars->win);
	etiration(keycode, vars);
	shifting(keycode, vars);
	reset(keycode, vars);
	colors(keycode, vars);
	draw(*vars);
	return (0);
}
