/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 09:57:39 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 14:20:42 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*out;

	i = 0;
	if (!f)
		return (NULL);
	out = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!out)
		return (NULL);
	while (s[i] != '\0')
	{
		out[i] = f(s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
