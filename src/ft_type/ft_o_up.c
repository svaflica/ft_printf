/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:09:26 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/09 13:29:45 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void			prec_neg(char *str, t_param list, t_buf *buf)
{
	int tmp;

	tmp = ft_strlen(str);
	*str == '0' && tmp == 1 ? tmp = 0 : 0;
	if (list.minus == 0 && list.zero == 0 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - list.hasht - tmp, ' '), 0);
	if (list.minus == 0 && list.zero == 1 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - list.hasht - tmp, '0'), 0);
	list.hasht == 1 && tmp != '0' ? ft_buf_add_c(buf, '0') : NULL;
	ft_buf_add_s(buf, str, 0);
	if (list.minus == 1 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - list.hasht - tmp, ' '), 0);
}

static void			prec_pos(char *str, t_param list, t_buf *buf)
{
	int tmp;

	tmp = ft_strlen(str);
	*str == '0' && tmp == 1 ? tmp = 0 : 0;
	if (list.minus == 0)
		{
		if (list.width > list.precision && list.width > tmp && list.zero == 0)
			ft_buf_add_s(buf, ft_memnew(list.width - (list.precision > tmp ? list.precision : tmp) - (list.hasht == 1 && list.precision < tmp), ' '), 0);
		if (list.width > list.precision && list.width > tmp && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width - (list.precision > tmp ? list.precision : tmp) - (list.hasht == 1 && list.precision < tmp), '0'), 0);
		if ((tmp > list.precision && list.hasht == 1) || (tmp == 0 && list.hasht == 1))
			ft_buf_add_c(buf, '0');
		if (list.precision > tmp)
			ft_buf_add_s(buf, ft_memnew(list.precision - tmp, '0'), 0);
		tmp != 0 ? ft_buf_add_s(buf, str, 0) : 0;
		}
	else
	{
		if ((tmp > list.precision && list.hasht == 1) || (tmp == 0 && list.hasht == 1))
			ft_buf_add_c(buf, '0');
		if (list.precision > tmp)
			ft_buf_add_s(buf, ft_memnew(list.precision - tmp, '0'), 0);
		tmp != 0 ? ft_buf_add_s(buf, str, 0) : 0;
		if (list.width > list.precision && list.width > tmp)
			ft_buf_add_s(buf, ft_memnew(list.width - (list.precision > tmp ? list.precision : tmp) - (list.hasht == 1 && list.precision < tmp), ' '), 0);
	}
}

static void			ft_type_o_up(t_param list, char *i, t_buf *buf)
{
	if (list.precision == -1)
		prec_neg(i, list, buf);
	else
		prec_pos(i, list, buf);
	// free(i);
}

void				ft_o_up(t_param list, va_list ap, t_buf *buf)
{
	ft_type_o_up(list, ft_itoa_base_ll((unsigned long)va_arg(ap, long int), 8), buf);
}