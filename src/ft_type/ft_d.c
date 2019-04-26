/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:44:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/26 13:15:21 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int		ft_space_before(t_param list, int i, int num_d)
{
	if (list.space == 1 && i >= 0)
	{
		ft_putchar(' ');
		num_d += 1;
	}
	if (list.precision != 0 && list.precision - num_d > 0)
	{
		(i < 0) ? num_d += ft_print_symb('-', 1) : 0;
		(i >= 0 && list.plus == 1) ? num_d += ft_print_symb('+', 1) : 0;
		num_d += ft_print_symb('0', list.precision - num_d);
	}
	else if (list.space == 1 && list.minus == 0 &&
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
	return (num_d);
}

int				ft_d(t_param list, int i)
{
	int size;
	int n_di;

	n_di = ft_num_dig(i, 10);
	(list.precision < 0) ? list.precision = 0 : list.precision;
	size = ft_space_before(list, i, n_di);
	size == n_di && list.plus == 1 && i >= 0 ? size += ft_print_symb('+', 1)
											: 0;
	ft_putnbr(i * (list.zero == 1 && list.width > 0 && i < 0 ? -1 : 1));
	if (list.minus == 1 && list.width > n_di + list.space +
		(list.plus == 1 || i < 0))
		size += ft_print_symb(' ', list.width - n_di - list.space -
				(list.plus == 1 || i < 0));
	// if (list.space == 1 && i >= 0)
	// 	ft_putchar(' ');
	// if (list.zero == 1 && list.width > 0)
	// {
	// 	(i < 0) ? ft_putchar('-') : NULL;
	// 	(i > 0 && list.plus == 1) ? ft_putchar('+') : NULL;
	// 	size += ft_print_symb('0', list.width - n_di - list.space -
	// 		(list.plus == 1 || i < 0));
	// }
	// else if (list.minus == 0 && list.width > n_di + list.space +
	// 		(list.plus == 1 || i < 0))
	// 	size += ft_print_symb(' ', list.width - n_di - list.space -
	// 		(list.plus == 1 || i < 0));
	// if (list.zero == 0 && list.plus == 1 && i >= 0)
	// 	ft_putchar('+');
	// ft_putnbr(i * (list.zero == 1 && list.width > 0 && i < 0 ? -1 : 1));
	// if (list.minus == 1 && list.width > n_di + list.space +
	// 	(list.plus == 1 || i < 0))
	// 	size += ft_print_symb(' ', list.width - n_di - list.space -
	// 		(list.plus == 1 || i < 0));
	return (size);
}
