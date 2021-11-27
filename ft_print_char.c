/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:05:17 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/09 16:05:20 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	flag_two(char c, t_mod mods, int i)
{
	while (i < mods.width)
		i += printnum(0);
	ft_putchar_fd(c, 1);
	return (i);
}

int			is_char(char c, t_mod mods)
{
	int i;

	i = 1;
	if (mods.flag == 2)
		i = flag_two(c, mods, i);
	else if (mods.flag == 1 && mods.width != 0)
	{
		ft_putchar_fd(c, 1);
		while (i < mods.width)
			i += printchar(' ');
	}
	else if (mods.width != 0)
	{
		while (i < mods.width)
			i += printchar(' ');
		ft_putchar_fd(c, 1);
	}
	else
		ft_putchar_fd(c, 1);
	return (i);
}
