/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 22:21:14 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:50:16 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <wchar.h>
# include <inttypes.h>
# include "libft.h"

# define BUFF_SIZE 4096

# define FLAG_DOLLAR 1
# define WIDTH_ASTERISK 2
# define PRECISION_ASTERISK 4
# define PADDING 8
# define FIELD_WIDTH 16
# define PRECISION 32
# define MODIFYER 64

# define HASHTAG 1
# define ZERO 2
# define MOINS 4
# define PLUS 8
# define SPACE 16
# define APOSTROPHE 32

typedef struct s_buffer		t_buffer;

typedef struct s_list_conv	t_list_conv;
typedef struct s_list_arg	t_list_arg;
typedef struct s_conversion	t_conversion;
typedef struct s_argument	t_argument;
typedef struct s_ft_conv	t_ft_conv;
typedef struct s_type		t_type;
typedef struct s_get_type	t_get_type;
typedef struct s_params_a	t_params_a;

enum				e_types
{
	CHAR = 1,
	SHORT,
	INT,
	LONG,
	LONGLONG,

	UCHAR,
	USHORT,
	UINT,
	ULONG,
	ULONGLONG,

	SIZE_T,

	INTMAX_T,
	UINTMAX_T,

	DOUBLE,

	PTR_VOID,

	STRING,
	PTR_INT,

	WINT_T,
	STR_WCHAR_T,

	PERCENT
};

struct				s_buffer
{
	char			*buf;
	int				ind;
};

struct				s_conversion
{
	int				pos;
	char			*conversion;
	int				id_flags;
	int				type;
	char			char_conv;
	char			*pad;
	int				id_pad;
	int				width;
	int				prec;
	char			*mod;
	int				(*ft_conv)(t_buffer *, t_conversion, t_argument);
};

struct				s_argument
{
	union
	{
		intmax_t	d;
		uintmax_t	u;
		double		f;
		void		*p;
		char		*s;
		void		*n;
		wint_t		wc;
		wchar_t		*ws;
	}				u_arg;
	int				type;
};

struct				s_list_conv
{
	t_conversion	conv;
	t_list_conv		*next;
};

struct				s_list_arg
{
	t_argument		arg;
	t_list_arg		*next;
};

struct				s_ft_conv
{
	char			*str;
	int				(*ft_conv)(t_buffer *, t_conversion, t_argument);
};

struct				s_type
{
	int				type;
	void			(*ft_type)(va_list ap, t_list_arg *l_arg);
};

struct				s_get_type
{
	char			*mod;
	void			(*get_type)(t_conversion *);
};

struct				s_params_a
{
	uintmax_t		sign;
	intmax_t		exp;
	uintmax_t		mantissa;
	int				len;
	int				len_mantissa;
	int				fill_width;
	int				fill_prec;
};

int					ft_printf(const char *format, ...);
int					get_next_line(int fd, char **line);

/*
 ** storage/
*/

void				ft_stock_char(va_list ap, t_list_arg *list);
void				ft_stock_short(va_list ap, t_list_arg *list);
void				ft_stock_int(va_list ap, t_list_arg *list);
void				ft_stock_long(va_list ap, t_list_arg *list);
void				ft_stock_longlong(va_list ap, t_list_arg *list);
void				ft_stock_uchar(va_list ap, t_list_arg *list);
void				ft_stock_ushort(va_list ap, t_list_arg *list);
void				ft_stock_uint(va_list ap, t_list_arg *list);
void				ft_stock_ulong(va_list ap, t_list_arg *list);
void				ft_stock_ulonglong(va_list ap, t_list_arg *list);
void				ft_stock_size_t(va_list ap, t_list_arg *list);
void				ft_stock_intmax_t(va_list ap, t_list_arg *list);
void				ft_stock_uintmax_t(va_list ap, t_list_arg *list);
void				ft_stock_double(va_list ap, t_list_arg *list);
void				ft_stock_ptr(va_list ap, t_list_arg *list);
void				ft_stock_string(va_list ap, t_list_arg *list);
void				ft_stock_ptr_int(va_list ap, t_list_arg *list);
void				ft_stock_wint_t(va_list ap, t_list_arg *list);
void				ft_stock_str_wchar_t(va_list ap, t_list_arg *list);
void				ft_stock_usage(va_list ap, t_list_arg *list);

