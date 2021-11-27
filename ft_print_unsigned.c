/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:23:30 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/09 16:23:32 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static unsigned int	num_len(unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void			ft_putunsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10);
		ft_putchar_fd((char)(n % 10 + '0'), 1);
	}
	else
		ft_putchar_fd((char)(n + '0'), 1);
}

static unsigned int	flag_two(unsigned int n, t_mod mods, unsigned int i,
							unsigned int d)
{
	if ((unsigned int)mods.accuracy <= i)
		while (i < (unsigned int)mods.width)
			i += printchar(' ');
	else
	{
		while (d < (unsigned int)(mods.width - mods.accuracy))
			d += printchar(' ');
		while (i < (unsigned int)mods.accuracy)
			i += printchar('0');
	}
	ft_putunsigned(n);
	return (i + d);
}

static unsigned int	flag_one(unsigned int n, t_mod mods, unsigned int i)
{
	if ((unsigned int)mods.accuracy <= i)
	{
		ft_putunsigned(n);
		while (i < (unsigned int)mods.width)
			i += printchar(' ');
	}
	else
	{
		while (i < (unsigned int)mods.accuracy)
			i += printchar('0');
		ft_putunsigned(n);
		while (i < (unsigned int)mods.width)
			i += printchar(' ');
	}
	return (i);
}

int					is_unsigned(unsigned int n, t_mod mods)
{
	unsigned int i;
	unsigned int d;

	d = 0;
	i = num_len(n);
	if (n == 0 && mods.dot == 1 && mods.accuracy == 0)
	{
		while ((int)d < mods.width)
			d += printchar(' ');
		return ((int)d);
	}
	if ((mods.dot == 0 && mods.flag == 0 && mods.width == 0) || ((unsigned
	int)mods.width <= i && (unsigned int)mods.accuracy <= i))
		d = 0;
	else if ((mods.flag == 2 && (unsigned int)mods.width > i && mods.dot ==
	0) || (mods.accuracy > mods.width))
		while (i < (unsigned int)mods.width || i < (unsigned int)mods.accuracy)
			i += printchar('0');
	else if ((mods.flag == 2) || (mods.width > (int)i && mods.flag == 0))
		return ((int)flag_two(n, mods, i, d));
	else if (mods.flag == 1)
		return ((int)flag_one(n, mods, i));
	ft_putunsigned(n);
	return ((int)i);
}
