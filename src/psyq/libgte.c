#include "libgte.h"

static struct
{
	long h;
	long ofx;
	long ofy;
	MATRIX r;
	VECTOR tr;
} GTE;

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
	GTE.h = h;
}

void gte_ldOFX(long ofx)
{
	GTE.ofx = ofx;
}

void gte_ldOFY(long ofy)
{
	GTE.ofy = ofy;
}

void gte_RotTransPers(const SVECTOR *r0, long *r1, long *r2, long *r3, long *r4)
{
	long mx = (GTE.r.m[0][0] * r0->vx + GTE.r.m[0][1] * r0->vy + GTE.r.m[0][2] * r0->vz) >> 12;
	long my = (GTE.r.m[1][0] * r0->vx + GTE.r.m[1][1] * r0->vy + GTE.r.m[1][2] * r0->vz) >> 12;
	long mz = (GTE.r.m[2][0] * r0->vx + GTE.r.m[2][1] * r0->vy + GTE.r.m[2][2] * r0->vz) >> 12;

	mx += GTE.tr.vx;
	my += GTE.tr.vy;
	mz += GTE.tr.vz;

	long denom = GTE.h + r0->vz;
	if (denom = 0)
		denom = 1;
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
