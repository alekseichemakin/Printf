/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:52:38 by mqueen            #+#    #+#             */
/*   Updated: 2020/12/09 16:52:41 by mqueen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_mod
{
	int			flag;
	int			width;
	int			dot;
	int			star;
	int			accuracy;
	int			counter;
}				t_mod;

int				ft_printf(const char *input, ...);
int				is_char(char c, t_mod mods);
int				is_int(int n, t_mod mods);
int				is_unsigned(unsigned int n, t_mod mods);
int				is_string(char *str, t_mod mods);
int				is_hex(unsigned int n, t_mod mods, int f);
int				is_pointer(long long unsigned int n, t_mod mods);
t_mod			flag_parser(char c, t_mod mods, va_list arg);
int				printchar(char c);
int				printnum(int n);
int				int_counter(int d);
t_mod			init_mod(void);
int				str_parser(const char *input, t_mod mods, int counter,
						va_list arg);

#endif
