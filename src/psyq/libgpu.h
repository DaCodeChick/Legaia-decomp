#pragma once

#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief Represents a rectangle.
	typedef struct
	{
		short x; /// < The x-coordinate of the rectangle's top-left corner
		short y; /// < The y-coordinate of the rectangle's top-left corner
		short w; /// < The width of the rectangle
		short h; /// < The height of the rectangle
	} RECT;

	/**
	 * @brief Get the color lookup table (CLUT) value at the specified coordinates.
	 *
	 * @param x The x-coordinate.
	 * @param y The y-coordinate.
	 * @return The CLUT value at the specified coordinates.
	 */
	EXPORT u_short GetClut(int x, int y);

#ifdef __cplusplus
}
#endif