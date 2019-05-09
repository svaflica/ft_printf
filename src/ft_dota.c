/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 23:36:04 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/09 15:02:37 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

union doub {
	struct {
		unsigned long mantissa : 52;
		unsigned long expo : 10;
		unsigned long sign : 1;
	} dou;
	__int128_t d;
} doub;

char		*ft_dota(long double f, int precision)
{
	union doub k;

	k.d = f;
	printf("sign : %lu\n\n", k.dou.sign);
	printf("expo : %lu\n\n", k.dou.expo);
	printf("mant : %lu\n\n", k.dou.mantissa);
}

// char		*ft_dota(long double f, int precision)
// {
// 	char	*main;
// 	char	*prec;
// 	char	*res;
// 	char	*beg_p;

// 	// f += 0.5 * ft_neg_pow(10, -1 * precision);
// 	if (precision != 0)
// 		main = ft_itoa((long)f);
// 	else
// 	{
// 		f += 0.5;
// 		return (ft_itoa((long)f));
// 	}
// 	if (!(prec = ft_strnew(precision + 1)))
// 		return (NULL);
// 	*prec = '.';
// 	f = (f - (int)f) * 10;
// 	beg_p = prec;
// 	while (precision--)
// 	{
// 		prec++;
// 		*prec = (int)f + '0';
// 		f = (f - (int)f) * 10;
// 	}
// 	res = ft_strjoin(main, beg_p);
// 	free(main);
// 	free(beg_p);
// 	return (res);
// }
