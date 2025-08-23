/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:00:05 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/23 06:20:18 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "mlx/mlx.h"

# define WIDTH 500
# define HEIGHT 500

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_img_data
{
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img_data;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_mlx_data
{
	t_img_data	img;
	t_complex	z;
	double		x;
	double		y;
	double		zome;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*set;
	int			iters;
}	t_mlx_data;

double	ft_remap(double s, t_range sr, t_range dr);
double	ft_atof(const char *str);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

void	ft_fractol(t_mlx_data data);
void	ft_init(t_mlx_data *data, char *set);
void	ft_hook(t_mlx_data *data);
void	ft_destroy(t_mlx_data data);

#endif