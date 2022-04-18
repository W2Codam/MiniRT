/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: W2Wizard <w2.wizzard@gmail.com>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 17:04:13 by W2Wizard      #+#    #+#                 */
/*   Updated: 2022/04/18 17:06:06 by W2Wizard      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	ft_muls_color(t_FVec3 a, t_FVec3 b, float s)
{
	a.x *= (b.x * s / 255);
	a.y *= (b.y * s / 255);
	a.z *= (b.z * s / 255);
	return (a);
}
