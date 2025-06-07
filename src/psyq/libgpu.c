#include "libgpu.h"

// SCUS_942.54: 80057428
u_short GetClut(int x, int y)
{
	return (u_short)(y << 6) | (u_short)(x >> 4) & 0x3f;
}
