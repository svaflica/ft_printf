/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/14 14:51:42 by qclubfoo         ###   ########.fr       */
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

	printf("%0#34.6llo\n", 0);
	ft_printf("%0#34.6llo\n", 0);

	printf("@moulitest: %.0o %.0o\n", 0, 0);
	ft_printf("@moulitest: %.0o %.0o\n", 0, 0);

	printf("!%0#34.2ho!\n", 0);
	ft_printf("!%0#34.2ho!\n", 0);

	printf("^.^/%0#39.49llo^.^/\n", 0);
	ft_printf("^.^/%0#39.49llo^.^/\n", 0);

	printf("%-0#34.6llo\n", 0);
	ft_printf("%-0#34.6llo\n", 0);

	printf("@moulitest: %-.0o %-.0o\n", 0, 0);
	ft_printf("@moulitest: %-.0o %-.0o\n", 0, 0);

	printf("!%-0#34.2ho!\n", 0);
	ft_printf("!%-0#34.2ho!\n", 0);

	printf("!%#034.2hho!\n", 317750540);
	ft_printf("!%#034.2hho!\n", 317750540);

	printf("%#025.10o\n", 952442588);
	ft_printf("%#025.10o\n", 952442588);

	printf("%-#42.2hho\n", -1509226214);
	ft_printf("%-#42.2hho\n", -1509226214);

	printf("!%#034.2hho!\n", -174683375);
	ft_printf("!%#034.2hho!\n", -174683375);
	// printf(">------------<%2zo>------------<\n", 0);
	// ft_printf(">------------<%2zo>------------<\n", 0);
	
}
