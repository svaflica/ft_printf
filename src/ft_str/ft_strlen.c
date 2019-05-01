/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:49:31 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 13:22:22 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	char *tmp;

	tmp = (char*)s;
	if (s)
		while (*tmp)
			tmp++;
	return (tmp - s);
}
