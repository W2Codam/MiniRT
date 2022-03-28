/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 10:46:08 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 14:19:48 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_pow(int32_t base, int32_t exp)
{
	if (exp > 0)
		return (base * ft_pow(base, exp - 1));
	return (1);
}
