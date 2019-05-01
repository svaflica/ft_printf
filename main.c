/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 13:27:55 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c && ./a.out
int main (void)
{
int a[1] = {1};

printf("%8.10p\n", 0);
ft_printf("%8.10p\n", 0);

//ft_printf("%-10.0p\n", 0);
	// printf("-->%20.0p<--\n", &a);
	// ft_printf("-->%20.0p<--\n\n", &a);

	// printf("-->%-20p<--\n", &a);
	// ft_printf("-->%-20p<--\n\n", &a);

	// printf("-->%20.17p<--\n", &a);
	// ft_printf("-->%20.17p<--\n\n", &a);

	// printf("-->%-20.17p<--\n", &a);
	// ft_printf("-->%-20.17p<--\n\n", &a);
}
