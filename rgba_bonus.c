/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:38:59 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/27 21:05:48 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

unsigned int	rgba(char c, t_fractol *fractol)
{
	if (c == 'v')
	{
		fractol->blue = 2.55 * fractol->max;
		fractol->red = 2.55 * fractol->max;
	}
	if (c == 'w')
	{
		fractol->blue = 2.125 * fractol->max;
		fractol->red = 2.55 * fractol->max;
		fractol->green = 2.55 * fractol->max;
	}
	if (c == 'r')
		fractol->red = 2.55 * fractol->max;
	if (c == 'b')
	{
		fractol->blue = 2.55 * fractol->max;
		fractol->green = 2.55 * fractol->max;
	}
	if (c == 'o')
	{
		fractol->red = 2.55 * fractol->max;
		fractol->green = 1.65 * fractol->max;
	}
	return ((fractol->red << 16) | (fractol->green << 8) | fractol->blue);
}
