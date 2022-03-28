/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:39:28 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 14:19:48 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int32_t n, t_base base)
{
	char	*out;
	char	*HEX;
	int32_t	numlen;

	if (!n)
		return (ft_strdup("0"));
	HEX = "0123456789ABCDEF";
	numlen = ft_intlen(n, base);
	if (n < 0)
		numlen++;
	out = ft_calloc(numlen + 1, sizeof(char));
	if (!out)
		return (NULL);
	if (n < 0)
	{
		out[0] = '-';
		n = ft_abs(n);
	}
	while (n)
	{
		out[--numlen] = HEX[n % base];
		n /= base;
	}
	return (out);
}
