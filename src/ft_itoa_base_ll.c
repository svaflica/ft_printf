/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:19:47 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/29 18:44:17 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		turn_into_char(char *res, unsigned long long n,
								int base, int num_d)
{
	char	*buf;
	int		sign;

	buf = "0123456789abcdef";
	sign = 1;
	if (n < 0)
		sign = -1;
	res[num_d--] = '\0';
	while (n)
	{
		res[num_d--] = buf[(n % base) * sign];
		n /= base;
	}
}

char			*ft_itoa_base_ll(unsigned long long n, int base)
{
	char	*res;
	int		num_d;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 || n == 0)
		res = ft_itoa(n);
	else
	{
		num_d = ft_num_dig(n, base);
		if (!(res = (char *)malloc(sizeof(char) * (num_d + 1))))
			return (NULL);
		turn_into_char(res, n, base, num_d);
	}
	return (res);
}
