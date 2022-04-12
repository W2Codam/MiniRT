#include "lib3d.h"

t_FVec3	ft_rotate(t_FVec3 vec, t_FVec3 k, float angle)
{
	t_FVec3	temp1;
	t_FVec3 temp2;
	t_FVec3 temp3;
	t_FVec3	result;

	if (angle == 0)
		return (vec);
	term1 = ft_mul_fvec3(vec, cos(angle));
	term2 = ft_mul_fvec3(ft_cross_fvec3(k, vec), sin(angle));
	term3 = ft_mul_fvec3(k, (ft_dot_fvec3(k, vec) * (1 - cos(angle))));
	result = ft_add_fvec3(term1, term2);
	result = ft_add_fvec3(result, term3);
	return (result);
}

bool	ft_abc(float a, float b, float c, float *distance)
{
	float	d;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (false);
	else
	{
		*distance = ((-b -sqrt(d)) / (2.0 * a));
		return (true);
	}
}
