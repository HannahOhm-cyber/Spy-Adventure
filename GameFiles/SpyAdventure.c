/****************************************************************************
* File:   SpyAdventure.c
* Author:   Hannah Ohm
* Purpose:  Contains the main block of code
*******************************************************************************/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include ".save.h"
#include ".stages.h"
#include ".maps.h"

int main(){
char name[256];
int stage,side,jump;
  FILE *savefile = fopen("savefile.txt","a+" );/*Checks save file for current game progress*/
  fscanf(savefile, "%s%d%d", &name, &stage, &side);  
  printf("Read %s/%d/%d\n", name, stage, side);
  saveProgress(name,stage,side);
  fclose(savefile);
while (stage!=7){
  if (stage == 0){
    printf ("\nHello Agent. Please enter your agent codename: ");
    scanf("%s", &name );
    stage++;
  }  
  else if (stage == 1){
    side=stage1();
    stage++;
    saveProgress(name,stage,side);
    if (side==1){
      exit(0);/*boots the user from the game before checkpoint so they have a chance to replay the level*/
    }
  }  
  else if (stage == 2){
    jump=stage2(side);
    stage++;
    if (jump==1){
      stage=4;
      side=1;
    } 
    else if (jump==2){
    stage=2;
    side=2;
    }
    saveProgress(name,stage,side);
  }
  else if (stage == 3){
    stage3(side);
    stage++;
    saveProgress(name,stage,side);
  } 
  else if (stage == 4){
    jump=stage4(side);
    if (jump==1){
    stage=6;
    side=1; 
    }
    else if (jump==2){ /*jump allows the user to move to a different path*/
    stage++;
    saveProgress(name,stage,side);
    exit(0);
    }
    else stage++;
    saveProgress(name,stage,side);
  } 
  else if (stage == 5){
    side=stage5(side);
    stage++;
    saveProgress(name,stage,side);
  } 
  else if (stage == 6){
    stage6(side);
    stage++;
  }
}

saveProgress(" ",0,0);
printf("\n*******************Thanks for playing!******************\n");
return 0;}

