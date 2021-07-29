#pragma once

#include <cstdarg>

#ifdef DEBUG
#include <string>
// function defines for debug
void debug_printf(const std::string& fmt, ...);


#endif // DEBUG

#define DEBUG_CALL_FUNC(f) #ifdef DEBUG \
f\
#endif

#define debug_function(f) DEBUG_CALL_FUNC(f)