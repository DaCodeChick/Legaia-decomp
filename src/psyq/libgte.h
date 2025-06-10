#pragma once

#include "../typedefs.h"
#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief Color vector structure for graphics operations.
	typedef struct
	{
		u_char r;  ///< Red component (0-255)
		u_char g;  ///< Green component (0-255)
		u_char b;  ///< Blue component (0-255)
		u_char cd; ///< Color depth (0-255)
	} CVECTOR;

	/// @brief Vector structure for 2D graphics operations.
	typedef struct
	{
		short vx; ///< X coordinate
		short vy; ///< Y coordinate
	} DVECTOR;

	/// @brief Matrix structure for 3D graphics operations.
	typedef struct
	{
		short m[3][3]; ///< 3x3 matrix elements
		long t[3];     ///< 3D translation components
	} MATRIX;

	/// @brief Vector structure for 2D graphics operations with padding.
	typedef struct
	{
		short vx;  ///< X coordinate
		short vy;  ///< Y coordinate
		short vz;  ///< Z coordinate
		short pad; ///< Padding
	} SVECTOR;

	/// @brief Vector structure for 3D graphics operations.
	typedef struct
	{
		long vx;  ///< X coordinate
		long vy;  ///< Y coordinate
		long vz;  ///< Z coordinate
		long pad; ///< Padding
	} VECTOR;

	/**
	 * @brief Add two 2D vectors and store the result in a third vector.
	 *
	 * @param r0 The first vector to add.
	 * @param r1 The second vector to add.
	 * @param r2 The vector to store the result.
	 */
	EXPORT void gte_adddvd(const DVECTOR *r0, const DVECTOR *r1, DVECTOR *r2);

	/**
	 * @brief Add two 2D vectors and store the result in a 3D vector.
	 *
	 * @param r0 The first vector to add.
	 * @param r1 The second vector to add.
	 * @param r2 The vector to store the result.
	 */
	EXPORT void gte_adddvl(const DVECTOR *r0, const DVECTOR *r1, VECTOR *r2);

	/**
	 * @brief Load the H register with a 32-bit value.
	 *
	 * @param h The 32-bit value to load into the H register.
	 */
	EXPORT void gte_ldH(long h);

	/**
	 * @brief Load the OFX register with a 32-bit value.
	 *
	 * @param ofx The 32-bit value to load into the OFX register.
	 */
	EXPORT void gte_ldOFX(long ofx);

	/**
	 * @brief Load the OFY register with a 32-bit value.
	 *
	 * @param ofy The 32-bit value to load into the OFY register.
	 */
	EXPORT void gte_ldOFY(long ofy);

	/**
	 * @brief Rotate and translate a 3D vector using perspective projection.
	 *
	 * @param r0 The input vector to transform.
	 * @param r1 The output X coordinate.
	 * @param r2 The output Y coordinate.
	 * @param r3 The output Z coordinate.
	 * @param r4 The output W coordinate.
	 */
	EXPORT void gte_RotTransPers(const SVECTOR *r0, long *r1, long *r2, long *r3, long *r4);

	/**
	 * @brief Subtract two 2D vectors and store the result in a third vector.
	 *
	 * @param r0 The first vector to subtract.
	 * @param r1 The second vector to subtract.
	 * @param r2 The vector to store the result.
	 */
	EXPORT void gte_subdvd(const DVECTOR *r0, const DVECTOR *r1, DVECTOR *r2);

	/**
	 * @brief Subtract two 2D vectors and store the result in a 3D vector.
	 *
	 * @param r0 The first vector to subtract.
	 * @param r1 The second vector to subtract.
	 * @param r2 The vector to store the result.
	 */
	EXPORT void gte_subdvl(const DVECTOR *r0, const DVECTOR *r1, VECTOR *r2);

#ifdef __cplusplus
}
#endif
