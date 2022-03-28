/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 10:45:06 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 14:19:48 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_min(int32_t valA, int32_t valB)
{
	return (valA * (valA <= valB) + valB * (valB < valA));
}
