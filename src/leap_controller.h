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

#ifndef LeapC_leap_controller_h
#define LeapC_leap_controller_h

#include "leap_types.h"

#ifdef __cplusplus
extern "C" {
#endif

    // Controller
    leap_controller_ref leap_controller_new();
    void leap_controller_delete(leap_controller_ref controller);
    int leap_controller_is_connected(leap_controller_ref controller);
    leap_frame_ref leap_controller_copy_frame(leap_controller_ref controller, int history);
    void leap_controller_add_listener(leap_controller_ref controller, leap_listener_ref listener);
    void leap_controller_remove_listener(leap_controller_ref controller, leap_listener_ref listener);

    // Listener
    typedef void (*leap_controller_callback)(leap_controller_ref, void*);

    struct leap_controller_callbacks {
        leap_controller_callback on_init;
        leap_controller_callback on_connect;
        leap_controller_callback on_disconnect;
        leap_controller_callback on_exit;
        leap_controller_callback on_frame;
    };

    leap_listener_ref leap_listener_new(struct leap_controller_callbacks* callbacks, void *user_info);
    void leap_listener_delete(leap_listener_ref listener);

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif
