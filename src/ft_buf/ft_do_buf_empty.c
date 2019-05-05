/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_buf_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:46:30 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/05 18:02:48 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int		ft_do_buf_empty(t_buf *buf)
{
	int size;

	size = buf->size;
	write(1, buf->buf, buf->top + 1);
	free(buf->buf);
	buf = NULL;
	return (size);
}
