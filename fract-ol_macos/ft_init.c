/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:59:28 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/23 05:54:10 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_destroy(t_mlx_data data)
{
	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}

void	ft_init(t_mlx_data *data, char *set)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, set);
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		exit(1);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img.img_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	data->img.data_addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	if (!data->img.img_ptr)
	{
		ft_destroy(*data);
		exit(1);
	}
}
