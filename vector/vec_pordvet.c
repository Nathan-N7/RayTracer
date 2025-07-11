#include "vector.h"

t_vec   vec_prodvec(t_vec a, t_vec b)
{
    t_vec   r;

    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x *b.z;
    r.z = a.x * b.y - a.y * b.x;

    return (r);
}