/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:25:18 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/09 13:25:21 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	flag_iscl(t_mod mods)
{
	if (mods.flag == 1)
	{
		ft_putstr_fd("0x", 1);
		while (mods.width >= mods.counter)
			mods.counter += printchar(' ');
	}
	else
	{
		while (mods.width >= mods.counter)
			mods.counter += printchar(' ');
		ft_putstr_fd("0x", 1);
	}
	mods.counter--;
	return (mods.counter);
}

static void	to_hex(long long unsigned int n)
{
	if (n >= 16)
	{
		to_hex(n / 16);
		if (n % 16 < 10)
			ft_putchar_fd((char)(n % 16 + '0'), 1);
		else
			ft_putchar_fd((char)(n % 16 + 87), 1);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((char)(n % 16 + '0'), 1);
		else
			ft_putchar_fd((char)(n % 16 + 87), 1);
	}
}

int			proc_flag(long long unsigned int n, t_mod mods, int i)
{
	if (mods.flag == 1)
	{
		ft_putstr_fd("0x", 1);
		to_hex(n);
		while (mods.width > i)
			i += printchar(' ');
	}
	else
	{
		while (mods.width > i)
			i += printchar(' ');
		ft_putstr_fd("0x", 1);
		to_hex(n);
	}
	return (i);
}

int			is_pointer(long long unsigned int n, t_mod mods)
{
	long long unsigned int	d;

	d = n;
	if (d == 0)
		mods.counter++;
	while (d != 0)
	{
		d /= 16;
		mods.counter++;
	}
	mods.counter += 2;
	if (mods.dot == 1 && n == 0)
		return (flag_iscl(mods));
	d = mods.counter;
	mods.counter = proc_flag(n, mods, (int)d);
	return (mods.counter);
}
