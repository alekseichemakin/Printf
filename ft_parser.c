/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:43:50 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/09 15:43:53 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	int		is_type(char input)
{
	if (input == 'c' || input == 's' || input == 'p' || input == 'd' ||
		input == 'i' || input == 'u' || input == 'x' || input == 'X' ||
		input == '%')
		return (1);
	return (0);
}

static int		what_type(char t, va_list arg, t_mod mods)
{
	if (t == 'c')
		mods.counter = is_char(va_arg(arg, int), mods);
	if (t == 's')
		mods.counter = is_string(va_arg(arg, char *), mods);
	if (t == 'p')
		mods.counter = is_pointer(va_arg(arg, long long unsigned int), mods);
	if (t == 'd' || t == 'i')
		mods.counter = is_int(va_arg(arg, int), mods);
	if (t == 'u')
		mods.counter = is_unsigned(va_arg(arg, unsigned int), mods);
	if (t == 'x' || t == 'X')
	{
		if (t == 'x')
			mods.counter = is_hex(va_arg(arg, unsigned int), mods, 0);
		else
			mods.counter = is_hex(va_arg(arg, unsigned int), mods, 32);
	}
	if (t == '%')
		mods.counter = is_char('%', mods);
	return (mods.counter);
}

static	t_mod	is_star(t_mod mods, va_list arg)
{
	if (mods.width == 0 && mods.dot == 0)
	{
		if ((mods.width = va_arg(arg, int)) < 0)
		{
			mods.width *= -1;
			mods.flag = 1;
		}
	}
	if (mods.dot == 1)
	{
		if ((mods.accuracy = va_arg(arg, int)) < 0)
		{
			mods.accuracy = 0;
			mods.dot = 0;
		}
	}
	return (mods);
}

t_mod			flag_parser(char c, t_mod mods, va_list arg)
{
	if (c == '0' && mods.width == 0 && mods.star == 0 && mods.dot == 0 &&
		(mods.flag == 0 || mods.flag == 2))
		mods.flag = 2;
	if (c == '-' && mods.width == 0 && mods.dot == 0 && mods.star == 0 &&
		(mods.flag == 0 || mods.flag == 1))
		mods.flag = 1;
	if (ft_isdigit(c) == 1 && mods.dot == 0)
		mods.width = (mods.width * 10) + (c - '0');
	if (c == '.' && mods.dot == 0)
		mods.dot = 1;
	if (ft_isdigit(c) == 1 && mods.dot == 1)
		mods.accuracy = (mods.accuracy * 10) + (c - '0');
	if (c == '*')
		mods = is_star(mods, arg);
	return (mods);
}

int				str_parser(const char *input, t_mod mods, int counter,
				va_list arg)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			if (input[i++ + 1] == '\0')
				return (-1);
			mods = init_mod();
			while (is_type(input[i]) == 0 && input[i])
			{
				if (ft_isalpha(input[i]) == 1)
					return (-1);
				mods = flag_parser(input[i++], mods, arg);
			}
			if (is_type(input[i]) == 1)
				counter += what_type(input[i++], arg, mods);
		}
		if (input[i] != '%' && input[i] != '\0')
			counter += printchar(input[i++]);
	}
	return (counter);
}
