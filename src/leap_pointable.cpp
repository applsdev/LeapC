/*
 * C wrapper around the Leap Motion library.
 * Copyright (c) 2013, Camille Troillard. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an "AS
 * IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied.  See the License for the specific language
 * governing permissions and limitations under the License.
 *
 */

#include "Leap.h"
#include "leap_utils.hpp"
#include "leap_pointable_private.hpp"

struct leap_pointable
{
public:
    leap_pointable(Leap::Pointable const& pointable) : wrap(pointable) {}
    Leap::Pointable wrap;
};

leap_pointable_ref leap_pointable_new(Leap::Pointable const& pointable)
{
    return new leap_pointable(pointable);
}

void leap_pointable_delete(leap_pointable_ref pointable)
{
    delete pointable;
}

int32_t leap_pointable_id(leap_pointable_ref pointable)
{
    return W(pointable).id();
}

leap_vector leap_pointable_tip_position(leap_pointable_ref pointable)
{
    return to_leap_vector(W(pointable).tipPosition());
}

leap_vector leap_pointable_tip_velocity(leap_pointable_ref pointable)
{
    return to_leap_vector(W(pointable).tipVelocity());
}

leap_vector leap_pointable_direction(leap_pointable_ref pointable)
{
    return to_leap_vector(W(pointable).direction());
}

float leap_pointable_width(leap_pointable_ref pointable)
{
    return W(pointable).width();
}

float leap_pointable_length(leap_pointable_ref pointable)
{
    return W(pointable).length();
}

int leap_pointable_is_tool(leap_pointable_ref pointable)
{
    return bool_as_int(W(pointable).isTool());
}

int leap_pointable_is_finger(leap_pointable_ref pointable)
{
    return bool_as_int(W(pointable).isFinger());
}

int leap_pointable_is_valid(leap_pointable_ref pointable)
{
    return bool_as_int(W(pointable).isValid());
}

int leap_pointable_equal(leap_pointable_ref pointable, leap_pointable_ref other)
{
    return bool_as_int(W(pointable) == W(other));
}
