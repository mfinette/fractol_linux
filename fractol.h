/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:44:14 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/17 13:36:04 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
// include <papier.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_zoom
{
	double	x;
	double	y;
}	t_zoom;

typedef struct s_complex
{
	double		r;
	double		i;
	t_data		img;
	t_vars		window;
	t_zoom		z;
	double		color;
	double		max;
	t_zoom		pos;
	double		definition;
	int			name;
	int			render;
	int			crazy;
}	t_complex;

typedef struct s_pixel
{
	t_complex	c;
	long		i;
}	t_pixel;

typedef struct s_thread
{
	t_complex	*c;
	pthread_t	thread;
	int			id;
}	t_thread;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

t_pixel	get_coordinates(double x, double y, t_complex *parameter);
long	iteration_nb_julia(t_complex z, t_complex *c);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		check_parameter(int argc, char **argv, t_complex *p);
long	iteration_nb_mandelbrot(t_complex z, t_complex *c);
long	iteration_nb_oscil(t_complex z, t_complex *c);
long	iteration_nb_julia(t_complex z, t_complex *c);
int		mouse_action(int keycode, int x, int y, t_complex *p);
void	select_theme(int keycode, t_complex *p);
void	select_fractal(int keycode, t_complex *p);
void	set_initial_parameters(t_complex *p);
void	modif_params(int keycode, t_complex *p);
int		hook_action(int keycode, t_complex *p);
void	render(t_complex *p);
void	render_fractal(t_thread *t);
int		ft_close(t_complex *p);

# define MAX_THREADS 8
# define W_WIDTH 500
# define W_HGT 500
# define MAX 30
# define PAD_6 65432
# define PAD_4 65430
# define PAD_8 65431
# define PAD_5 65437
# define PAD_7 65429
# define PAD_9 65434
# define RIGHT_A 65363
# define LEFT_A 65361
# define UP_A 65362
# define DOWN_A 65364
# define PAD_PLUS 65451
# define PAD_MINUS 65453
# define SPACE 32
# define K_J 106
# define K_M 109
# define K_C 99
# define K_P 112

# define ERROR "\033[31mINVALID PARAMETERS !!!!\e[0m\n\nCorrect usage is: ./fractol 'fractl_name' \
'graphical_mode' 'julia_real' 'julia_imaginary'\n\nFractals available : MANDELBROT ('m') \
|| JULIA ('j') || CREEPY('c')\n\nGraphical modes available : GRAPHIC ('g') || PERFORMANCE \
('p')\n\njulia parameters must be integers between 0 and 200 ;)\n"

#endif