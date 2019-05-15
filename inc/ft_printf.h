/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 08:39:30 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/15 15:01:57 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_INT 922337203685477580
# define BUF_SIZE 1000

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

typedef struct		s_buf
{
	char			*buf;
	size_t			top;

	size_t			size;
	int				err;
}					t_buf;

t_param				*ft_param_new(void);
int					ft_param_add(t_param *new, char **str, va_list ap);
void				ft_param_nul(t_param *param);

t_buf				*ft_buf_new(t_buf *new);
void				ft_buf_add_c(t_buf *new, char c);
void				ft_buf_add_nc(t_buf *new, wchar_t c);
void				ft_buf_add_s(t_buf *new, char *str, int flag);
void				ft_buf_add_ns(t_buf *new, char *str, size_t n, int flag);
int					ft_do_buf_empty(t_buf *buf);
void				free_buf(t_buf *buf);

int					ft_printf(char *str, ...);

void				ft_percent(va_list ap, char **str,
					t_param list, t_buf *buf);

char				*ft_strnew(size_t size);
void				ft_putnbr(long long n);
int					ft_putchar(unsigned long long c, char *str);
void				ft_putstr(char const *s);
int					ft_putnstr(char *str, int size);
size_t				ft_strlen(const char *s);
int					ft_print_symb(int c, int size);
int					ft_num_dig(uintmax_t n, int base);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_memnew(size_t i, int lett);
long double			ft_neg_pow(long double n, int pow);
char				*ft_strjoin(char const *s1, char const *s2);

void				ft_c_up(t_param list, wchar_t c, t_buf *buf);
void				ft_c(t_param list, char c, t_buf *buf);
void				ft_s(t_param list, char *s, t_buf *buf);
void				ft_s_up(t_param list, wchar_t *s, t_buf *buf);
void				ft_p(t_param list, void *ptr, t_buf *buf);
void				ft_d(t_param list, va_list ap, t_buf *buf);
void				ft_d_up(t_param list, va_list ap, t_buf *buf);
void				ft_u(t_param list, va_list ap, t_buf *buf);
void				ft_u_up(t_param list, va_list ap, t_buf *buf);
void				ft_o(t_param list, va_list ap, t_buf *buf);
void				ft_o_up(t_param list, va_list ap, t_buf *buf);
void				prec_pos_null(char *str, t_param list, t_buf *buf);
void				prec_neg_null(char *str, t_param list, t_buf *buf);
void				ft_x(t_param list, va_list ap, t_buf *buf);
void				ft_prcnt(t_param list, t_buf *buf);
void				ft_x_up(t_param list, va_list ap, t_buf *buf);
void				ft_x(t_param list, va_list ap, t_buf *buf);
void				minus_neg_null(t_param list, char *i, int tmp, t_buf *buf);
void				minus_pos_null(t_param list, char *i, int tmp, t_buf *buf);
void				ft_f(t_param list, va_list ap, t_buf *buf);
char				*ft_dota(long double f, int precision);

char				*ft_strchr(const char *s, int c);

int					ft_atoi(const char *str);
char				*ft_itoa(long long n);
char				*ft_itoa_base(long long n, int base);
char				*ft_itoa_base_ll(uintmax_t n, int base);

#endif
