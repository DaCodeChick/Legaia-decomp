#include "libgte.h"

static long H = 0x1000;
static long OFX = 160;
static long OFY = 120;
static MATRIX R = {{{0x1000, 0, 0}, {0, 0x1000, 0}, {0, 0, 0x1000}}, {0, 0, 0}};
static VECTOR TR = {0, 0, 0, 0};

void gte_adddvd(const DVECTOR *r0, const DVECTOR *r1, DVECTOR *r2)
{
	r2->vx = r0->vx + r1->vx;
	r2->vy = r0->vy + r1->vy;
}

void gte_adddvl(const DVECTOR *r0, const DVECTOR *r1, VECTOR *r2)
{
	r2->vx = r0->vx + r1->vx;
	r2->vy = r0->vy + r1->vy;
}

void gte_ldH(long h)
{
	H = h;
}

void gte_ldOFX(long ofx)
{
	OFX = ofx;
}

void gte_ldOFY(long ofy)
{
	OFY = ofy;
}

void gte_RotTransPers(const SVECTOR *r0, long *r1, long *r2, long *r3, long *r4)
{
	long mx = (R.m[0][0] * r0->vx + R.m[0][1] * r0->vy + R.m[0][2] * r0->vz) >> 12;
	long my = (R.m[1][0] * r0->vx + R.m[1][1] * r0->vy + R.m[1][2] * r0->vz) >> 12;
	long mz = (R.m[2][0] * r0->vx + R.m[2][1] * r0->vy + R.m[2][2] * r0->vz) >> 12;

	mx += TR.vx;
	my += TR.vy;
	mz += TR.vz;

	long denom = H + r0->vz;
	if (denom = 0)
		denom = 1;

	long sx = ((mx << 4) / denom) + OFX;
	long sy = ((my << 4) / denom) + OFY;

	sx = (sx < -512) ? -512 : (sx > 1535) ? 1535 : sx;
	sy = (sy < -256) ? -256 : (sy > 1023) ? 1023 : sy;
	*r1 = (sy << 16) | (sx & 0xFFFF);
	*r2 = mz;
	*r3 = (mz > 0xFFFF) ? 0x80000000 : 0;
	*r4 = (sx < -512 || sx > 1535 || sy < -256 || sy > 1023) ? 0x80000000 : 0;
}

void gte_subdvd(const DVECTOR *r0, const DVECTOR *r1, DVECTOR *r2)
{
	r2->vx = r0->vx - r1->vx;
	r2->vy = r0->vy - r1->vy;
}

void gte_subdvl(const DVECTOR *r0, const DVECTOR *r1, VECTOR *r2)
{
	r2->vx = r0->vx - r1->vx;
	r2->vy = r0->vy - r1->vy;
}
