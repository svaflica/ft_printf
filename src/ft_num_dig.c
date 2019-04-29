/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_dig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:53:32 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/29 17:39:38 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_num_dig(long long n, int base)
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
