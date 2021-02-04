/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prinft.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 17:25:50 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/22 07:06:46 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_check_color2(char *color)
{
	int	b;

	b = 0;
	if (!ft_strcmp(color, "mag") && (b = 1))
		ft_printf("\033[35m");
	else if (!ft_strcmp(color, "cyn") && (b = 1))
		ft_printf("\033[36m");
	else if (!ft_strcmp(color, "bred") && (b = 1))
		ft_printf("\033[41m");
	else if (!ft_strcmp(color, "bgrn") && (b = 1))
		ft_printf("\033[42m");
	else if (!ft_strcmp(color, "byel") && (b = 1))
		ft_printf("\033[43m");
	else if (!ft_strcmp(color, "bblu") && (b = 1))
		ft_printf("\033[44m");
	else if (!ft_strcmp(color, "bmag") && (b = 1))
		ft_printf("\033[45m");
	else if (!ft_strcmp(color, "bcyn") && (b = 1))
		ft_printf("\033[46m");
	return (b);
}

int		ft_check_color(char *color)
{
	int b;

	b = 0;
	if (!ft_strcmp(color, "eoc") && (b = 1))
		ft_printf("\033[0m");
	else if (!ft_strcmp(color, "b") && (b = 1))
		ft_printf("\033[1m");
	else if (!ft_strcmp(color, "gre") && (b = 1))
		ft_printf("\033[2m");
	else if (!ft_strcmp(color, "i") && (b = 1))
		ft_printf("\033[3m");
	else if (!ft_strcmp(color, "u") && (b = 1))
		ft_printf("\033[4m");
	else if (!ft_strcmp(color, "red") && (b = 1))
		ft_printf("\033[31m");
	else if (!ft_strcmp(color, "grn") && (b = 1))
		ft_printf("\033[32m");
	else if (!ft_strcmp(color, "yel") && (b = 1))
		ft_printf("\033[33m");
	else if (!ft_strcmp(color, "blu") && (b = 1))
		ft_printf("\033[34m");
	else
		b = ft_check_color2(color);
	free(color);
	return (b);
}

int		ft_color(const char *format, t_pars *pars)
{
	int		i;
	char	*color;
	char	*join;

	i = 1;
	color = NULL;
	if (!(color = ft_strnew(0)))
		return (0);
	if (!(join = ft_strnew(1)))
		return (0);
	while (format[i] && format[i] != '}')
	{
		join[0] = format[i++];
		if (!(color = ft_strjoin_clean(color, join, 1)))
			return (0);
	}
	free(join);
	if (format[i] == '}' && ft_check_color(color))
		return (i);
	write(1, "{", 1);
	(*pars).ret++;
	return (0);
}

int		ft_perc(t_pars *pars, t_func tab, const char **format, va_list ap)
{
	if (**format == '{')
		*format += ft_color(*format, pars) + 1;
	else
	{
		ft_init_pars(pars);
		(*format)++;
		*format += parse_it(*format, pars, tab, ap);
		while (tab.type[(*pars).nb] && (*pars).type != tab.type[(*pars).nb])
			(*pars).nb++;
		if ((*pars).nb <= 11)
		{
			tab.f_get[(*pars).nb](ap, tab, pars);
			option_cancel(pars);
			if (!(tab.f[(*pars).nb](tab, pars)))
				return (0);
		}
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_pars	pars;
	t_func	tab;

	pars.ret = 0;
	ft_init_tab(&tab);
	va_start(ap, format);
	if (!(format))
		return (-1);
	while (*format)
	{
		while (*format && *format != '%' && *format != '{')
		{
			write(1, format++, 1);
			pars.ret++;
		}
		if (*format)
		{
			if (!(ft_perc(&pars, tab, &format, ap)))
				return (-1);
		}
	}
	va_end(ap);
	return (pars.ret);
}
