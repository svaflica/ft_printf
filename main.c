/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/13 15:23:37 by qclubfoo         ###   ########.fr       */
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
	// printf("{%03.2d}\n", 2);
	// ft_printf("{%03.2d}\n", 2);
	printf("%-56.6hi\n", -1621429446);
	ft_printf("%-56.6hi\n", -1621429446);

	printf("%-36.15i\n", -1688340887);
	ft_printf("%-36.15i\n", -1688340887);

	printf("!%-4.2hhi!\n", 24652749);
	ft_printf("!%-4.2hhi!\n", 24652749);
	
	printf("%+-61.56hhi\n", 1755736792);
	ft_printf("%+-61.56hhi\n", 1755736792);

	printf("\\!/%+-36.2hhi\\!/\n", 617099467);
	ft_printf("\\!/%+-36.2hhi\\!/\n", 617099467);

	printf("42%+-36.20hhi42\n", 102728879);
	ft_printf("42%+-36.20hhi42\n", 102728879);
	// printf("\\!/% -3zi\\!/\n", 0);
	// ft_printf("\\!/% -3zi\\!/\n", 0);
	// printf(">------------<%+14.2zi>------------<\n", -2091894250);
	// ft_printf(">------------<%+14.2zi>------------<\n", -2091894250);

	// printf("{%*3d}\n", 0, 0);
	// ft_printf("{%*3d}\n", 0, 0);


	// printf("{%3*d}\n", 0, 0);
	// ft_printf("{%3*d}\n", 0, 0);
	
}
