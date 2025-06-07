#pragma once

#ifdef _WIN32
#include <windows.h>
#define EXPORT __declspec(dllexport)
#else
#endif

typedef unsigned char byte;            ///< 8-bit unsigned integer
typedef long long longlong;            ///< 64-bit signed integer
typedef unsigned char uchar;           ///< 8-bit unsigned integer
typedef unsigned int uint;             ///< 32-bit unsigned integer
typedef unsigned long ulong;           ///< 32-bit unsigned integer
typedef unsigned long long ulonglong;  ///< 64-bit unsigned integer
typedef unsigned char undefined;       ///< 8-bit unsigned integer
typedef unsigned char undefined1;      ///< 8-bit unsigned integer
typedef unsigned short undefined2;     ///< 16-bit unsigned integer
typedef unsigned long undefined4;      ///< 32-bit unsigned integer
typedef unsigned long long undefined8; ///< 64-bit unsigned integer
typedef unsigned short ushort;         ///< 16-bit unsigned integer

/// @brief Carries out a 4-bit addition with carry-in.
#define CARRY4(x, y, carry_in) ((((x) + (y) + (carry_in)) >> 4) & 1)

/// @brief Concatenates two 8-bit values into a 16-bit value.
#define CONCAT11(a, b) ((ushort)(a) << 8 | (ushort)(b))

/// @brief Concatenates the most significant byte of a 32-bit value with the least significant 3
/// bytes of another 32-bit value.
#define CONCAT13(msb1, lsb3) (((uint)(msb1) << 24) | ((uint)(lsb3) & 0xFFFFFF))

/// @brief Concatenates the most significant byte of a 32-bit value with the least significant 3
/// bytes of another 32-bit value.
#define CONCAT22(a, b) ((ulong)(a) << 16 | (ulong)(b))

/// @brief Concatenates the most significant byte of a 32-bit value with the least significant byte
/// of another 32-bit value.
#define CONCAT31(msb3, lsb1) (((uint)(msb3) << 8) | ((uint)(lsb1) & 0xFF))

/// @brief Concatenates two 32-bit unsigned integers into a 64-bit unsigned integer.
#define CONCAT44(a, b) ((ulonglong)(a) << 32 | (ulonglong)(b))

/// @brief Subtracts two 32-bit unsigned integers.
#define SUB41(a, b) ((uint)((uint)(a) - (uint)(b)))

/// @brief Marks a variable as unused to avoid compiler warnings.
#define UNUSED(x) (void)(x)
