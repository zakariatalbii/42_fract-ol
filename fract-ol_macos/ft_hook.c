/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:01:37 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/23 05:49:34 by zatalbi          ###   ########.fr       */
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
	if (key == kVK_Escape)
		ft_destroy_hook(data);
	if (key == kVK_UpArrow)
		data->y += 0.25 * data->zome;
	if (key == kVK_DownArrow)
		data->y -= 0.25 * data->zome;
	if (key == kVK_RightArrow)
		data->x += 0.25 * data->zome;
	if (key == kVK_LeftArrow)
		data->x -= 0.25 * data->zome;
	if (key == kVK_ANSI_P && data->iters <= 500)
		data->iters += 5;
	if (key == kVK_ANSI_M && data->iters >= 25)
		data->iters -= 5;
	if (key == kVK_Escape || key == kVK_UpArrow || key == kVK_DownArrow
		|| key == kVK_RightArrow || key == kVK_LeftArrow
		|| (key == kVK_ANSI_P && data->iters <= 500)
		|| (key == kVK_ANSI_M && data->iters >= 25))
		ft_fractol(*data);
	return (0);
}

static int	ft_button_press_hook(int button, int x, int y, t_mlx_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zome *= 0.8;
	if (button == 5)
		data->zome *= 1.25;
	if (button == 4 || button == 5)
		ft_fractol(*data);
	return (0);
}

void	ft_hook(t_mlx_data *data)
{
	mlx_hook(data->win_ptr, 4, 4,
		ft_button_press_hook, data);
	mlx_hook(data->win_ptr, 2, 2, ft_key_press_hook, data);
	mlx_hook(data->win_ptr, 17, 0, ft_destroy_hook, data);
}
