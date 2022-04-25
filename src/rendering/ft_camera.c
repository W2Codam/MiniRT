/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:12:52 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/25 11:22:06 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Public =//

t_Camera    *ft_get_active_camera(t_RT *rt)
{
    return (&rt->world.cameras[rt->camera_index]);
}

void   		ft_update_camera(t_Camera *camera, t_FVec3 pos, t_FVec3 dir[3], float fov)
{
	camera->position = pos;
	camera->rotation_matrix[0] = dir[0];
	camera->rotation_matrix[1] = dir[1];
	camera->rotation_matrix[2] = dir[2];
	camera->fov = fov;
}
