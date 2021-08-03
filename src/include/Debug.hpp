#pragma once

#include <cstdarg>

#ifdef DEBUG
#include <string>
// function defines for debug
void debug_printf(const std::string& fmt, ...);


#endif // DEBUG


#define debug_function(f) DEBUG_CALL_FUNC(f)