/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 17:37:25 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 18:02:36 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct			s_flag
{
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					gl;
}						t_flag;

typedef struct			s_opt
{
	int					minus;
	int					plus;
	int					hash;
	int					zero;
	int					space;
}						t_opt;

typedef struct			s_input
{
	void				*p;
	long long			i;
	unsigned long long	u;
	unsigned char		c;
	char				*str;
	long double			f;
}						t_input;

typedef struct			s_pars
{
	char				type;
	int					nb;
	int					b_acc;
	int					acc;
	int					b_width;
	int					width;
	int					ret;
	int					neg;
	t_opt				opt;
	int					b_flag;
	t_flag				flag;
	t_input				input;
}						t_pars;

typedef	struct			s_func
{
	char				type[13];
	int					base[13];
	void				(*f_get[13])(va_list ap, struct s_func, struct s_pars*);
	int					(*f[13])(struct s_func, struct s_pars *);
	int					(*f_print[13])(struct s_func, struct s_pars *);
}						t_func;

char					*ft_char_supp(t_pars *pars);
char					*ft_width_int(t_pars pars, char *str);
char					*ft_acc_int(t_pars pars, char *str);
int						ft_char(t_func tab, t_pars *pars);
int						ft_check_flag(const char *c, t_pars *pars);
int						ft_check_opt(const char c, t_pars *pars);
int						ft_check_type(const char c, t_pars *pars);
int						ft_str(t_func tab, t_pars *pars);
int						ft_int(t_func tab, t_pars *pars);
int						ft_float(t_func tab, t_pars *pars);
int						ft_uint(t_func tab, t_pars *pars);
char					*ft_width_int(t_pars pars, char *str);
char					*ft_litoa_base(long long value, int base, t_pars pars);
char					*ft_ulitoa_base(unsigned long long value,
		int base, t_pars pars);
char					*ft_strjoin_clean(char *dest, char *src, int b);
void					ft_get_int(va_list ap, t_func tab, t_pars *pars);
void					ft_get_uint(va_list ap, t_func tab, t_pars *pars);
void					ft_get_double(va_list ap, t_func tab, t_pars *pars);
void					ft_get_single(va_list ap, t_func tab, t_pars *pars);
int						ft_printf(const char *format, ...);
void					ft_init_tab(t_func *tab);
void					ft_init_pars(t_pars *pars);
void					ft_init_opt(t_pars *pars);
int						parse_it(const char *format, t_pars *pars,
		t_func tab, va_list ap);
void					option_cancel(t_pars *pars);
int						ft_check_opt(const char c, t_pars *pars);
int						ft_check_flag(const char *c, t_pars *pars);
int						ft_check_type(const char c, t_pars *pars);
int						ft_special_float(t_pars *pars);
int						ft_iseven(char c);
#endif
