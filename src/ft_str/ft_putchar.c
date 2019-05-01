/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:34:41 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 17:54:00 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void		ft_two_b(unsigned long long c)
{
	unsigned char *str;

	str = ft_strnew(4);
	str[1] = (c & 63) | (2 << 6);
	str[0] = ((c >> 6) & 31) | (6 << 5);
	write(1, str, 2);
	free(str);
}

void		ft_three_b(unsigned long long c)
{
	unsigned char *str;

	str = ft_strnew(4);
	str[2] = (c & 63) | (2 << 6);
	str[1] = ((c >> 6) & 63) | (2 << 6);
	str[0] = ((c >> 12) & 15) | (14 << 4);
	write(1, str, 3);
	free(str);
}

void		ft_four_b(unsigned long long c)
{
	unsigned char *str;

	str = ft_strnew(4);
	str[3] = (c & 63) | (2 << 6);
	str[2] = ((c >> 6) & 63) | (2 << 6);
	str[1] = ((c >> 12) & 63) | (2 << 6);
	str[0] = ((c >> 18) & 7) | (30 << 3);
	write(1, str, 4);
	free(str);
}

void		ft_putchar(unsigned long long c)
{
	if (c <= 127)
		write(1, &c, 1);
	else if (c <= 2047)
		ft_two_b(c);
	else if (c <= 65535)
		ft_three_b(c);
	else
		ft_four_b(c);
}
