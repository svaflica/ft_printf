/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:58:01 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/05 20:29:53 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	minus_neg(t_param list, char *i, int tmp, t_buf *buf)
{

	if (list.width > list.precision && list.width > tmp &&
	(list.zero == 0 || list.precision > -1))
		ft_buf_add_s(buf, ft_memnew(list.width - (list.precision > tmp ?
		list.precision : tmp) - (*i == '0' ? 0 : list.hasht), ' '));
	if (list.hasht != 0 && *i != '0')
		ft_buf_add_s(buf, "0X");
	if (list.zero == 1 && list.width > tmp && list.precision == -1)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp -
		(*i == '0' ? 0 : list.hasht), '0'));
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(list.precision - tmp, '0'));
	if (list.precision == -1)
		ft_buf_add_s(buf, i);
	else if (*i != '0')
		ft_buf_add_s(buf, i);
}

static void	minus_pos(t_param list, char *i, int tmp, t_buf *buf)
{
	if (list.hasht != 0 && *i != '0')
		ft_buf_add_s(buf, "0X");
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(list.precision - tmp, '0'));
	if (list.precision == -1)
		ft_buf_add_s(buf, i);
	else if (*i != '0')
		ft_buf_add_s(buf, i);
	if (list.width > list.precision && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - (list.precision > tmp ?
		list.precision : tmp) - (*i == '0' ? 0 : list.hasht), ' '));
}

static void	ft_type_x(t_param list, char *i, t_buf *buf)
{
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
	if (list.minus == 0)
		minus_neg(list, i, tmp, buf);
	else
		minus_pos(list, i, tmp, buf);
	free(i);
}

void			ft_x_up(t_param list, va_list ap, t_buf *buf)
{
	if (list.length == 0)
		ft_type_x(list,
		ft_itoa_base((unsigned)va_arg(ap, unsigned), 16), buf);
	else if (list.length == 'l')
		ft_type_x(list,
		ft_itoa_base((unsigned long)va_arg(ap, unsigned long), 16), buf);
	else if (list.length == 'l' + 'l')
		ft_type_x(list,
		ft_itoa_base((unsigned long long)va_arg(ap, unsigned long long), 16),
		buf);
	else if (list.length == 'h')
		ft_type_x(list,
				ft_itoa_base((unsigned short)va_arg(ap, int), 16), buf);
	else if (list.length == 'h' + 'h')
		ft_type_x(list,
				ft_itoa_base((unsigned char)va_arg(ap, int), 16), buf);
}
