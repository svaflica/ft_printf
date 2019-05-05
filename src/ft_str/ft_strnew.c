/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:43:45 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 23:40:03 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*res;

	res = (unsigned char *)b;
	while (len--)
	{
		*res = c;
		res++;
	}
	return (b);
}

static void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}


static void		*ft_memalloc(size_t size)
{
	void	*new;

	new = NULL;
	if (size != 0)
	{
		if (!(new = (void *)malloc(size)))
			return (NULL);
		ft_bzero(new, size);
	}
	return (new);
}

unsigned char	*ft_strnew(size_t size)
{
	return ((unsigned char *)ft_memalloc(size + 1));
}
