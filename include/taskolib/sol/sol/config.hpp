// The MIT License (MIT)

// Copyright (c) 2013-2020 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_SINGLE_CONFIG_HPP
#define SOL_SINGLE_CONFIG_HPP

// beginning of sol/config.hpp

/*
Configuration values can be seen in the safety.rst of the Sol3 doc/src, or at
https://sol2.readthedocs.io/en/latest/safety.html ! You can also pass them through
the build system, or the command line options of your compiler.
*/

// Tell Sol3 that we are using a custom LUA build that was compiled with C++ and therefore
// properly handles exceptions.
#define SOL_USING_CXX_LUA 1

// Enable a trampoline for C/C++ functions injected into Lua (among other things)
#define SOL_PROPAGATE_EXCEPTIONS 0

// Tell Sol3 to make several checks so that we can actually differentiate integers from
// floating-point numbers.
#define SOL_SAFE_NUMERICS 1

// Do not produce console output on certain errors
#define SOL_PRINT_ERRORS 0

// Enable maximum amount of safety checks (for instance, this enables somewhat meaningful
// error messages if strange C++ exceptions that are not derived from std::exception are
// thrown during Lua script execution)
#define SOL_ALL_SAFETIES_ON 1

// end of sol/config.hpp

#endif // SOL_SINGLE_CONFIG_HPP
