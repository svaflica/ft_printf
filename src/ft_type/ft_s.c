/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:30:23 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/05 18:17:21 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_before_write(t_param list, int tmp, t_buf *buf)
{
	int	size;

	size = 0;
	if (list.width > 0 && list.width > tmp && list.precision == -1
						&& list.minus == 0 && list.zero == 0)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
	if (list.width > 0 && list.width > tmp && list.precision != -1
					&& list.minus == 0 && list.zero == 0 && tmp == 0)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
	if (list.width > 0 && list.width > tmp && list.precision != -1
						&& list.minus == 0 && list.zero == 0 && tmp != 0)
		ft_buf_add_s(buf, ft_memnew(list.width - list.precision, ' '));
	if (list.width > 0 && list.width > tmp && list.minus == 0 && list.zero == 1)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp, '0'));
	return (size);
}

static int	ft_after_write(t_param list, int tmp, t_buf *buf)
{
	int	size;

	size = 0;
	if (list.width > 0 && list.width > tmp &&
				list.minus == 1 && list.precision == -1)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
	if (list.width > 0 && list.width > tmp && list.precision != -1 &&
					list.minus == 1 && list.zero == 0 && tmp == 0)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
	if (list.width > 0 && list.width > tmp && list.minus == 1 &&
					list.precision != -1 && tmp != 0)
		ft_buf_add_s(buf, ft_memnew(list.width - list.precision, ' '));
	return (size);
}

static int	ft_write(t_param list, char *s, t_buf *buf)
{
	int	size;

	size = 0;
	if (list.precision > -1)
		ft_buf_add_ns(buf, s, list.precision);
	else
	{
		if (s != NULL)
			ft_buf_add_s(buf, s);
		else
			ft_buf_add_s(buf, "(null)");
	}
	return (size);
}

void			ft_s(t_param list, char *s, t_buf *buf)
{
	int	tmp;
	int	size;

	size = 0;
	tmp = ft_strlen(s);
	size += ft_before_write(list, tmp, buf);
	size += ft_write(list, s, buf);
	size += ft_after_write(list, tmp, buf);
	return (size);
}
