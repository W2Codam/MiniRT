/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:26:52 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/06 09:00:35 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_atoi(const char *str)
{
	int32_t	nbr;
	size_t	i;
	int32_t	neg;

	i = 0;
	neg = 1;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * neg);
}