int					list_conv(t_list_conv **list, char *format);

int					is_flags(char c);
int					is_conv(char c);
void				get_ft_conv(t_conversion *conv);
void				get_type(t_conversion *conv);
int					get_flags(t_conversion *conv);

char				*get_padding(char *conv, int *i);
int					get_fieldwidth(char *conv, int *i);
int					get_precision(char *conv, int *i);
char				*get_modifyer(char *conv, int *i);
int					valid_modifyer(char *mod);

void				get_no_mod(t_conversion *conv);
void				get_hh(t_conversion *conv);
void				get_h(t_conversion *conv);
void				get_l(t_conversion *conv);
void				get_ll(t_conversion *conv);
void				get_j(t_conversion *conv);
void				get_z(t_conversion *conv);

t_list_arg			*create_list_args(int type, va_list ap);
int					add_list_args(t_list_arg *list, int type, va_list ap);
t_list_arg			*stock_args(t_list_conv *listconv, va_list ap);

int					get_buffer
	(const char *format, t_buffer *buffer, t_list_conv *listconv,
	t_list_arg *listarg);

/*
 ** fts_conv/
*/

int					ft_int
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_hexa
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_oct
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_uns
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_point
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_char
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_str
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_wchar
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_wstr
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_percent
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_n
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_binary
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_hexfloat
	(t_buffer *buffer, t_conversion conv, t_argument arg);
int					ft_usage
	(t_buffer *buffer, t_conversion conv, t_argument arg);

/*
 ** tools/
*/

void				unnormalized_nb(uintmax_t *mantissa, intmax_t *exp);
uintmax_t			arrondi(uintmax_t mantissa, int prec);
int					ft_put_hex
	(uintmax_t d, t_buffer *buffer, t_conversion conv);
int					floathex_length
	(uintmax_t d, t_conversion conv, int len_mantissa, intmax_t exp);
int					mantissa_length(uintmax_t mantissa);
int					nan_inf
	(uintmax_t sign, uintmax_t mantissa, t_conversion conv, t_buffer *buffer);

int					ft_putbuffer(char c, t_buffer *buffer);
int					ft_putstr_buff(char *s, t_buffer *buffer);
int					int_length(intmax_t n, uintmax_t base);
int					uint_length(uintmax_t n, uintmax_t base);
int					ft_putnbr_buff_base
	(intmax_t nb, uintmax_t base, int maj, t_buffer *buffer);
int					ft_putunbr_buff_base
	(uintmax_t nb, uintmax_t base, int maj, t_buffer *buffer);
int					bit_length(uintmax_t n, int lenbytes);

int					ft_wstrlen(wchar_t *ws);
int					ft_wstrlen_prec(wchar_t *ws, int prec);
int					ft_putwc_buff(t_buffer *buffer, wchar_t wc);
int					ft_putwstr_buff(t_buffer *buffer, wchar_t *ws);
int					ft_putwstr_prec(t_buffer *buffer, wchar_t *ws, int prec);
int					ft_strlen_prec(char *s, int prec);

/*
 ** bonuses/
*/

t_list_arg			*arg_dollar(t_conversion conv, t_list_arg *listarg);
int					is_flag_dollar(t_list_conv *list);
int					no_duplicates_dollar(t_list_conv *listconv);
int					valid_dollar(t_list_conv *list);
void				asterisk(t_conversion *conv, va_list ap);
t_list_arg			*stock_args_dollar(t_list_conv *listconv, va_list ap);
int					get_pos_max(t_list_conv *listconv);

#endif
