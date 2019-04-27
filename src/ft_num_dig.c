/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_dig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:53:32 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/27 16:50:31 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_num_dig(intmax_t n, int base)
{
	int res;

	res = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		res++;
		n /= base;
	}
	return (res);
}
