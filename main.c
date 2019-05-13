/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/13 13:09:14 by qclubfoo         ###   ########.fr       */
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

	printf("%d", printf("\\!/% 40.53hhi\\!/\n", 1525060274));
	printf("%d", ft_printf("\\!/% 40.53hhi\\!/\n", 1525060274));

	// printf("{%*3d}\n", 0, 0);
	// ft_printf("{%*3d}\n", 0, 0);


	// printf("{%3*d}\n", 0, 0);
	// ft_printf("{%3*d}\n", 0, 0);
	
}
