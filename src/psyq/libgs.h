#pragma once

#include "libgte.h"

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief Vertex structure for 3D graphics.
	typedef struct
	{
		short vx;    ///< Vertex x-coordinate
		short vy;    ///< Vertex y-coordinate
		short vz;    ///< Vertex z-coordinate
		u_char tu;   ///< Texture u-coordinate
		u_char tv;   ///< Texture v-coordinate
		CVECTOR col; ///< Vertex color
	} VERTC;

#ifdef __cplusplus
}
#endif
