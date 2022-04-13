/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isempty.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:55:34 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 13:57:17 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isempty(const char *str)
{
	size_t			i;
	const size_t	len = ft_strlen(str);

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i == len);
}
