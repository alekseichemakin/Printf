/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:42:04 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/09 15:42:06 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_mod			init_mod(void)
{
	t_mod	mods;

	mods.dot = 0;
	mods.flag = 0;
	mods.star = 0;
	mods.width = 0;
	mods.accuracy = 0;
	mods.counter = 0;
	return (mods);
}

int				ft_printf(const char *input, ...)
{
	va_list	arg;
	t_mod	mods;
	int		counter;

	va_start(arg, input);
	counter = 0;
	mods = init_mod();
	counter = str_parser(input, mods, counter, arg);
	va_end(arg);
	return (counter);
}
