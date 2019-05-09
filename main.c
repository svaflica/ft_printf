/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/09 10:38:47 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c ./src/ft_buf/*.c && ./a.out
int main (void)
{
	// // printf("%2s", "str");
	char c;
	// char buf[30] = "\033[38;5;0m";
	// //printf("\033[38;5;153mBoooooooooold greeeeeeeen\033[0mAAAAAAAAA\n");
	// write(1, "\033[38;5;0m", 11);
	// write(1, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n", 16);
	// write(1, "\033[0m", 4);

	ft_printf("{%3*p}\n", 10, &c);
	printf("{%3*p}\n", 10, &c);

}
