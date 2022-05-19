/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:39:28 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/19 13:41:02 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int32_t n, t_base base)
{
	char	*out;
	char	*hex;
	int32_t	numlen;

	if (!n)
		return (ft_strdup("0"));
	hex = "0123456789ABCDEF";
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
		out[--numlen] = hex[n % base];
		n /= base;
	}
	return (out);
}
