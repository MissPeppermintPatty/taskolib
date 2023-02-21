/**
 * \file   test_TriggerTimeout.cc
 * \author Marcus Walla
 * \date   Created on February 21, 2023
 * \brief  Test suite for the TriggerTimeout class.
 *
 * \copyright Copyright 2022 Deutsches Elektronen-Synchrotron (DESY), Hamburg
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 2.1 of the license, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// SPDX-License-Identifier: LGPL-2.1-or-later

#include <gul14/catch.h>

#include "taskolib/TimeoutTrigger.h"

using namespace std::literals;
using namespace task;

TEST_CASE("Default constructor", "[TimeoutTrigger]")
{
    static_assert(std::is_default_constructible<TimeoutTrigger>::value,
        "TimeoutTrigger is_default_constructible");
    static_assert(std::is_trivially_destructible<TimeoutTrigger>::value,
        "TimeoutTrigger is_trivially_destructible");

    TimeoutTrigger timeout_trigger;
    REQUIRE(timeout_trigger.get_start_time().time_since_epoch().count() == 0L);
}

TEST_CASE("Default copy", "[TimeoutTrigger]")
{
    static_assert(std::is_copy_constructible<TimeoutTrigger>::value,
        "TimeoutTrigger is_copy_constructible");
    static_assert(std::is_copy_assignable<TimeoutTrigger>::value,
        "TimeoutTrigger is_copy_assignable");

    TimeoutTrigger timeout_trigger;

    SECTION("copy constructable")
    {
        TimeoutTrigger timeout_trigger_copy = timeout_trigger;
        timeout_trigger_copy.reset(1ms);

        REQUIRE(timeout_trigger.get_start_time().time_since_epoch().count() == 0L);
        REQUIRE(timeout_trigger_copy.get_start_time().time_since_epoch().count() != 0L);
    }

    SECTION("copy assignable")
    {
        TimeoutTrigger timeout_trigger_assigned{timeout_trigger};
        timeout_trigger_assigned.reset(1ms);

        REQUIRE(timeout_trigger.get_start_time().time_since_epoch().count() == 0L);
        REQUIRE(timeout_trigger_assigned.get_start_time().time_since_epoch().count()
                != 0L);
    }
}