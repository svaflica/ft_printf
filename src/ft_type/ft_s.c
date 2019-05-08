/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:30:23 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/08 14:46:05 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		prec_pos(t_param list, char *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
	{
		if (list.width > (tmp < list.precision ? tmp : list.precision))
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision), ' '));
		if (s != NULL)
			ft_buf_add_ns(buf, s, tmp < list.precision ? tmp : list.precision);
		else
			ft_buf_add_s(buf, "(null)");
	}
	else
	{
		if (s != NULL)
			ft_buf_add_ns(buf, s, tmp < list.precision ? tmp : list.precision);
		else
			ft_buf_add_s(buf, "(null)");
		if (list.width > (tmp < list.precision ? tmp : list.precision))
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision), ' '));
	}
}

static void		prec_neg(t_param list, char *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
	{
		if (list.width > tmp)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
		if (s != NULL)
			ft_buf_add_s(buf, s);
		else
			ft_buf_add_s(buf, "(null)");
	}
	else
	{
		if (s != NULL)
			ft_buf_add_s(buf, s);
		else
			ft_buf_add_s(buf, "(null)");
		if (list.width > tmp)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
	}
}

void		ft_s(t_param list, char *s, t_buf *buf)
{
	int	tmp;

	tmp = ft_strlen(s);
	if (list.precision > -1)
		prec_pos(list, s, tmp, buf);
	else
		prec_neg(list, s, tmp, buf);
}
