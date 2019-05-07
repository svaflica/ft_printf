/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:37:10 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/02 16:19:45 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

t_buf				*ft_buf_new(t_buf *new)
{
	new->size = 0;
	new->top = -1;
	if (!(new->buf = ft_strnew(1000)))
		return (NULL);
	return (new);
}