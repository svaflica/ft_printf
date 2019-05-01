/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:51:07 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 17:02:09 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

// static void	prec_neg(int *size, char *i, t_param list, int tmp)
// {
// 	if (list.minus == 0 && list.zero == 0 && list.width - list.plus > tmp)
// 		*size += ft_print_symb(' ', list.width - list.plus - tmp);
// 	if (list.minus == 0 && list.zero == 1 && list.width - list.plus > tmp)
// 		*size += ft_print_symb('0', list.width - list.plus - tmp);
// 	ft_putstr(i);
// 	if (list.minus == 1 && list.width - list.plus > tmp)
// 		*size += ft_print_symb(' ', list.width - list.plus - tmp);
// }

// static void	prec_pos(int *size, char *i, t_param list, int tmp)
// {
// 	if (list.minus == 0 && list.zero == 0 &&
// 		list.width - list.plus - list.precision > tmp)
// 		*size += ft_print_symb(' ',
// 						list.width - list.plus - list.precision - tmp);
// 	if (list.precision > tmp)
// 		*size += ft_print_symb('0', list.precision - tmp - list.plus);
// 	ft_putstr(i);
// 	if (list.width > (list.precision + tmp))
// 		*size += ft_print_symb(' ', list.width - list.precision - tmp);
// }

// static int	ft_type_u(t_param list, char *i)
// {
// 	int size;

// 	size = ft_strlen(i);
// 	if (list.precision == -1)
// 		prec_neg(&size, i, list, size);
// 	else
// 		prec_pos(&size, i, list, size);
// 	free(i);
// 	return (size);
// }

static void	minus_pos(int *size, char *i, t_param list, int tmp)
{
	if (list.precision > tmp && list.zero == 0)
		*size += ft_print_symb('0', list.precision - tmp);
	ft_putstr(i);
	if (list.width > list.precision && list.width > tmp && list.zero == 1)
		*size += ft_print_symb('0', list.width - list.space -
				(list.precision > tmp ? list.precision : tmp));
	if (list.width > list.precision && list.width > tmp)
		*size += ft_print_symb(' ', list.width - list.space -
			(list.precision > tmp ? list.precision : tmp));
}

static void	prec_neg(int *size, char *i, t_param list, int tmp)
{
	// if (list.space == 1)
	// 	*size += ft_print_symb(' ', 1);
	if (list.minus == 0 && list.zero == 0 && list.width > tmp)
		*size += ft_print_symb(' ', list.width - tmp);
	if (list.minus == 0 && list.zero == 1 && list.width > tmp)
		*size += ft_print_symb('0', list.width - tmp);
	ft_putstr(i);
	if (list.minus == 1 && list.width > tmp)
		*size += ft_print_symb(' ', list.width - tmp);
}

static void	prec_pos(int *size, char *i, t_param list, int tmp)
{
	*i == '0' && list.precision == 0 ? tmp -= 1 : 0;
	// if ((list.space == 1) || (list.space == 1 && list.plus == 0))
	// 	*size += ft_print_symb(' ', 1);
	if (list.width > list.precision && list.width > tmp)
		*size += ft_print_symb(' ', list.width - list.space -
			(list.precision > tmp ? list.precision : tmp));
	if (list.width > list.precision && list.width > tmp && list.zero == 1)
		*size += ft_print_symb('0', list.width - list.space -
			(list.precision > tmp ? list.precision : tmp));
	if (list.precision > tmp && list.zero == 0)
		*size += ft_print_symb('0', list.precision - tmp);
	*i == '0' && list.precision == 0 ? *size = *size - 1 : ft_putstr(i);
}

static int	ft_type_u(t_param list, char *i)
{
	int size;

	size = ft_strlen(i);
	if (list.precision == -1)
		prec_neg(&size, i, list, size);
	else if (list.minus == 0)
		prec_pos(&size, i, list, size);
	else if (list.minus == 1)
		minus_pos(&size, i, list, size);
	free(i);
	return (size);
}

int			ft_u(t_param list, va_list ap)
{
	if (list.length == 0)
		return (ft_type_u(list,
				ft_itoa_base_ll((unsigned)va_arg(ap, unsigned), 10)));
	else if (list.length == 'l')
		return (ft_type_u(list,
				ft_itoa_base_ll((unsigned long)va_arg(ap, unsigned long), 10)));
	else if (list.length == 'l' + 'l')
		return (ft_type_u(list,
	ft_itoa_base_ll((unsigned long long)va_arg(ap, unsigned long long), 10)));
	else if (list.length == 'h')
		return ((ft_type_u(list,
				ft_itoa_base_ll((unsigned short)va_arg(ap, unsigned), 10))));
	else if (list.length == 'h' + 'h')
		return (ft_type_u(list,
				ft_itoa_base_ll((unsigned char)va_arg(ap, unsigned), 10)));
	return (0);
}
