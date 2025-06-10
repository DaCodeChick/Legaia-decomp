#include "libcd.h"

CdlLOC *CdIntToPos(int i, CdlLOC *p)
{
	int iVar1;
	int iVar2;
	int iVar3;

	iVar3 = (i + 0x96) / 0x4b;
	iVar2 = (i + 0x96) % 0x4b;
	iVar1 = iVar3 / 0x3c;
	iVar3 = iVar3 % 0x3c;
	p->sector = (char)iVar2 + (char)(iVar2 / 10) * '\x06';
	p->second = (char)iVar3 + (char)(iVar3 / 10) * '\x06';
	p->minute = (char)iVar1 + (char)(iVar1 / 10) * '\x06';
	return p;
}

int CdPosToInt(const CdlLOC *p)
{
	return (((uint)(p->minute >> 4) * 10 + (p->minute & 0xf)) * 0x3c + (uint)(p->second >> 4) * 10 +
	        (p->second & 0xf)) *
	           0x4b +
	       (uint)(p->sector >> 4) * 10 + (p->sector & 0xf) + -0x96;
}
