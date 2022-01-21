/****************************************************************************
* File:   .messenger.c
* Author:   Hannah Ohm
* Purpose:  This file contains the function for the stage that requires a message
*******************************************************************************/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int messageInterface(){
  char ans[256];
  int next=0;
  printf("\n\n\n ____________________________________________\n│                    Boss                    │\n----------------------------------------------\n");
  printf("  What was the name of the file you found?\n\n");
  scanf(" %[^\n]s", &ans);
  while (next==0){
    if (strcmp(ans, "plans.txt") == 0){
      printf("  Great that checks out. \n  Next Question:");
      next=1;
    }
    else{
      printf("Sorry, that wasn't the name of the file. ");
      return 1;
    }
  }
  next=0;
  printf(" What was the encrypted message hidden in the file?\n\n");
  scanf("  %[^\n]s", &ans);
  while (next==0){
    if (strcmp(ans, "kziprmt tziztv wverxv prooh") == 0){
      printf("That looks like it could be the code. ");
      next=1;
    }
    else{/*scans the answer and doesn't allow for illegal inputs*/
      printf("That doesn't look right. Try again.");
      scanf("  %[^\n]s", &ans);
    }
  }
  next=0;
  printf("Try decoding it now.\n\n");
  scanf(" %[^\n]s", &ans);
  while (next==0){
    if (strcmp(ans, "parking garage device kills") == 0){
      printf("Great work, Agent!");
      next=1;
    }
    else{/*scans the answer and doesn't allow for illegal inputs*/
      printf("Try again.");
      scanf("  %[^\n]s", &ans);
    }
  }
  printf("\n_____________________________________________\n\n");
  return 0;
}