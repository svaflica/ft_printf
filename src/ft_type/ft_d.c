/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:53:27 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/28 17:53:48 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	prec_neg(int *size, intmax_t i, t_param list, int tmp)
{
	if (i < 0 || list.plus == 1)
		tmp += 1;
	if (list.space == 1 && i > -1)
		*size += ft_print_symb(' ', 1);
	if (list.minus == 0 && list.zero == 0 && list.width > tmp)
		*size += ft_print_symb(' ', list.width - tmp);
	list.plus == 1 && i >= 0 ? *size += ft_print_symb('+', 1) : 0;
	if (i < 0)
	{
		*size += ft_print_symb('-', 1);
		i *= -1;
	}
	if (list.minus == 0 && list.zero == 1 && list.width > tmp)
		*size += ft_print_symb('0', list.width - tmp);
	ft_putnbr(i);
	if (list.minus == 1 && list.width > tmp)
		*size += ft_print_symb(' ', list.width - tmp);
}

static void	prec_pos(int *size, intmax_t i, t_param list, int tmp)
{
	if (i < 0 || list.plus == 1)
		tmp += 1;
	if (list.minus == 0 && list.zero == 0 && list.width - list.precision > tmp)
		*size += ft_print_symb(' ', list.width - list.precision);
	list.plus == 1 && i >= 0 ? *size += ft_print_symb('+', 1) : 0;
	if (i < 0)
	{
		*size += ft_print_symb('-', 1);
		i *= -1;
	}
	if (list.precision > tmp)
		*size += ft_print_symb('0', list.precision - tmp);
	ft_putnbr(i);
	if (list.minus == 1 && list.width - list.precision > tmp)
		*size += ft_print_symb(' ', list.width - list.precision);
}

// static void	prec_pos(int *size, intmax_t i, t_param list, int tmp)
// {
// 	if (list.minus == 0 && list.zero == 0 &&
// 		list.width - list.plus - list.precision > tmp)
// 		*size += ft_print_symb(' ',
// 						list.width - list.plus - list.precision - tmp);
// 	list.plus == 1 && i >= 0 ? *size += ft_print_symb('+', 1) : 0;
// 	if (i < 0)
// 	{
// 		*size += ft_print_symb('-', 1);
// 		i *= -1;
// 	}
// 	if (list.precision > tmp)
// 		*size += ft_print_symb('0', list.precision - tmp - list.plus);
// 	ft_putnbr(i);
// 	if (list.width > (list.precision + tmp))
// 		*size += ft_print_symb(' ', list.width - list.precision - tmp);
// }

static int	ft_type_d(t_param list, intmax_t i)
{
	int size;

	size = ft_num_dig(i, 10);
	if (list.precision == -1)
		prec_neg(&size, i, list, size);
	else
		prec_pos(&size, i, list, size);
	return (size);
}

int			ft_d(t_param list, va_list ap)
{
	if (list.length == 0)
		return (ft_type_d(list, (int)va_arg(ap, int)));
	else if (list.length == 'l')
		(ft_type_d(list, (long)va_arg(ap, int)));
	else if (list.length == 'l' + 'l')
		(ft_type_d(list, (long long)va_arg(ap, int)));
	else if (list.length == 'h')
		(ft_type_d(list, (short)va_arg(ap, int)));
	else if (list.length == 'h' + 'h')
		(ft_type_d(list, (char)va_arg(ap, int)));
	return (0);
}
