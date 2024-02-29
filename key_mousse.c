/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mousse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:10:08 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/29 13:59:58 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_mousse(int button, int x, int y, t_fractol *vars)
{
	double	zoom_x;
	double	zoom_y;

	zoom_x = vars->r_min + (x * (vars->r_max - vars->r_min) / 600);
	zoom_y = vars->i_min + (y * (vars->i_max - vars->i_min) / 600);
	if (button == 4)
	{
		vars->r_min /= 0.8;
		vars->r_max /= 0.8;
		vars->i_min /= 0.8;
		vars->i_max /= 0.8;
	}
	else if (button == 5)
	{
		vars->r_min *= 0.8;
		vars->r_max *= 0.8;
		vars->i_min *= 0.8;
		vars->i_max *= 0.8;
	}
	mlx_clear_window(vars->mlx, vars->win);
	draw(*vars);
	return (0);
}

int	close_window(t_fractol *vars)
{
	ft_free(vars);
	exit(0);
}
