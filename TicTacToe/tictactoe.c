#include "tictactoe.h"
#include "ai.h"
#include <stdio.h>
#include <stdlib.h>

int isTaken(int *feld, int pos)
{
	int test = 1 << pos;
	return (test & *feld) != 0;
}

static void setPosition(int *feld, int pos)
{
	pos = 1 << pos;
	*feld = *feld | pos;
}

int doMove(int *fplay, int *fcpu, int pos)
{
	if (pos < 0 || pos > 8)
		return 0;

	if (!isTaken(fcpu, pos) && !isTaken(fplay, pos))
	{
		setPosition(fplay, pos);
		return 1;
	}
	return 0;
}

void doCpuMove(int *fplay, int *fcpu)
{
	//Win with 3rd next to 2
	int doubcp = findDouble(fcpu, fplay);

	if (doubcp != NOTFOUND)
	{
		setPosition(fcpu, doubcp);
		return;
	}

	//Stop player from winning if he has 2
	int doubpl = findDouble(fplay, fcpu);

	if (doubpl != NOTFOUND)
	{
		setPosition(fcpu, doubpl);
		return;
	}

	//Play center if Possible
	if (canCenter(fplay, fcpu)) {
		setPosition(fcpu, 4);
		return;
	}

	//Play opposite corner
	int cornerOp = otherCorner(fplay, fcpu);

	if (cornerOp != NOTFOUND) {
		setPosition(fcpu, cornerOp);
		return;
	}


	//Lets play Lotto
	if (tie(fplay, fcpu))
		return;

	int r;

	do {
		r = rand() % 9;
	} while (isTaken(fplay, r) || isTaken(fcpu, r));
	
	setPosition(fcpu, r);
}

int hasWon(int *feld)
{
	return	(*feld & 7) == 7
			|| (*feld & 0x38) == 0x38
			|| (*feld & 0x1C0) == 0x1C0
			|| (*feld & 0x49) == 0x49
			|| (*feld & 0x124) == 0x124
			|| (*feld & 0x111) == 0x111
			|| (*feld & 0x54) == 0x54
			|| (*feld & 0x92) == 0x92;
}


int tie(int *fplay, int *fcpu) {
	return (*fplay | *fcpu) == 0x1FF;
}

static char getChar(int *fplay, int *fcpu, int pos)
{
	char chr = 0x20;

	if (isTaken(fplay, pos))
	{
		chr = 0x58;
	}
	else if (isTaken(fcpu, pos))
	{
		chr = 0x4F;
	}

	return chr;
}

void printField(int *fplay, int *fcpu)
{
	printf(" %c %c %c %c %c\n", getChar(fplay, fcpu, 0), 0xB3, getChar(fplay, fcpu, 1), 0xB3, getChar(fplay, fcpu, 2));
	printf("%c%c%c%c%c%c%c%c%c%c%c\n", 0xC4, 0xC4, 0xC4, 0xC5, 0xC4, 0xC4, 0xC4, 0xC5, 0xC4, 0xC4, 0xC4);
	printf(" %c %c %c %c %c\n", getChar(fplay, fcpu, 3), 0xB3, getChar(fplay, fcpu, 4), 0xB3, getChar(fplay, fcpu, 5));
	printf("%c%c%c%c%c%c%c%c%c%c%c\n", 0xC4, 0xC4, 0xC4, 0xC5, 0xC4, 0xC4, 0xC4, 0xC5, 0xC4, 0xC4, 0xC4);
	printf(" %c %c %c %c %c\n", getChar(fplay, fcpu, 6), 0xB3, getChar(fplay, fcpu, 7), 0xB3, getChar(fplay, fcpu, 8));
}