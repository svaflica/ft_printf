/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:58:01 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/05 15:31:07 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	minus_neg(t_param list, char *i, int *size, int tmp)
{

	if (list.width > list.precision && list.width > tmp &&
	(list.zero == 0 || list.precision > -1))
		*size += ft_print_symb(' ', list.width - (list.precision > tmp ?
		list.precision : tmp) - (*i == '0' ? 0 : list.hasht));
	if (list.hasht != 0 && *i != '0')
		*size += ft_putnstr("0X", 2);
	if (list.zero == 1 && list.width > tmp && list.precision == -1)
		*size += ft_print_symb('0', list.width - tmp -
		(*i == '0' ? 0 : list.hasht));
	if (list.precision > tmp)
		*size += ft_print_symb('0', list.precision - tmp);
	if (list.precision == -1)
		ft_putstr(i);
	else if (*i != '0')
		ft_putstr(i);
	// list.precision == -1 ? ft_putstr(i) : (*i == '0' ? 0 : ft_putstr(i));
}

static void	minus_pos(t_param list, char *i, int *size, int tmp)
{
	if (list.hasht != 0 && *i != '0')
		*size += ft_putnstr("0X", 2);
	if (list.precision > tmp)
		*size += ft_print_symb('0', list.precision - tmp);
	// list.precision == -1 ? ft_putstr(i) : (*i == '0' ? 0 : ft_putstr(i));
	if (list.precision == -1)
		ft_putstr(i);
	else if (*i != '0')
		ft_putstr(i);
	if (list.width > list.precision && list.width > tmp)
		*size += ft_print_symb(' ', list.width - (list.precision > tmp ?
		list.precision : tmp) - (*i == '0' ? 0 : list.hasht));
}

static int	ft_type_x(t_param list, char *i)
{
	int		size;
	int		tmp;
	int		j;

	j = 0;
	while (i[j] != 0)
	{
		if (i[j] >= 'a' && i[j] <= 'z')
			i[j] = i[j] - 32;
		j++;
	}
	list.hasht == 1 ? list.hasht = 2 : 0;
	if (*i == '0' && list.precision != -1)
		tmp = 0;
	else
		tmp = ft_strlen(i);
	size = tmp;
	if (list.minus == 0)
		minus_neg(list, i, &size, tmp);
	else
		minus_pos(list, i, &size, tmp);
	free(i);
	return (size);
}

int			ft_x_up(t_param list, va_list ap)
{
	if (list.length == 0)
		return (ft_type_x(list,
				ft_itoa_base((unsigned)va_arg(ap, unsigned), 16)));
	else if (list.length == 'l')
		return (ft_type_x(list,
				ft_itoa_base((unsigned long)va_arg(ap, unsigned long), 16)));
	else if (list.length == 'l' + 'l')
		return (ft_type_x(list,
				ft_itoa_base((unsigned long long)va_arg(ap, unsigned long long), 16)));
	else if (list.length == 'h')
		return ((ft_type_x(list,
				ft_itoa_base((unsigned short)va_arg(ap, int), 16))));
	else if (list.length == 'h' + 'h')
		return (ft_type_x(list,
				ft_itoa_base((unsigned char)va_arg(ap, int), 16)));
		return (0);
}
