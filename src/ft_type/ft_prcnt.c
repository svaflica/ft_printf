/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:15:49 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/05 18:07:22 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_prcnt(t_param list, t_buf *buf)
{
	if (list.minus == 0 && list.zero == 1 && list.width > 1)
		ft_buf_add_s(buf,
			ft_memset(ft_strnew(list.width - 1), '0', list.width - 1));
	else if (list.width > 1 && list.minus == 0)
		ft_buf_add_s(buf,
			ft_memset(ft_strnew(list.width - 1), ' ', list.width - 1));
	ft_buf_add_c(buf, '%');
	if (list.width > 1 && list.minus == 1)
		ft_buf_add_s(buf,
			ft_memset(ft_strnew(list.width - 1), ' ', list.width - 1));
}
