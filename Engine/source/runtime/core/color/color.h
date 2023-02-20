#pragma once

#include "runtime/core/math/vector3.h"

namespace Dream
{
    class Color
    {
    public:
        float r;
        float g;
        float b;

        Vector3 toVector3() const { return Vector3(r, g, b); }
    };
}