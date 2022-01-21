/****************************************************************************
* File:   .maps.c
* Author:   Hannah Ohm
* Purpose:  Concatenates a map to the screen. 
*******************************************************************************/

#include <stdio.h>

void mapsFunction (){
printf("\n\nDROP POINT MAP\n\n");
system("cat map.txt");
printf("\n\n1=Cafe\n2=Grocery Store\n3=Bakery\n4=Restaraunt\n\n");
}
