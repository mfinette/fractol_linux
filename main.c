/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:40:28 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/17 13:56:34 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_initial_parameters(t_complex *p)
{
	p->r = 1;
	p->i = 0;
	p->z.x = 200;
	p->z.y = 200;
	p->max = 30;
	p->pos.x = 0;
	p->pos.y = 0;
	p->render = 0;
}

int	ft_close(t_complex *p)
{
	mlx_clear_window(p->window.mlx, p->window.win);
	mlx_destroy_image(p->window.mlx, p->window.win);
	exit(0);
}

// int	find_keycode(int keycode, t_complex *p)
// {
// 	(void)p;
// 	printf("key = %d\n", keycode);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_complex	parameter;

	set_initial_parameters(&parameter);
	printf("cores = %d\n", MAX_THREADS);
	if (!check_parameter(argc, argv, &parameter))
		return (0);
	parameter.crazy = -1;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, W_WIDTH, W_HGT, "Fractol");
	img.img = mlx_new_image(mlx, W_WIDTH, W_HGT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	parameter.img = img;
	parameter.window.mlx = mlx;
	parameter.window.win = mlx_win;
	mlx_hook(mlx_win, ON_KEYDOWN, 1L << 0, hook_action, &parameter);
	mlx_hook(mlx_win, 17, 1L << 0, ft_close, &parameter);
	mlx_hook(mlx_win, ON_MOUSEDOWN, 1L << 0, mouse_action, &parameter);
	printf("coucou\n");
	mlx_loop(mlx);
}
