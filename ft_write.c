/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:55:54 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/13 14:55:57 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	printnum(int n)
{
	ft_putnbr_fd(n, 1);
	return (1);
}

int	int_counter(int d)
{
	int i;

	i = 0;
	if (d < 0)
	{
		d *= -1;
		i++;
	}
	if (d == 0)
		i++;
	while (d != 0)
	{
		d /= 10;
		i++;
	}
	return (i);
}
