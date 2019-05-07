/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:42:35 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/07 15:29:47 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void			ft_print_and_free(int top, char *str)
{
	write(1, str, top + 1);
	while (*str)
	{
		*str = 0;
		str++;
	}
}

void				ft_buf_add_s(t_buf *new, char *str)
{
	size_t len;

	len = ft_strlen(str);
	if (new->top + 1 + len >= 20)
	{
		ft_print_and_free(new->top, new->buf);
		new->top = -1;
	}
	if (len >= 20)
	{
		new->size += len;
		write(1, str, len);
	}
	else
		while (*str)
		{
			new->top += ft_putchar(*str, new->buf + 1 + new->top);
			new->size++;
			str++;
		}
}

void				ft_buf_add_ns(t_buf *new, char *str, size_t n)
{
	size_t len;

	len = ft_strlen(str);
	if (new->top + 1 + len >= 20)
	{
		new->size += new->top + 1;
		ft_print_and_free(new->top, new->buf);
		new->top = -1;
	}
	if (n >= 20/*len >= 20*/)
	{
		new->size += len;
		write(1, str, len);
	}
	else
		while (*str && n--)
		{
			new->top += ft_putchar(*str, new->buf + 1 + new->top);
			new->size++;
			str++;
		}
}

void				ft_buf_add_c(t_buf *new, char c)
{
	if (new->top + 1 >= 20)
	{
		ft_print_and_free(new->top, new->buf);
		new->top = -1;
	}
	new->buf[++new->top] = c;
	new->size++;
}

void				ft_buf_add_nc(t_buf *new, wchar_t c)
{
	int putch;

	if (new->top + 1 + (c <= 127) + (c <= 2047) + (c <= 65535) + (c > 65535)
			>= 20)
	{
		ft_print_and_free(new->top, new->buf);
		new->top = -1;
	}
	putch = ft_putchar(c, new->buf + 1 + new->top);
	new->top += putch;
	new->size += putch;
}
