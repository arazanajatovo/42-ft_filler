/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:37:20 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:06:06 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*ft_fillstr(int neg, int len, int n)
{
	char			*str;
	unsigned int	nb;

	if (!(str = ft_strnew(len)))
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	nb = n < 0 ? n * -1 : n;
	str[len--] = '\0';
	while (len >= neg)
	{
		str[len--] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				len;
	int				neg;

	len = 0;
	neg = 0;
	if (n <= 0)
		len++;
	if (n < 0)
		neg = 1;
	nb = n < 0 ? n * -1 : n;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	if (!(str = ft_fillstr(neg, len, n)))
		return (NULL);
	return (str);
}
