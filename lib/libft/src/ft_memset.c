/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 10:48:14 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 14:20:42 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int32_t c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((uint8_t *)b)[i] = (uint8_t)c;
		i++;
	}
	return (b);
}
