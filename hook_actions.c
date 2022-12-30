/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:19:11 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/17 13:38:58 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


# define K_1 49
# define K_2 50
# define K_3 51
# define K_4 52
# define K_5 53
# define K_6 54
# define K_7 55
# define K_8 56
# define K_9 57
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

int	mouse_action(int keycode, int x, int y, t_complex *p)
{
	double	mouse_x_pos;
	double	mouse_y_pos;

	printf("mouse code = %d\n", keycode);
	mouse_x_pos = (x - W_WIDTH / 2) / p->z.x;
	mouse_y_pos = (y - W_HGT / 2) / p->z.y;
	if (keycode == 4)
	{
		p->pos.x += 0.174 * mouse_x_pos;
		p->pos.y += 0.174 * mouse_y_pos;
		p->z.x *= 1.2;
		p->z.y *= 1.2;
		p->max += 0.5;
	}
	if (keycode == 2)
	{
		while (p->z.x > 200)
			mouse_action(5, x, y, p);
	}
	if (keycode == 5)
	{
		p->pos.x -= 0.174 * mouse_x_pos;
		p->pos.y -= 0.174 * mouse_y_pos;
		p->max -= 0.5;
		p->z.x /= 1.2;
		p->z.y /= 1.2;
	}
	render(p);
	return (0);
}

void	select_theme(int keycode, t_complex *p)
{
	if (keycode == K_1)
	{
		if (p->color == 330000)
			p->color = 330500;
		else if (p->color == 330500)
			p->color = 328200;
		else if (p->color == 328200)
			p->color = 327700;
		else
			p->color = 330000;
	}
	if (keycode == K_2)
		p->color = 1770000;
	if (keycode == K_3)
		p->color = 1640000;
	if (keycode == K_4)
			p->color = 1639946;
	if (keycode == K_8)
		p->color = 4780000;
	if (keycode == K_6)
		p->color = 4850000;
	if (keycode == K_7)
		p->color = 15270000;
}

void	select_fractal(int keycode, t_complex *p)
{
	if (keycode == K_J)
	{
		p->name = 0;
		set_initial_parameters(p);
	}
	if (keycode == K_C)
	{
		p->name = 1;
		set_initial_parameters(p);
	}	
	if (keycode == K_M)
	{
		p->name = 10;
		set_initial_parameters(p);
	}	
}

void	modif_params(int keycode, t_complex *p)
{
	if (keycode == PAD_6)
		p->pos.x += 20 / p->z.x;
	if (keycode == PAD_4)
		p->pos.x -= 20 / p->z.x;
	if (keycode == PAD_8)
		p->pos.y -= 20 / p->z.x;
	if (keycode == PAD_5)
		p->pos.y += 20 / p->z.x;
	if (keycode == RIGHT_A)
		p->r += 0.01 * p->name;
	if (keycode == LEFT_A)
		p->r -= 0.01 * p->name;
	if (keycode == UP_A)
		p->i += 0.01 * p->name;
	if (keycode == DOWN_A)
		p->i -= 0.01 * p->name;
	if (keycode == PAD_7)
		p->color -= 1;
	if (keycode == PAD_9)
		p->color += 1;
	if (keycode == SPACE)
		set_initial_parameters(p);
	if (keycode == 65435)
	{
		p->z.x *= 1.2;
		p->z.y *= 1.2;
		p->max += 0.5;
	}
	if (keycode == 65436)
	{
		p->z.x /= 1.2;
		p->z.y /= 1.2;
		p->max -= 0.5;
	}		
	if (keycode == 112)
		p->crazy *= -1;
}

int	hook_action(int keycode, t_complex *p)
{
	printf("keycode = %d\n", keycode);
	if (keycode == PAD_PLUS)
		p->max += 0.5;
	if (keycode == PAD_MINUS)
		p->max -= 0.5;
	if (keycode == 65307)
		ft_close(p);
	select_fractal(keycode, p);
	select_theme(keycode, p);
	modif_params(keycode, p);
	render(p);
	return (0);
}
