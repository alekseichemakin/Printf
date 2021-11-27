/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:11:58 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/08 16:12:02 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	to_hex(unsigned int n, int f)
{
	if (n >= 16)
	{
		to_hex(n / 16, f);
		if (n % 16 < 10)
			ft_putchar_fd((char)(n % 16 + '0'), 1);
		else
			ft_putchar_fd((char)(n % 16 + 87 - f), 1);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((char)(n % 16 + '0'), 1);
		else
			ft_putchar_fd((char)(n % 16 + 87 - f), 1);
	}
}

int			print_flag_two(unsigned int n, t_mod mods, int i, int f)
{
	if (mods.flag == 2 && mods.width > i && mods.dot == 0)
		while (mods.width > i)
			i += printchar('0');
	else
	{
		while ((mods.width > mods.accuracy && mods.dot == 1 && mods.counter <
		mods.accuracy) || (mods.width > i && (mods.dot == 0 || mods.accuracy
		<= mods.counter)))
		{
			i += printchar(' ');
			if (mods.dot == 1 && mods.counter < mods.accuracy)
				mods.width--;
		}
		while (mods.accuracy > mods.counter)
		{
			mods.counter += printchar('0');
			i++;
		}
	}
	to_hex(n, f);
	return (i);
}

int			print_hex(unsigned int n, t_mod mods, int i, int f)
{
	if (mods.accuracy <= i && mods.width <= i)
		to_hex(n, f);
	else if (mods.flag == 1)
	{
		while (mods.accuracy > i)
			i += printchar('0');
		to_hex(n, f);
		while (mods.width > i)
			i += printchar(' ');
	}
	else
		i = print_flag_two(n, mods, i, f);
	return (i);
}

int			is_hex(unsigned int n, t_mod mods, int f)
{
	unsigned int	d;
	int				i;

	d = n;
	if (n == 0 && mods.dot == 1 && mods.accuracy == 0)
	{
		while ((int)d < mods.width)
			d += printchar(' ');
		return ((int)d);
	}
	if (d == 0)
		mods.counter++;
	while (d != 0)
	{
		d /= 16;
		mods.counter++;
	}
	i = mods.counter;
	mods.counter = print_hex(n, mods, i, f);
	return (mods.counter);
}
