/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:53:27 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/30 18:35:34 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	minus_pos(int *size, char *i, t_param list, int tmp)
{
	int	tmp_2;

	tmp_2 = tmp;
	*i == '-' ? tmp_2 = tmp - 1 : 0;
	if (list.plus == 1 && *i != '-')
		*size += ft_print_symb('+', 1);
	if (*i == '-')
	{
		ft_putchar(*i);
		i++;
	}
	if (list.precision > tmp_2 && list.zero == 0)
		*size += ft_print_symb('0', list.precision - tmp_2);
	ft_putstr(i);
	if (list.width > list.precision && list.width > tmp && list.zero == 1)
		*size += ft_print_symb('0', list.width - list.space - list.plus -
				(list.precision > tmp_2 ? list.precision : tmp_2));
	if (list.width > list.precision && list.width > tmp)
		*size += ft_print_symb(' ', list.width - list.space - list.plus
		- (list.precision > tmp_2 ? list.precision + (tmp != tmp_2) : tmp));
}

static void	prec_neg(int *size, char *i, t_param list, int tmp)
{
	list.plus == 1 && *i != '-' ? tmp += 1 : 0;
	if (list.space == 1 && *i != '-')
		*size += ft_print_symb(' ', 1);
	if (list.minus == 0 && list.zero == 0 && list.width > tmp)
		*size += ft_print_symb(' ', list.width - tmp);
	list.plus == 1 && *i != '-' ? *size += ft_print_symb('+', 1) : 0;
	if (*i == '-')
	{
		ft_putchar(*i);
		i++;
	}
	if (list.minus == 0 && list.zero == 1 && list.width > tmp)
		*size += ft_print_symb('0', list.width - tmp);
	ft_putstr(i);
	if (list.minus == 1 && list.width > tmp)
		*size += ft_print_symb(' ', list.width - tmp);
}

static void	prec_pos(int *size, char *i, t_param list, int tmp)
{
	int		tmp_2;

	tmp_2 = tmp;
	*i == '-' ? tmp_2 = tmp - 1 : 0;
	*i == '0' && list.precision == 0 ? tmp -= 1 : 0;
	if ((list.space == 1 && *i == '-') ||
		(list.space == 1 && list.plus == 0))
		*size += ft_print_symb(' ', 1);
	if (list.width > list.precision && list.width > tmp)
		*size += ft_print_symb(' ', list.width - list.space - (list.plus ||
			*i == '-') - (list.precision > tmp_2 ? list.precision : tmp));
	if (list.plus == 1 && *i != '-')
		*size += ft_print_symb('+', 1);
	*i == '-' ? ft_putchar(*i) : 0;
	*i == '-' ? i++ : 0;
	if (list.width > list.precision && list.width > tmp && list.zero == 1)
		*size += ft_print_symb('0', list.width - list.space - (list.plus ||
			*i == '-') - (list.precision > tmp_2 ? list.precision : tmp_2));
	if (list.precision > tmp_2 && list.zero == 0)
		*size += ft_print_symb('0', list.precision - tmp_2);
	*i == '0' && list.precision == 0 ? *size = *size - 1 : ft_putstr(i);
}

static int	ft_type_d(t_param list, char *i)
{
	int size;

	size = ft_strlen(i);
	if (list.precision == -1)
		prec_neg(&size, i, list, size);
	else if (list.minus == 0)
		prec_pos(&size, i, list, size);
	else if (list.minus == 1)
		minus_pos(&size, i, list, size);
	return (size);
}

int			ft_d(t_param list, va_list ap)
{
	if (list.length == 0)
		return (ft_type_d(list, ft_itoa_base((int)va_arg(ap, int), 10)));
	else if (list.length == 'l')
		return (ft_type_d(list, ft_itoa_base((long)va_arg(ap, int), 10)));
	else if (list.length == 'l' + 'l')
		return (ft_type_d(list, ft_itoa_base((long long)va_arg(ap, int), 10)));
	else if (list.length == 'h')
		return (ft_type_d(list, ft_itoa_base((short)va_arg(ap, int), 10)));
	else if (list.length == 'h' + 'h')
		return (ft_type_d(list, ft_itoa_base((char)va_arg(ap, int), 10)));
	return (0);
}
