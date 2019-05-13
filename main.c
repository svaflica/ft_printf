/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/13 11:45:00 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

void	print(unsigned char *f)
{
	for(int i=0; i<sizeof(long double); i++) {
  		unsigned char cx = *(f+i);
  		for (int j=0; j<5; j++)
    		printf("%d", (cx>>j)&1);
	}
}

union d {
	struct {
		long long mantissa : 52;
		long long exp : 11;
		long long sign : 1;
	} me;
	__int128_t dou;
} lol;

//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c ./src/ft_buf/*.c && ./a.out

int main (void)
{
	setlocale(LC_ALL, "ru_RU.UTF-4");

	double n = -40.555555;
	//__int128_t  exp = (*(__int128_t *)&n << 1 >> 65) - 16383;
	//long long exp = *(__int128_t *)&n & ((__int128_t)0x7FFF << 64);
	// long long exp = (((*(__int128_t *)&n) >> 64) & 0x7FFF) - 16383;
	// long mantissa   = *(__int128_t *)&n << 12 >> 12;

	union d f;
	f.dou = *((__int128_t *)(&n));
	printf("%lld\n\n", f.me.mantissa);
	printf("%lld\n\n\n", f.me.exp);
}
