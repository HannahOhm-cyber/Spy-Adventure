/****************************************************************************
* File:   .save.c
* Author:   Hannah Ohm
* Purpose:  This file contains a program meant to save the players progress
*******************************************************************************/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

void saveProgress(char name[256], int stage,int side){
  FILE *savefile = fopen("savefile.txt","w" );
  fprintf(savefile, "%s %d %d", name, stage, side );
  fclose(savefile);
  printf("\n\n*****GAME SAVED*****\n");
  printf("%s |Stage %d\n", name, stage );
}