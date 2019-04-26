/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:30:23 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/04/26 17:43:53 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_before_write(t_param list, int tmp)
{
	int	size;

	size = 0;
	if (list.width > 0 && list.width > tmp && list.precision == -1
						&& list.minus == 0 && list.zero == 0)
		size += ft_print_symb(' ', list.width - tmp);
	if (list.width > 0 && list.width > tmp && list.precision != -1
					&& list.minus == 0 && list.zero == 0 && tmp == 0)
		size += ft_print_symb(' ', list.width - tmp);
	if (list.width > 0 && list.width > tmp && list.precision != -1
						&& list.minus == 0 && list.zero == 0 && tmp != 0)
		size += ft_print_symb(' ', list.width - list.precision);
	if (list.width > 0 && list.width > tmp && list.minus == 0 && list.zero == 1)
		size += ft_print_symb('0', list.width - tmp);
	return (size);
}

static int	ft_after_write(t_param list, int tmp)
{
	int	size;

	size = 0;
	if (list.width > 0 && list.width > tmp &&
				list.minus == 1 && list.precision == -1)
		size += ft_print_symb(' ', list.width - tmp);
	if (list.width > 0 && list.width > tmp && list.precision != -1 &&
					list.minus == 1 && list.zero == 0 && tmp == 0)
		size += ft_print_symb(' ', list.width - tmp);
	if (list.width > 0 && list.width > tmp && list.minus == 1 &&
					list.precision != -1 && tmp != 0)
		size += ft_print_symb(' ', list.width - list.precision);
	return (size);
}

static int	ft_write(t_param list, char *s)
{
	int	size;

	size = 0;
	if (list.precision > -1)
		size += ft_putnstr(s, list.precision);
	else
	{
		if (s != NULL)
		{
			ft_putstr(s);
			size += ft_strlen(s);
		}
		else
		{
			ft_putstr("(null)");
			size += ft_strlen("(null)");
		}
	}
	return (size);
}

int			ft_s(t_param list, char *s)
{
	int	tmp;
	int	size;

	size = 0;
	tmp = ft_strlen(s);
	size += ft_before_write(list, tmp);
	size += ft_write(list, s);
	size += ft_after_write(list, tmp);
	return (size);
}
