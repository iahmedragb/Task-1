#ifndef TICTAC_H_INCLUDED
#define TICTAC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int i;
int gamescore;
int turn,t;
char p1[20],p2[20],gamemode,pch1;

//Board slots
char bslot[10];

int startgame();
void menu();
void board();
void mode1();
void turnMode1();
void game1();
void newgame();
void layout1();
void playerMarkMode1();
void slot();
void markpcsv();
void markwin();
void markComputerCheck();
void mark();
void gamecheck();
void endgame();
void screen1();
void screen2();
void game3();
void draw();
void screen3();
void mode2();
void game2();
void layout2();
void playerMarkMode2();

#endif // TICTAC_H_INCLUDED
