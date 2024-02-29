/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:23:34 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/27 00:20:08 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	inisialiser(t_fractol *fractol, char **argv, int argc)
{
	fractol->i_max = 2;
	fractol->i_min = -2;
	fractol->r_max = 2;
	fractol->r_min = -2;
	fractol->nom = argv[1];
	fractol->argc = argc;
	fractol->argv = argv;
	fractol->max = 0;
	fractol->c = 'o';
	fractol->shift = 1.0;
}
