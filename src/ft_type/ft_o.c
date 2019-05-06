/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:09:26 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/06 18:33:27 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void			prec_neg(char *str, t_param list, t_buf *buf)
{
	int tmp;

	tmp = ft_strlen(str);
	if (list.minus == 0 && list.zero == 0 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - list.hasht - tmp, ' '));
	if (list.minus == 0 && list.zero == 1 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - list.hasht - tmp, '0'));
	list.hasht == 1 ? ft_buf_add_c(buf, '0') : NULL;
	ft_buf_add_s(buf, str);
	if (list.minus == 1 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - list.hasht - tmp, ' '));
}

static void			prec_pos(char *str, t_param list, t_buf *buf)
{
	int tmp;

	tmp = ft_strlen(str);
	if (*str == '0' && tmp == 1)
		tmp = 0;
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(list.precision - tmp - list.hasht, '0'));
	list.hasht == 1 ? ft_buf_add_c(buf, '0') : NULL;
	if (list.precision < list.width && list.precision == 0 && tmp == 0)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
	if (list.precision < list.width && list.precision < tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
	if (tmp != 0)
		ft_buf_add_s(buf, str);
	if (list.width > list.precision && list.minus == 1)
		ft_buf_add_s(buf, ft_memnew(list.width - list.precision, ' '));
}

static void			ft_type_o(t_param list, char *i, t_buf *buf)
{
	if (list.precision == -1)
		prec_neg(i, list, buf);
	else
		prec_pos(i, list, buf);
	free(i);
}

void				ft_o(t_param list, va_list ap, t_buf *buf)
{
	if (list.length == 0)
		ft_type_o(list,
				ft_itoa_base((unsigned int)va_arg(ap, int), 8), buf);
	else if (list.length == 'l')
		ft_type_o(list,
				ft_itoa_base((unsigned long)va_arg(ap, int), 8), buf);
	else if (list.length == 'l' + 'l')
		ft_type_o(list,
				ft_itoa_base((unsigned long long)va_arg(ap, int), 8), buf);
	else if (list.length == 'h')
		ft_type_o(list,
				ft_itoa_base((unsigned short)va_arg(ap, int), 8), buf);
	else if (list.length == 'h' + 'h')
		ft_type_o(list,
				ft_itoa_base((unsigned char)va_arg(ap, int), 8), buf);
}
