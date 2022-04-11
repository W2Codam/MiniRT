/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 19:30:49 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/11 12:49:28 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static void	ft_make_tlc(t_Camera *camera)
{
	t_FVec3	a;
	t_FVec3	b;
	t_FVec3	c;

	c = new_fvec3(0, 0, camera->fov);
	a = sub_vec3(camera->transform.pos, div_fvec3(camera->horizontal, 2));
	b = sub_vec3(a, div_fvec3(camera->vertical, 2));
	camera->top_left = sub_vec3(b, c);
}

//= Public =//

t_Camera	*ft_get_active_camera(t_rt *rt)
{
	return (&rt->cameras[rt->active_camera]);
}

// TODO: Add rotation
void	ft_new_camera(t_Camera *Camera, float FOV, t_FVec3 pos)
{
	const float		aspect_ratio = (16.0f / 9.0f);

	Camera->fov = FOV;
	Camera->transform.pos = pos;
	Camera->viewport.y = 2.0f;
	Camera->viewport.x = aspect_ratio * Camera->viewport.y;
	Camera->horizontal = new_fvec3(Camera->viewport.x, 0, 0);
	Camera->vertical = new_fvec3(0, Camera->viewport.y, 0);
	ft_make_tlc(Camera);
}
