/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:43:58 by vkravets          #+#    #+#             */
/*   Updated: 2018/01/12 13:44:03 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPEC0(a) (a == 's' || a == 'S' || a == 'p' || a == 'd' || a == 'D')
# define SPEC1(a) (a == 'i' || a == 'o' || a == 'O' || a == 'u' || a == 'U')
# define SPEC2(a) (a == 'X' || a == 'c' || a == 'C'|| a == '%' || a == 'x')
# define SPEC(a) (SPEC0(a) || SPEC1(a) || SPEC2(a))
# define INV0(b) (b != 's' && b != 'S' && b != 'p' && b != 'd' && b != 'D')
# define INV1(b) (b != 'i' && b != 'o' && b != 'O' && b != 'u' && b != 'U')
# define INV2(b) ( b != 'x' && b != 'X' && b != 'c' && b != 'C' && b != '.')
# define INV3(b) ( b != '-' && b != ' ' && b != '#' && b != '%' && b != '+' )
# define INVALID(b) (INV0(b) && INV1(b) && INV2(b) && INV3(b) && b != '*')

# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <locale.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flags
{
	int			plus;
	int			minus;
	int			space;
	int			hash;
	int			zero;
	int			val_wid;
	int			val_pr;
	char		md;
	char		specifier;
	char		sig;
	char		interest;
	int			value_for_return;
	int			count_bit;
	int			reserv;
	int			null;
}				t_flags;
char			*ft_itoa_base_for_x(uint64_t v, char c, t_flags *flag, int i);
void			ft_format_acord_fl_x(char *s, t_flags *flag, char x);
uint64_t		ft_rec(int base, int i);
int				ft_atoi(const char *str);
void			ft_memdel(void **ap);
void			ft_putstr(char const *s);
int				ft_isdigit(int c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memset(void *dest, int c, size_t cnt);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_printf(char *fmt, ...);
int				ft_main_string(char *str, va_list *ap, t_flags *flag);
void			ft_check_flag(char *str, t_flags *flag, int *i);
void			ft_check_wid(char *str, t_flags *flag, int *i, va_list *ap);
void			ft_check_modifiers(char *str, t_flags *flag, int *i);
void			ft_check_specifier(char *str, t_flags *flag, int *i);
void			ft_kind_specifier(va_list *ap, t_flags *flag);
int				ft_check_cpec_su(va_list *ap, t_flags *flag);
void			ft_subfunc_for_11(char print[5], unsigned int i);
void			ft_subfunc_for_16(char print[5], unsigned int i);
void			ft_subfunc_for_else(char print[5], unsigned int i);
void			ft_print_cpec_su(unsigned int *spec_su, t_flags *flag);
void			ft_for_cpec_s(va_list *ap, t_flags *flag);
int				ft_check_cpec_chu(va_list *ap, t_flags *flag);
void			ft_for_spec_c(va_list *ap, t_flags *flag);
intmax_t		ft_check_and_ret_value(t_flags *flag, intmax_t value);
char			*ft_modif_itoa_for_sign_spec(intmax_t n, t_flags *flag);
void			ft_format_acord_flags(char *s, t_flags *flag);
void			ft_for_spec_d(va_list *ap, t_flags *flag);
void			ft_for_spec_dl(va_list *ap, t_flags *flag);
void			ft_for_spec_i(va_list *ap, t_flags *flag);
uint64_t		ft_check_and_ret_value_u(t_flags *flag, uint64_t value);
char			*ft_modif_itoa_for_unsign_spec(uint64_t n);
void			ft_for_spec_u(va_list *ap, t_flags *flag);
void			ft_for_spec_ul(va_list *ap, t_flags *flag);
void			ft_for_spec_x(va_list *ap, t_flags *flag);
void			ft_for_spec_xl(va_list *ap, t_flags *flag);
void			ft_for_spec_o(va_list *ap, t_flags *flag);
void			ft_for_spec_ol(va_list *ap, t_flags *flag);
void			ft_for_spec_p(va_list *ap, t_flags *flag);
void			ft_check_interest(t_flags *flag);

#endif
