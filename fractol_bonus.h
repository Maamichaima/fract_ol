/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:34:33 by cmaami            #+#    #+#             */
/*   Updated: 2024/02/27 21:06:16 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct s_fractol
{
	double			i_max;
	double			i_min;
	double			r_max;
	double			r_min;
	double			shift;
	double			cr;
	double			ci;
	void			*mlx;
	void			*win;
	char			*nom;
	void			*image;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			**argv;
	int				argc;
	int				max;
	char			c;
	int				red;
	int				blue;
	int				green;
}					t_fractol;

unsigned int		mandelbrot_color(t_fractol fractol, double i, double j);
unsigned int		julia_color(t_fractol fractol, double i, double j);
double				ft_atoi(char *str);
double				ft_atof(char *str);
void				inisialiser(t_fractol *fractol, char **str, int c);
void				julia(t_fractol fractol);
void				mandelbrot(t_fractol fractol);
void				my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void				buring_ship(t_fractol fractol);
unsigned int		buring_ship_color(t_fractol fractol, double cr, double ci);
void				put_error(void);
int					ft_strcmp(char *s1, char *s2);
unsigned int		rgba(char c, t_fractol *fractol);
int					key_hook(int keycode, t_fractol *vars);
int					key_mousse(int button, int x, int y, t_fractol *vars);
void				draw(t_fractol fractol);
void				ft_free(t_fractol *fractol);
int					close_window(t_fractol *vars);
int					ft_isdigit(int c);
int					check_double(char *str);

#endif