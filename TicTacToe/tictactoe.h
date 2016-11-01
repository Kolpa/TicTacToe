#pragma once
int isTaken(int *feld, int pos);

int doMove(int *fplay, int *fcpu, int pos);

void doCpuMove(int *fplay, int *fcpu);

int hasWon(int *feld);

int tie(int *fplay, int *fcpu);

void printField(int *fplay, int *fcpu);