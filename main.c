/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/29 16:56:48 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
//gcc main.c ./src/*.c ./src/ft_param/*.c ./src/ft_str/*.c ./src/ft_type/*.c && ./a.out

int main(void)

{
	// printf("%d\n", ft_printf("%5.o %5.0o^\n", 0, 0));
	// printf("%d\n", printf("%5.o %5.0o^\n", 0, 0));
// printf("%03.2d\n", -1);
// printf("%04.3d", -1);

printf("%03.2d\n", -1);
ft_printf("%03.2d\n", -1);
}
