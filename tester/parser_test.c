#include "Ctest.h"
#include "MiniRT.h"
#include <stdio.h>

t_rt	rt;

static int32_t	test_ambient(float intensity, t_FVec3 color)
{
	TEST_ASSERT(rt.ambient.intensity != intensity);
	TEST_ASSERT(rt.ambient.color.x != color.x);
	TEST_ASSERT(rt.ambient.color.y != color.y);
	TEST_ASSERT(rt.ambient.color.z != color.z);
	TEST_ASSERT(rt.ambient.active != true);
	return (true);
}

static int32_t	test_camera(int i, t_FVec3 pos, t_FVec3 rot, float fov)
{
	TEST_ASSERT(rt.cameras[i].transform.pos.x != pos.x);
	TEST_ASSERT(rt.cameras[i].transform.pos.y != pos.y);
	TEST_ASSERT(rt.cameras[i].transform.pos.z != pos.z);
	TEST_ASSERT(rt.cameras[i].transform.rot.x != rot.x);
	TEST_ASSERT(rt.cameras[i].transform.rot.y != rot.y);
	TEST_ASSERT(rt.cameras[i].transform.rot.z != rot.z);
	TEST_ASSERT(rt.cameras[i].fov == fov);
	return (true);
}

static int32_t	test_light(int i, t_FVec3 pos, t_FVec3 rot, float intensity, t_FVec3 color)
{
	TEST_ASSERT(rt.lights[i].transform.pos.x != pos.x);
	TEST_ASSERT(rt.lights[i].transform.pos.y != pos.y);
	TEST_ASSERT(rt.lights[i].transform.pos.z != pos.z);
	TEST_ASSERT(rt.lights[i].transform.rot.x != rot.x);
	TEST_ASSERT(rt.lights[i].transform.rot.y != rot.y);
	TEST_ASSERT(rt.lights[i].transform.rot.z != rot.z);
	TEST_ASSERT(rt.lights[i].intensity != intensity);
	TEST_ASSERT(rt.lights[i].color.x != color.x);
	TEST_ASSERT(rt.lights[i].color.y != color.y);
	TEST_ASSERT(rt.lights[i].color.z != color.z);
	return (true);
}

//static void	test_plane(int i, t_FVec3 pos, t_FVec3 rot, t_FVec3 color)
//{
//	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.pos.x == pos.x);
//	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.pos.y == pos.y);
//	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.pos.z == pos.z);
//	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.rot.x == rot.x);
//	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.rot.y == rot.y);
//	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.rot.z == rot.z);
//	TEST_ASSERT(rt.objects[i].entity_plane.base.color.x == color.x);
//	TEST_ASSERT(rt.objects[i].entity_plane.base.color.y == color.y);
//	TEST_ASSERT(rt.objects[i].entity_plane.base.color.z == color.z);
//	return ;
//}

static int32_t	test_sphere(int i, t_FVec3 pos, float diameter, t_FVec3 color)
{
	TEST_ASSERT(rt.objects[i].entity_sphere.base.transform.pos.x != pos.x);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.transform.pos.y != pos.y);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.transform.pos.z != pos.z);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.color.x != color.x);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.color.y != color.y);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.color.z != color.z);
	TEST_ASSERT(rt.objects[i].entity_sphere.diameter != diameter);	
	return (true);
}

//static void	test_cylinder(int i, t_FVec3 pos, t_FVec3 rot, float diameter, float height, t_FVec3 color)
//{
//	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.pos.x == pos.x);
//	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.pos.y == pos.y);
//	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.pos.z == pos.z);
//	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.rot.x == rot.x);
//	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.rot.y == rot.y);
//	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.rot.z == rot.z);
//	TEST_ASSERT(rt.objects[i].entity_cylinder.base.color.x == color.x);
//	TEST_ASSERT(rt.objects[i].entity_cylinder.base.color.y == color.y);
//	TEST_ASSERT(rt.objects[i].entity_cylinder.base.color.z == color.z);
//	TEST_ASSERT(rt.objects[i].entity_cylinder.diameter == diameter);	
//	TEST_ASSERT(rt.objects[i].entity_cylinder.height == height);	
//	return ;
//}

//static void	test_triangle(int i, t_FVec3 vert1, t_FVec3 vert2, t_FVec3 vert3, t_FVec3 color)
//{
//	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[0].x == vert1.x);
//	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[0].y == vert1.y);
//	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[0].z == vert1.z);
//	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[1].x == vert2.x);
//	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[1].y == vert2.y);
//	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[1].z == vert2.z);
//	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[2].x == vert3.x);
//	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[2].y == vert3.y);
//	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[2].z == vert3.z);
//	TEST_ASSERT(rt.objects[i].entity_triangle.color.x == color.x);
//	TEST_ASSERT(rt.objects[i].entity_triangle.color.y == color.y);
//	TEST_ASSERT(rt.objects[i].entity_triangle.color.z == color.z);
//	return ;
//}

TEST_DECLARE(ambient)
{
	// Test ambient; Only one per map, otherwise init_entities will fail
	// 1st param: intensity
	// 2nd param: color
	return (test_ambient(0.2, new_fvec3(255, 255, 255)));
}

TEST_DECLARE(camera)
{
	// Test camera(s)
	// 1st param: ith camera, starting at 0
	// 2nd param: position
	// 3rd param: rotation
	// 4th param: field of view
	return (test_camera(0, new_fvec3(-50, 0, 20), new_fvec3(0, 0, 0), 70)); 
}

TEST_DECLARE(light)
{
	// Test light(s)
	// 1st param: ith light, starting at 0
	// 2nd param: position
	// 3rd param: rotation
	// 4th param: intensity
	// 5th param: color
	return (test_light(0, new_fvec3(-40, 0, 30), new_fvec3(0, 0, 0), 0.7, new_fvec3(255, 255, 255)));
}

TEST_DECLARE(sphere)
{
	// Test object(s); Plane, Sphere, Cylinder
	// 1st param: ith object, starting at 0
	// 2nd param: position
	// 3rd param: rotation
	// 4th param: color
	// 5th param: diameter (only for sphere & cylinder)
	// 6th param: height (only for cylinder)
	return (test_sphere(0, new_fvec3(0, 0, 2), 0.5, new_fvec3(255, 0, 0)));
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (!argv[1])
	{
		printf("Missing input map");
		return (EXIT_FAILURE);
	}
	init_entities(&rt, argv[1]);
	puts("\n");
	//printf("int: %f, x: %f, y: %f, z: %f\n", rt.ambient.intensity, rt.ambient.color.x, rt.ambient.color.y, rt.ambient.color.z);
	TEST_RUN(UNIT_ambient, false);
	TEST_RUN(UNIT_light, false);
	TEST_RUN(UNIT_camera, false);
	TEST_RUN(UNIT_sphere, false);
	return (EXIT_SUCCESS);
}
