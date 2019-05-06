/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 23:36:04 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/06 15:10:29 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

// int			ft_round(long double f, int precision)
// {
// 	long double
// }

char		*ft_dota(long double f, int precision)
{
	char	*main;
	char	*prec;
	char	*res;
	char	*beg_p;

	f += 0.5 * ft_neg_pow(10, -1 * precision);
	if (precision != 0)
		main = ft_itoa((long)f);
	else
	{
		main = ft_itoa((long)f);
		return (main);
	}
	if (!(prec = ft_strnew(precision + 1)))
		return (NULL);
	*prec = '.';
	f = (f - (int)f) * 10;
	beg_p = prec;
	while (precision--)
	{
		prec++;
		*prec = (int)f + '0';
		f = (f - (int)f) * 10;
	}
	res = ft_strjoin(main, beg_p);
	free(main);
	free(beg_p);
	return (res);
}
