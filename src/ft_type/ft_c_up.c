/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:34:15 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/15 15:13:35 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void				ft_c_up(t_param list, wchar_t c, t_buf *buf)
{
	int	len;
	unsigned long long cc;

	if (c < 0)
		buf->err = 1;
	else
	{
		cc = (unsigned long long)c;
		len = 1 + (cc >= 127) + (cc >= 2047) + (cc >= 65535);
		if (list.minus == 0 && list.zero == 1 && list.width > len && list.width - len >= 0)
			ft_buf_add_s(buf,
				ft_memset(ft_strnew(list.width - len), '0', list.width - len), 0);
		else if (list.minus == 0 && list.zero == 0 && list.width > 1 && list.width - len >= 0)
			ft_buf_add_s(buf,
				ft_memset(ft_strnew(list.width - len), ' ', list.width - len), 0);
		if ((MB_CUR_MAX == 4 && c < 114112) || (MB_CUR_MAX == 3 && c < 65536) ||
			(MB_CUR_MAX == 2 && c < 2048) || (MB_CUR_MAX == 1 && c < 127))
			ft_buf_add_nc(buf, c);
		else
			ft_buf_add_c(buf, c);
		if (list.minus == 1 && list.width > len)
			ft_buf_add_s(buf,
				ft_memset(ft_strnew(list.width - len), ' ', list.width - len), 0);
	}
}
