#include "ai.h"

int findDouble(int *fieldx, int *fieldy)
{
	if ((*fieldx & 3) == 3)
		if ((1 << 2 & *fieldy) == 0)
			return 2;
	if ((*fieldx & 6) == 6)
		if ((1 << 0 & *fieldy) == 0)
			return 0;
	if ((*fieldx & 0x18) == 0x18)
		if ((1 << 5 & *fieldy) == 0)
			return 5;
	if ((*fieldx & 0x30) == 0x30)
		if ((1 << 3 & *fieldy) == 0)
			return 3;
	if ((*fieldx & 0xC0) == 0xC0)
		if ((1 << 8 & *fieldy) == 0)
			return 8;
	if ((*fieldx & 0x180) == 0x180)
		if ((1 << 6 & *fieldy) == 0)
			return 6;

	if ((*fieldx & 9) == 9)
		if ((1 << 6 & *fieldy) == 0)
			return 6;
	if ((*fieldx & 0x48) == 0x48)
		if ((1 << 0 & *fieldy) == 0)
			return 0;
	if ((*fieldx & 0x12) == 0x12)
		if ((1 << 7 & *fieldy) == 0)
			return 7;
	if ((*fieldx & 0x90) == 0x90)
		if ((1 << 1 & *fieldy) == 0)
			return 1;
	if ((*fieldx & 0x24) == 0x24)
		if ((1 << 8 & *fieldy) == 0)
			return 8;
	if ((*fieldx & 0x120) == 0x120)
		if ((1 << 2 & *fieldy) == 0)
			return 2;

	if ((*fieldx & 0x11) == 0x11)
		if ((1 << 8 & *fieldy) == 0)
			return 8;
	if ((*fieldx & 0x110) == 0x110)
		if ((1 << 0 & *fieldy) == 0)
			return 0;

	if ((*fieldx & 0x14) == 0x14)
		if ((1 << 6 & *fieldy) == 0)
			return 6;
	if ((*fieldx & 0x50) == 0x50)
		if ((1 << 2 & *fieldy) == 0)
			return 2;


	if ((*fieldx & 5) == 5)
		if ((1 << 1 & *fieldy) == 0)
			return 1;
	if ((*fieldx & 0x28) == 0x28)
		if ((1 << 4 & *fieldy) == 0)
			return 4;
	if ((*fieldx & 0x149) == 0x149)
		if ((1 << 7 & *fieldy) == 0)
			return 7;

	if ((*fieldx & 0x41) == 0x41)
		if ((1 << 3 & *fieldy) == 0)
			return 3;
	if ((*fieldx & 0x82) == 0x82)
		if ((1 << 4 & *fieldy) == 0)
			return 4;
	if ((*fieldx & 0x104) == 0x104)
		if ((1 << 5 & *fieldy) == 0)
			return 5;

	return NOTFOUND;
}

int canCenter(int *fieldx, int *fieldy) {
	return ((*fieldx & 0x10) != 0x10) && ((*fieldy & 0x10) != 0x10);
}

int otherCorner(int *fieldx, int *fieldy) {
	if ((*fieldx & 1) == 1)
		if ((1 << 8 & *fieldy) == 0)
			return 8;

	if ((*fieldx & 4) == 4)
		if ((1 << 6 & *fieldy) == 0)
			return 6;

	if ((*fieldx & 0x40) == 0x40)
		if ((1 << 2 & *fieldy) == 0)
			return 2;

	if ((*fieldx & 0x100) == 0x100)
		if ((1 & *fieldy) == 0)
			return 0;

	return NOTFOUND;
}