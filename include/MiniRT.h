/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:06:20 by lde-la-h      #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2022/04/04 14:43:47 by dvan-der         ###   ########.fr       */
=======
/*   Updated: 2022/04/04 10:42:23 by lde-la-h      ########   odam.nl         */
>>>>>>> b88448d3112d9f10a53fd381d478512c64ca7c01
/*                                                                            */
/* ************************************************************************** */

/*
  __  __                      ____  _____ 
 |  \/  |  ___   __ _   __ _ |  _ \|_   _|
 | |\/| | / _ \ / _` | / _` || |_) | | |  
 | |  | ||  __/| (_| || (_| ||  _ <  | |  
 |_|  |_| \___| \__, | \__,_||_| \_\ |_|  
                |___/                     

Balls to the walls cross-platform, multi-threaded stud Raytracer on the CPU!
Written by W2.Wizard (lde-la-h) & Daan Van Der Plas (dvan-der) @ 2022
*/

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <memory.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <errno.h>
# include "libft.h"
# include "lib3d.h"
# include "MLX42/MLX42.h"
# define STD_WIDTH		1080
# define STD_HEIGHT		720
# define MAX_OBJS		100
# define MAX_CAMERAS	10

//= Types =//

// Types of entities that exist.
typedef enum e_EntityType
{
	CAMERA,
	LIGHT,
	AMBIENTLIGHT,
	SPHERE,
	CYLINDER,
	PLANE,
	TRIANGLE,
}	t_EntityType;

// Types of entities that exist.
typedef enum e_MaterialType
{
	DIFFUSE,
	METAL,
	TRANSLUCENT,
}	t_MaterialType;

/**
 * A transform that encompasses both rotation and
 * scale.
 */
typedef struct s_Transform
{
	t_FVec3	pos;
	t_FVec3	rot;
}	t_Transform;

/**
 * Base entity object, which is anything that exists in 3D space.
 * 
 * @param type The specific type of entity.
 * @param transform 3D transform in world space of the entity.
 * @param color Optional color param.
 */
typedef struct s_Entity
{
	t_Transform	transform;
	t_FVec4		color;
}	t_Entity;

/**
 * Camera object stores, position, orientation and fov, is NOT an entity!
 * 
 * @param pos The position in 3D world space.
 * @param rot The rotation in 3D world space.
 * @param fov The field of view [0 - 180].
 */
typedef struct s_Camera
{
	t_Transform	transform;
	int32_t		fov;
}	t_Camera;

/**
 * A light source.
 * 
 * @param transform The angle of the light source.
 * @param intensity Scalar value defining intensity of light.
 * @param color Light color.
 */
typedef struct s_Light
{
	t_Entity	base;
	float		intensity;
}	t_Light;

typedef struct s_SphereModel
{
	t_Entity	base;
	float		radius;
}	t_SphereModel;

typedef struct s_PlaneModel
{
	t_Entity	base;
}	t_PlaneModel;

typedef struct s_TriangleModel
{
	t_Entity	base;
	t_FVec3		vertices[3];
}	t_TriangleModel;

typedef struct s_CylinderModel
{
	t_Entity	base;
	float		height;
	float		diameter;
}	t_CylinderModel;

/**
 * Instance class of an entity, that is, something that needs to be
 * rendered.
 * 
 * @param type The type of entity.
 * @param union The different available types of entities.
 */
typedef struct s_EntityObject
{
	t_EntityType	type;
	t_MaterialType	material;

	union
	{
		t_Light			entity_light;
		t_SphereModel	entity_sphere;
		t_PlaneModel	entity_plane;
		t_CylinderModel	entity_cylinder;
		t_TriangleModel	entity_triangle;
	};
}	t_EntityObject;

/**
 * Struct that contains the application state. Including the current level.
 * 
 * @param mlx MLX42 instance handle.
 * @param render_thread The thread that does the pixel updating.
 */
typedef struct s_rt
{
	mlx_t			*mlx;
	mlx_image_t		*window_img;
	pthread_t		render_thread;

	int32_t			active_camera;
	t_Camera		cameras[MAX_CAMERAS];

	t_EntityObject	objects[MAX_OBJS];
	size_t			cameras_size;
	size_t			objects_size;

}	t_rt;

//= Functions =//

#endif // MINIRT_H
