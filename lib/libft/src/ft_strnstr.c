/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 18:08:42 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 14:20:42 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t ln)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little || !*little)
		return ((char *)big);
	while (big[i] != '\0' && i < ln)
	{
		while (big[i + j] == little[j] && i + j < ln)
		{
			if (little[++j] == '\0')
				return (&((char *)big)[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
