/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:44:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/26 16:09:16 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int		ft_space_before(t_param list, int i, int num_d)
{
	if (list.space == 1 && i >= 0)
		num_d += ft_print_symb(' ', 1);
	if (list.precision > 0 && list.precision - num_d > 0)
	{
		(i < 0) ? num_d += ft_print_symb('-', 1) : 0;
		(i >= 0 && list.plus == 1) ? num_d += ft_print_symb('+', 1) : 0;
		num_d += ft_print_symb('0', list.precision - num_d);
	}
	else if (list.zero == 1 && list.minus == 0 &&
			list.width - num_d - (list.plus || i < 0) > 0)
	{
		(i < 0) ? num_d += ft_print_symb('-', 1) : 0;
		(i >= 0 && list.plus == 1) ? num_d += ft_print_symb('+', 1) : 0;
		num_d += ft_print_symb('0', list.width - num_d - (list.plus || i < 0));
	}
	else if (list.minus == 0 && list.width - num_d - (list.plus || i < 0) > 0)
	{
		num_d += ft_print_symb(' ', list.width - num_d - (list.plus || i < 0));
		(i < 0) ? num_d += ft_print_symb('-', 1) : 0;
		(i >= 0 && list.plus == 1) ? num_d += ft_print_symb('+', 1) : 0;
	}
	else if (i < 0)
		num_d += ft_print_symb('-', 1);
	return (num_d);
}

int				ft_d(t_param list, int i)
{
	int size;
	int n_di;

	n_di = ft_num_dig(i, 10);
	size = ft_space_before(list, i, n_di);
	i < 0 ? i *= (-1) : 1;
	ft_putnbr(i);
	if (list.minus == 1 && list.width > n_di + list.space +
		(list.plus == 1 || i < 0))
		size += ft_print_symb(' ', list.width - n_di - list.space -
				(list.plus == 1 || i < 0));
	return (size);
}
