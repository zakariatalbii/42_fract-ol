/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:01:37 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/30 14:05:24 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_remap(double s, t_range sr, t_range dr)
{
	return (((s - sr.min) * ((dr.max - dr.min) / (sr.max - sr.min))) + dr.min);
}

double	ft_atof(const char *str)
{
	long double	num;
	double		n;
	int			sign;

	sign = 1;
	num = 0.;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '+') - (*str == '-');
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10. + (double)(*str++ - 48);
	if (*str++ == '.')
	{
		n = 10.;
		while (*str >= '0' && *str <= '9')
		{
			num = num + (double)(*str++ - 48) / n;
			n *= 10.;
		}
	}
	return (num *= (double)sign, (double)num);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '+') - (*str == '-');
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && num > (num * 10 + (*str - 48)))
			return (-1);
		else if (sign == -1 && (-num) < ((-num) * 10 - (*str - 48)))
			return (0);
		num = num * 10 + (*str++ - 48);
	}
	num *= sign;
	return ((int)num);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	v;

	v = 0;
	while (v < n && s1[v] && s2[v] && s1[v] == s2[v])
		v++;
	if (v == n || (unsigned char)s1[v] == (unsigned char)s2[v])
		return (0);
	else if ((unsigned char)s1[v] > (unsigned char)s2[v])
		return (1);
	return (-1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	v;

	if (fd < 0 || !s)
		return ;
	v = 0;
	while (s[v])
		write(fd, &s[v++], 1);
}
