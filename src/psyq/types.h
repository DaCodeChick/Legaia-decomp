#pragma once

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

typedef unsigned short u_short; ///< Unsigned 16-bit integer
typedef unsigned long u_long;   ///< Unsigned 32-bit integer
