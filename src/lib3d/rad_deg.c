/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rad_deg.c                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:30:39 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/21 13:45:44 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

float	ft_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}

float	ft_to_deg(float rad)
{
	return (rad * (180 / M_PI));
}
