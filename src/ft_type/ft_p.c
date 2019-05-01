/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:16:42 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 13:28:04 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		ft_zero(t_param list, int len, int *size)
{
	if (list.minus == 1)
	{
		write(1, "0x", 2);
		if (list.precision > len - 2)
			size += ft_print_symb('0', list.precision - len + 2);
		if (list.width > list.precision && list.width > len &&
		list.precision > len - 2)
			size += ft_print_symb(' ', list.width - list.precision - 2);
		if (list.width > list.precision && list.width > len &&
		list.precision < len - 2)
			size += ft_print_symb(' ', list.width - len);
	}
	else
	{
		if (list.width > list.precision && list.width > len)
		{
			if (list.precision > len - 2)
				size += ft_print_symb(' ', list.width - list.precision - 2);
			else
				size += ft_print_symb(' ', list.width - len);
		}
		write(1, "0x", 2);
		if (list.precision > len - 2)
			size += ft_print_symb('0', list.precision - len + 2);
	}
}

static void		minus_pos(t_param list, char *str, int len, int *size)
{
	write(1, "0x", 2);
	if (list.precision > len - 2)
		*size += ft_print_symb('0', list.precision - len + 2);
	ft_putstr(str);
	if (list.width > list.precision && list.width > len)
	{
		if (list.precision > len - 2)
			*size += ft_print_symb(' ', list.width - list.precision - 2);
		else
			*size += ft_print_symb(' ', list.width - len);
	}
}

static void		minus_neg(t_param list, char *str, int len, int *size)
{
	if (list.width > list.precision && list.width > len)
	{
		if (list.precision > len - 2)
			size += ft_print_symb(' ', list.width - list.precision - 2);
		else
			size += ft_print_symb(' ', list.width - len);
	}
	write(1, "0x", 2);
	if (list.precision > len - 2)
		size += ft_print_symb('0', list.precision - len + 2);
	ft_putstr(str);
}

int				ft_p(t_param list, void *ptr)
{
	int				size;
	long long		tmp;
	char			*str;
	int				len;

	tmp = (unsigned long long)ptr;
	str = ft_itoa_base_ll(tmp, 16);
	len = ft_strlen(str) + 2;
	size = len;
	if (*str == '0' && len == 3 && list.precision > -1)
		ft_zero(list, len - 1, &size);
	else if (list.minus == 1)
		minus_pos(list, str, len, &size);
	else
		minus_neg(list, str, len, &size);
	free(str);
	return (size);
}
