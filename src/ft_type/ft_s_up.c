/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:30:04 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/08 16:41:11 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void print_sym(wchar_t *s, t_buf *buf, size_t size)
{
    while (size--)
    {
        ft_buf_add_nc(buf, *s);
        s++;
    }
}

static void		prec_pos(t_param list, wchar_t *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
	{
        if (list.width > (tmp < list.precision ? tmp : list.precision) && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision), '0'));
		else if (list.width > (tmp < list.precision ? tmp : list.precision))
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision), ' '));
		if (s != NULL)
			print_sym(s, buf, tmp < list.precision ? tmp : list.precision);
		else
			ft_buf_add_ns(buf, "(null)", list.precision);
	}
	else
	{
		if (s != NULL)
			print_sym(s, buf, tmp < list.precision ? tmp : list.precision);
		else
			ft_buf_add_ns(buf, "(null)", list.precision);
        if (list.width > (tmp < list.precision ? tmp : list.precision) && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision), '0'));
		else if (list.width > (tmp < list.precision ? tmp : list.precision))
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision), ' '));
	}
}

static void		prec_neg(t_param list, wchar_t *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
	{
		if (list.width > tmp && list.zero == 0)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
        else if (list.width > tmp)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, '0'));
		if (s != NULL)
			print_sym(s, buf, tmp);
		else
			ft_buf_add_s(buf, "(null)");
	}
	else
	{
		if (s != NULL)
			print_sym(s, buf, tmp);
		else
			ft_buf_add_s(buf, "(null)");
		if (list.width > tmp && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, '0'));
        else if (list.width > tmp)
            ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
	}
}

static size_t	ft_wstrlen(const wchar_t *s)
{
	wchar_t *tmp;

	tmp = (wchar_t*)s;
	if (s)
		while (*tmp)
			tmp++;
	return (tmp - s);
}

void       ft_s_up(t_param list, wchar_t *s, t_buf *buf)
{
    int	tmp;

	tmp = ft_wstrlen(s);
	if (list.precision > -1)
		prec_pos(list, s, tmp, buf);
	else
		prec_neg(list, s, tmp, buf);
}