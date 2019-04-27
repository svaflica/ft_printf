/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:51:07 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/27 15:53:50 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	prec_neg(int *size, intmax_t i, t_param list, int tmp)
{
	if (list.minus == 0 && list.zero == 0 && list.width - list.plus > tmp)
		*size += ft_print_symb(' ', list.width - list.plus - tmp);
	if (list.minus == 0 && list.zero == 1 && list.width - list.plus > tmp)
		*size += ft_print_symb('0', list.width - list.plus - tmp);
	ft_putnbr(i);
	if (list.minus == 1 && list.width - list.plus > tmp)
		*size += ft_print_symb(' ', list.width - list.plus - tmp);
}

static void	prec_pos(int *size, intmax_t i, t_param list, int tmp)
{
	if (list.minus == 0 && list.zero == 0 &&
		list.width - list.plus - list.precision > tmp)
		*size += ft_print_symb(' ',
						list.width - list.plus - list.precision - tmp);
	if (list.precision > tmp)
		*size += ft_print_symb('0', list.precision - tmp - list.plus);
	ft_putnbr(i);
	if (list.width > (list.precision + tmp))
		*size += ft_print_symb(' ', list.width - list.precision - tmp);
}

static int	ft_type_u(t_param list, intmax_t i)
{
	int size;

	size = ft_num_dig(i, 10);
	if (list.precision == -1)
		prec_neg(&size, i, list, size);
	else
		prec_pos(&size, i, list, size);
	return (size);
}

int			ft_u(t_param list, va_list ap)
{
	if (list.length == 0)
		return (ft_type_u(list, (unsigned int)va_arg(ap, int)));
	else if (list.length == 'l')
		(ft_type_u(list, (unsigned long)va_arg(ap, int)));
	else if (list.length == 'l' + 'l')
		(ft_type_u(list, (unsigned long long)va_arg(ap, int)));
	else if (list.length == 'h')
		(ft_type_u(list, (unsigned short)va_arg(ap, int)));
	else if (list.length == 'h' + 'h')
		(ft_type_u(list, (unsigned char)va_arg(ap, int)));
	return (0);
}
