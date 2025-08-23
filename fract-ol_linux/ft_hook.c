/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:01:37 by zatalbi           #+#    #+#             */
/*   Updated: 2025/04/16 18:02:33 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_destroy_hook(t_mlx_data *data)
{
	ft_destroy(*data);
	exit(0);
}

static int	ft_key_press_hook(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
		ft_destroy_hook(data);
	if (key == XK_Up)
		data->y += 0.25 * data->zome;
	if (key == XK_Down)
		data->y -= 0.25 * data->zome;
	if (key == XK_Right)
		data->x += 0.25 * data->zome;
	if (key == XK_Left)
		data->x -= 0.25 * data->zome;
	if (key == XK_p && data->iters <= 500)
		data->iters += 5;
	if (key == XK_m && data->iters >= 25)
		data->iters -= 5;
	if (key == XK_Escape || key == XK_Up || key == XK_Down || key == XK_Right
		|| key == XK_Left || (key == XK_p && data->iters <= 500)
		|| (key == XK_m && data->iters >= 25))
		ft_fractol(*data);
	return (0);
}

static int	ft_button_press_hook(int button, int x, int y, t_mlx_data *data)
{
	(void)x;
	(void)y;
	if (button == Button4)
		data->zome *= 0.8;
	if (button == Button5)
		data->zome *= 1.25;
	if (button == Button4 || button == Button5)
		ft_fractol(*data);
	return (0);
}

void	ft_hook(t_mlx_data *data)
{
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask,
		ft_button_press_hook, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, ft_key_press_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, ft_destroy_hook, data);
}
