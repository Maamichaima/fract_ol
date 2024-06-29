/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:20:42 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/29 13:59:55 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	reset(keycode, vars);
	colors(keycode, vars);
	draw(*vars);
	return (0);
}
