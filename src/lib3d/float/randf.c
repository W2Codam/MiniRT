/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randf.c                                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 12:56:38 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 11:16:09 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

//= Public =//

float	ft_randf_r(float min, float max)
{
	const float	div = RAND_MAX / (max - min);

	return (min + (rand() / div));
}

float	ft_randf(void)
{
	return (ft_randf_r(0.0f, 1.0f));
}
