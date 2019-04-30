/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:51:07 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/30 17:26:57 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	prec_neg(int *size, char *i, t_param list, int tmp)
{
	if (list.minus == 0 && list.zero == 0 && list.width - list.plus > tmp)
		*size += ft_print_symb(' ', list.width - list.plus - tmp);
	if (list.minus == 0 && list.zero == 1 && list.width - list.plus > tmp)
		*size += ft_print_symb('0', list.width - list.plus - tmp);
	ft_putstr(i);
	if (list.minus == 1 && list.width - list.plus > tmp)
		*size += ft_print_symb(' ', list.width - list.plus - tmp);
}

static void	prec_pos(int *size, char *i, t_param list, int tmp)
{
	if (list.minus == 0 && list.zero == 0 &&
		list.width - list.plus - list.precision > tmp)
		*size += ft_print_symb(' ',
						list.width - list.plus - list.precision - tmp);
	if (list.precision > tmp)
		*size += ft_print_symb('0', list.precision - tmp - list.plus);
	ft_putstr(i);
	if (list.width > (list.precision + tmp))
		*size += ft_print_symb(' ', list.width - list.precision - tmp);
}

static int	ft_type_u(t_param list, char *i)
{
	int size;

	size = ft_strlen(i);
	if (list.precision == -1)
		prec_neg(&size, i, list, size);
	else
		prec_pos(&size, i, list, size);
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
				ft_itoa_base_ll(va_arg(ap, unsigned long), 10)));
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
