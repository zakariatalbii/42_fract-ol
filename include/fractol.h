/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:00:05 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/30 18:13:08 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# ifndef X11
#  define X11 11
# endif

# if X11
#  include <X11/X.h>
#  include <X11/Xlib.h>
#  include <X11/keysym.h>
# else
#  include <Carbon/Carbon.h>
# endif

# include "mlx.h"

# if X11
#  define K_ESC XK_Escape
#  define K_UP XK_Up
#  define K_DOWN XK_Down
#  define K_RIGHT XK_Right
#  define K_LEFT XK_Left
#  define K_P XK_p
#  define K_M XK_m
# else
#  define K_ESC kVK_Escape
#  define K_UP kVK_UpArrow
#  define K_DOWN kVK_DownArrow
#  define K_RIGHT kVK_RightArrow
#  define K_LEFT kVK_LeftArrow
#  define K_P kVK_ANSI_P
#  define K_M kVK_ANSI_M
#  define Button4 4
#  define Button5 5
# endif

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