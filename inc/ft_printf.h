/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 08:39:30 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/28 16:31:48 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_INT 922337203685477580

typedef struct		s_param
{
	unsigned char	length;
	char			minus;
	char			plus;
	char			zero;
	char			hasht;
	char			space;
	int				width;
	int				precision;
}					t_param;

t_param				*ft_param_new(void);
int					ft_param_add(t_param *new, char **str);
void				ft_param_nul(t_param *param);

int					ft_printf(char *str, ...);

size_t				ft_percent(va_list ap, char **str, t_param list);

void				ft_putnbr(intmax_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_putnstr(char *str, int size);
size_t				ft_strlen(const char *s);
int					ft_print_symb(int c, int size);
int					ft_num_dig(intmax_t n, int base);

int					ft_c(t_param list, int c);
int					ft_s(t_param list, char *s);
int					ft_p(t_param list, void *ptr);
int					ft_d(t_param list, va_list ap);
int					ft_u(t_param list, va_list ap);
int					ft_o(t_param list, va_list ap);
int					ft_prcnt(t_param list);

char				*ft_strchr(const char *s, int c);

int					ft_atoi(const char *str);
char				*ft_itoa(intmax_t n);
char				*ft_itoa_base(intmax_t n, int base);

#endif
