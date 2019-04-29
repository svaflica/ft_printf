/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:09:26 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/04/29 18:39:25 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include <stdio.h>

static void	prec_neg(int *size, char *str, t_param list, int tmp)
{
	if (list.minus == 0 && list.zero == 0 && list.width - list.hasht > tmp)
		*size = ft_print_symb(' ', list.width - list.hasht - tmp);
	if (list.minus == 0 && list.zero == 1 && list.width - list.hasht > tmp)
		*size = ft_print_symb('0', list.width - list.hasht - tmp);
	*size += ft_print_symb('0', list.hasht);
	*size += ft_putnstr(str, ft_strlen(str));
	if (list.minus == 1 && list.width - list.hasht > tmp)
		*size += ft_print_symb(' ', list.width - list.hasht - tmp);
}

static void	prec_pos(int *size, char *str, t_param list, int tmp)
{
	if (*str == '0' && tmp == 1)
		tmp = 0;
	if (list.precision > tmp)
		*size += ft_print_symb('0', list.precision - tmp - list.hasht);
	*size += ft_print_symb('0', list.hasht);
	if (list.precision < list.width && list.precision == 0 && tmp == 0)
		*size += ft_print_symb(' ', list.width - tmp);
	if (list.precision < list.width && list.precision < tmp)
		ft_print_symb(' ', list.width - tmp);
	if (tmp != 0)
		*size += ft_putnstr(str, ft_strlen(str));
	if (list.width > list.precision && list.minus == 1)
		*size += ft_print_symb(' ', list.width - list.precision);
}

static int			ft_type_o(t_param list, char *i)
{
	int		size;
	// char	*str;
	int		tmp;

	size = 0;
	// str = ft_itoa_base(i, 8);
	// tmp = ft_strlen(str);
	tmp = ft_strlen(i);
	if (list.precision == -1)
		// prec_neg(&size, str, list, tmp);
		prec_neg(&size, i, list, tmp);
	else
		// prec_pos(&size, str, list, tmp);
		prec_pos(&size, i, list, tmp);
	// free(str);
	free(i);
	return (size);
}

int				ft_o(t_param list, va_list ap)
{
	if (list.length == 0)
		return (ft_type_o(list,
				ft_itoa_base((unsigned int)va_arg(ap, int), 8)));
	else if (list.length == 'l')
		return (ft_type_o(list,
				ft_itoa_base((unsigned long)va_arg(ap, int), 8)));
	else if (list.length == 'l' + 'l')
		return (ft_type_o(list,
				ft_itoa_base((unsigned long long)va_arg(ap, int), 8)));
	else if (list.length == 'h')
		return ((ft_type_o(list,
				ft_itoa_base((unsigned short)va_arg(ap, int), 8))));
	else if (list.length == 'h' + 'h')
		return (ft_type_o(list,
				ft_itoa_base((unsigned char)va_arg(ap, int), 8)));
	return (0);
}
