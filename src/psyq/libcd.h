#pragma once

#include "../typedefs.h"
#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief CD-ROM data structure for the CD-ROM location.
	typedef struct
	{
		u_char minute; ///< The minute of the CD-ROM location (0-74).
		u_char second; ///< The second of the CD-ROM location (0-59).
		u_char sector; ///< The sector of the CD-ROM location (0-235).
		u_char track;  ///< The track of the CD-ROM location (1-99).
	} CdlLOC;

	/**
	 * @brief Converts an integer representation of a CD-ROM location to a CdlLOC structure.
	 *
	 * @param i The integer representation of the CD-ROM location.
	 * @param p Pointer to the CdlLOC structure to populate.
	 * @return A pointer to the populated CdlLOC structure.
	 */
	EXPORT CdlLOC *CdIntToPos(int i, CdlLOC *p);

	/**
	 * @brief Converts a CdlLOC structure to an integer representation.
	 *
	 * @param loc The CdlLOC structure to convert.
	 * @return The integer representation of the CD-ROM location.
	 */
	EXPORT int CdPosToInt(const CdlLOC *loc);

#ifdef __cplusplus
}
#endif
