/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:21:22 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/13 15:21:25 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	flag_one(int n, t_mod mods)
{
	if (mods.accuracy <= mods.counter)
	{
		ft_putnbr_fd(n, 1);
		while (mods.width > mods.counter)
			mods.counter += printchar(' ');
	}
	else
	{
		while (mods.accuracy > mods.counter)
			mods.counter += printchar('0');
		ft_putnbr_fd(n, 1);
		while (mods.width > mods.counter)
			mods.counter += printchar(' ');
	}
	return (mods.counter);
}

static int	positive_num(t_mod mods, int i)
{
	if (mods.accuracy > mods.counter)
	{
		while (i < mods.width - mods.accuracy)
		{
			i += printchar(' ');
			mods.counter++;
		}
		while (mods.counter < mods.width || (mods.counter < mods.accuracy &&
		mods.width < mods.accuracy))
			mods.counter += printchar('0');
	}
	else
		while (mods.counter < mods.width)
			mods.counter += printchar(' ');
	return (mods.counter);
}

static int	flag_two(int n, t_mod mods, int i)
{
	if (mods.dot == 0)
		while (mods.counter < mods.width)
			mods.counter += printchar('0');
	else if (n >= 0)
		mods.counter = positive_num(mods, i);
	else if (n < 0)
	{
		if (mods.accuracy > mods.counter - 1)
		{
			n *= -1;
			while (i < mods.width - mods.accuracy - 1 && mods.counter++)
				i += printchar(' ');
			ft_putchar_fd('-', 1);
			while (mods.counter < mods.width || (mods.counter <= mods.accuracy
			&& mods.width <= mods.accuracy))
				mods.counter += printchar('0');
		}
		else
			while (mods.counter < mods.width)
				mods.counter += printchar(' ');
	}
	ft_putnbr_fd(n, 1);
	return (mods.counter);
}

static int	destributer(int n, t_mod mods, int minus)
{
	if (n < 0 && (mods.flag == 1 || (mods.flag == 2 && mods.dot == 0)))
	{
		n *= -1;
		minus += printchar('-');
		mods.counter--;
		mods.width--;
	}
	if (mods.flag == 1)
		mods.counter = flag_one(n, mods);
	else
		mods.counter = flag_two(n, mods, minus);
	return (mods.counter + minus);
}

int			is_int(int n, t_mod mods)
{
	int minus;

	minus = 0;
	mods.counter = int_counter(n);
	if (n == 0 && mods.dot == 1 && mods.accuracy == 0)
	{
		mods.counter = 0;
		while (mods.counter < mods.width)
			mods.counter += printchar(' ');
	}
	else if ((mods.dot == 0 && mods.flag == 0) || (mods.width <= mods.counter
	&& ((mods.accuracy <= mods.counter && n > 0) || (mods.accuracy
	<= mods.counter - 1 && n < 0))))
	{
		while (mods.counter < mods.width)
			mods.counter += printchar(' ');
		ft_putnbr_fd(n, 1);
	}
	else
		mods.counter = destributer(n, mods, minus);
	return (mods.counter);
}
