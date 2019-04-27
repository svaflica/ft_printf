/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:30:23 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/04/26 16:11:33 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int			ft_s(t_param list, char *s)
{
	int	tmp;
	int	size;

	size = 0;
	tmp = ft_strlen(s);
	if (list.width > 0 && list.width > tmp && list.precision == -1
						&& list.minus == 0 && list.zero == 0)
		size += ft_print_symb(' ', list.width - tmp);
	if (list.width > 0 && list.width > tmp && list.precision != -1
					&& list.minus == 0 && list.zero == 0 && tmp == 0)
		size += ft_print_symb(' ', list.width - tmp);
	if (list.width > 0 && list.width > tmp && list.precision != -1
						&& list.minus == 0 && list.zero == 0 && tmp != 0)
		size += ft_print_symb(' ', list.width - list.precision);
	if (list.width > 0 && list.width > tmp && list.minus == 0 && list.zero == 1)
		size += ft_print_symb('0', list.width - tmp);
	if (list.precision > -1)
		size += ft_putnstr(s, list.precision);
	else
	{
		ft_putstr(s);
		size += ft_strlen(s);
	}
	if (list.width > 0 && list.width > tmp && list.minus == 1 && list.precision == -1)
		size += ft_print_symb(' ', list.width - tmp);
	if (list.width > 0 && list.width > tmp && list.minus == 1 && list.precision != -1)
		size += ft_print_symb(' ', list.width - list.precision);
	return (size);
}
