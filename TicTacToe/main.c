#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>

int feld_cpu = 0;
int feld_pl = 0;

int main(int argc, char **argv)
{
	int x;
	int y;
	int over = 0;

	while(!over)
	{
		printField(&feld_pl, &feld_cpu);
		
		do 
		{
			printf("Bitte Mach deinen Zug im format y x: ");

			scanf_s("%d %d", &y, &x);

			printf("\n");

		} while (!doMove(&feld_pl, &feld_cpu, (y - 1) * 3 + x - 1));

		if (hasWon(&feld_pl))
		{
			printField(&feld_pl, &feld_cpu);

			printf("Du hast Gewonnen!!\n");

			over = 1;
		}

		doCpuMove(&feld_pl, &feld_cpu);

		if (hasWon(&feld_cpu) && !over)
		{
			printField(&feld_pl, &feld_cpu);

			printf("Der Computer hat Gewonnen!!\n");
			
			over = 1;
		}

		if (tie(&feld_pl, &feld_cpu) && !over)
		{
			printField(&feld_pl, &feld_cpu);

			printf("Unentschieden!!\n");

			over = 1;
		}
	}

	system("pause");
}