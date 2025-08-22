/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:04:44 by zatalbi           #+#    #+#             */
/*   Updated: 2025/04/16 18:23:24 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_putpix(char *data_addr, int color)
{
	static int	offset;

	if (!data_addr)
	{
		offset = 0;
		return ;
	}
	*(int *)(data_addr + offset) = color;
	offset += sizeof(int);
}

static void	ft_mandelbrot(t_mlx_data data, int x, int y)
{
	t_range		sr;
	t_range		dr;
	t_complex	z;
	t_complex	c;
	int			v;

	v = 0;
	z = (t_complex){0, 0};
	sr = (t_range){0, WIDTH};
	dr = (t_range){(-2 * data.zome) + data.x, (2 * data.zome) + data.x};
	c.r = ft_remap(x, sr, dr);
	sr = (t_range){0, HEIGHT};
	dr = (t_range){(2 * data.zome) + data.y, (-2 * data.zome) + data.y};
	c.i = ft_remap(y, sr, dr);
	while ((z.r * z.r) + (z.i * z.i) < 4 && ++v < data.iters)
		z = (t_complex){(z.r * z.r) - (z.i * z.i) + c.r, (2 * z.r * z.i) + c.i};
	sr = (t_range){1, data.iters};
	dr = (t_range){0x000000, 0xffffff};
	ft_putpix(data.img.data_addr, ft_remap(v, sr, dr));
}

static void	ft_julia(t_mlx_data data, int x, int y, t_complex	c)
{
	t_range		sr;
	t_range		dr;
	t_complex	z;
	int			v;

	v = 0;
	sr = (t_range){0, WIDTH};
	dr = (t_range){(-2 * data.zome) + data.x, (2 * data.zome) + data.x};
	z.r = ft_remap(x, sr, dr);
	sr = (t_range){0, HEIGHT};
	dr = (t_range){(2 * data.zome) + data.y, (-2 * data.zome) + data.y};
	z.i = ft_remap(y, sr, dr);
	while ((z.r * z.r) + (z.i * z.i) < 4 && ++v < data.iters)
		z = (t_complex){(z.r * z.r) - (z.i * z.i) + c.r, (2 * z.r * z.i) + c.i};
	sr = (t_range){0, data.iters};
	dr = (t_range){0x000000, 0xffffff};
	ft_putpix(data.img.data_addr, ft_remap(v, sr, dr));
}

void	ft_fractol(t_mlx_data data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strncmp(data.set, "mandelbrot", 11))
				ft_mandelbrot(data, x, y);
			else
				ft_julia(data, x, y, data.z);
			x++;
		}
		y++;
	}
	ft_putpix(0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
}
