/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:47:45 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/25 08:29:48 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

t_param				*ft_param_new(void)
{
	t_param *new;

	if (!(new = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	ft_param_nul(new);
	return (new);
}
