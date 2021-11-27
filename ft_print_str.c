/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:58:21 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/09 15:58:25 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	flag_zero(char *str, t_mod mods)
{
	if (mods.dot != 0 && mods.accuracy <= (int)ft_strlen(str))
	{
		while (mods.counter < mods.width - mods.accuracy)
			mods.counter += printchar(' ');
		while (mods.accuracy-- > 0)
			mods.counter += printchar(*str++);
	}
	else
	{
		if (mods.width > (int)ft_strlen(str))
			while (mods.counter < (int)(mods.width - ft_strlen(str)))
				mods.counter += printchar(' ');
		ft_putstr_fd(str, 1);
		mods.counter += ft_strlen(str);
	}
	return (mods.counter);
}

static int	flag_one(char *str, t_mod mods, int i)
{
	if (mods.dot != 0 && mods.accuracy <= (int)ft_strlen(str))
	{
		while (mods.accuracy-- > 0)
			ft_putchar_fd(str[mods.counter++], 1);
		while (mods.counter < mods.width)
			mods.counter += printchar(' ');
	}
	else
	{
		ft_putstr_fd(str, 1);
		mods.counter = ft_strlen(str);
		if (mods.width > (int)ft_strlen(str))
			while (i < mods.width - (int)ft_strlen(str))
				i += printchar(' ');
		mods.counter += i;
	}
	return (mods.counter);
}

int			is_string(char *str, t_mod mods)
{
	int i;

	i = 0;
	if (!str)
		str = "(null)";
	if (mods.flag == 0)
		mods.counter = flag_zero(str, mods);
	else if (mods.flag == 1)
		mods.counter = flag_one(str, mods, i);
	else if (mods.accuracy >= (int)ft_strlen(str) || (mods.width <= (int)
	ft_strlen(str) && mods.accuracy >= (int)ft_strlen(str)) || mods.width <=
	(int)ft_strlen(str))
	{
		ft_putstr_fd(str, 1);
		mods.counter = ft_strlen(str);
	}
	return (mods.counter);
}
