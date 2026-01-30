/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:01:37 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/30 13:26:42 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_iserror(void)
{
	ft_putstr_fd("Available Inputs:\n\n", 2);
	ft_putstr_fd("\t\"./fractol mandelbrot\"\t\t\tfor Mandelbrot set\n", 2);
	ft_putstr_fd("\t\"./fractol julia <rpart> <ipart>\"\tfor Julia set\n", 2);
	exit(1);
}

static int	ft_check(char *str)
{
	int	v;
	int	f;

	v = 0;
	f = 0;
	if (str[v] == '+' || str[v] == '-')
		v++;
	if (!(str[v] >= '0' && str[v] <= '9'))
		return (0);
	while (str[++v])
	{
		if (str[v] == '.')
		{
			f++;
			if (f > 1)
				return (0);
			continue ;
		}
		if (!(str[v] >= '0' && str[v] <= '9'))
			return (0);
	}
	if (!str[v] && str[v - 1] == '.')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11))
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 6))
		|| (argc != 2 && argc != 4))
		ft_iserror();
	data.set = argv[1];
	data.zome = 1.;
	data.x = 0.;
	data.y = 0.;
	data.iters = 50;
	if (!ft_strncmp(argv[1], "julia", 6))
	{
		if (!ft_check(argv[2]) || !ft_check(argv[3]))
			ft_iserror();
		data.z = (t_complex){ft_atof(argv[2]), ft_atof(argv[3])};
	}
	ft_init(&data, argv[1]);
	ft_hook(&data);
	ft_fractol(data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
