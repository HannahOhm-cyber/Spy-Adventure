/****************************************************************************
* File:   .stages.c
* Author:   Hannah Ohm
* Purpose: This fuction contains all stages for the game
*******************************************************************************/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include ".maps.h"/*Displays a map when needed*/
#include ".messenger.h"/*Allows the messenger activity to run*/
int answerCheck (int numOptions){
  int ans, loop=1, error=0;
  while (loop==1){
    scanf(" %d", &ans);
    if (numOptions==2){
      if (ans==1|ans==0){
        loop=2;
      }
      else {
      printf("\nInvaild Input. Please try again:"); 
      error+=1;
      }
    }
    if (numOptions==4){
      if (ans==1|ans==2|ans==3|ans==4){
        loop=2;
      }  
      else{
      printf("\nInvaild Input. Please try again:"); 
      error+=1;
      }
    }
    if (error>=10){
    printf("\nError. Too many wrong or unrecognized answers. Please come back when you're ready to answer seriously. (You can restart the program where you left off) :)\n\n"); 
    exit(0);
    }
     
  }
return ans;
}

int stage1(){
  int ans;
  printf ("*CODENAME CONFIRMED* \"We've recieved intel that enemy operatives intend on infiltrating the HQ Annual Conference tomorrow. We need to know how they plan on doing this.\nThe enemy operatives communicate by delivering secret messages on a directory we found hidden in a popular game. Our team couldn't find this message so far, so we've copied the directory in your folder.\"\n\n\"Will you be able to find the file?\"(1=yes,0=no)\n");
  ans=answerCheck(2);
  if (ans==1){
  printf("\n\"Great! We've hidden the directory under enemyFiles on your device. Come back when you've found the secret file.\"\n");
  return 1;
  }
  else if (ans==0){
  return 2;
  }
}


int stage2 (int side){/*fuction will return which side the user is on in case it changes during stage*/
char message [256];
int ans;
if (side ==1){/*Checks which side the user is on to allow for the correct path*/
  printf("\n\"You found the file? What was the code inside?\" (Copy and paste) \n");
  scanf("%[^\n]s", &message);
  if (strcmp(message, "wverxv gl yv kozmgvw zg xlmuvivmxv") == 0){
    printf("\n\"Great agent, Now we need to find out what this means. Why don't you have a try at decoding it?\" (Enter the decoded phrase) \n");
    scanf(" %[^\n]s", &message);
    while (strcmp(message, "device to be planted at conference") != 0){/*scans the answer and doesn't allow for illegal inputs*/
      printf("\n\"Hmm, that doesnt look right, try again.\" (Hint: We know their agents sometimes use a code called Atbash)\n");
      scanf(" %[^\n]s", &message);
    }
  }
  else{/*if player gets the answer wrong, they can choose to continue looking or go a different path*/
    printf("\n\"This doesn't seem like the secret code. Why don't you go do some more digging?\" \n *Would you like to continue searching for the file?*(yes=1,no=0)\n");
    ans=answerCheck(2); 
    if (ans==0){
      printf("\nThen you will need to find another operative.\n");
    return 2;
    }
    else{
      exit(0);/*boots the user from the game before checkpoint so they have a chance to replay the level*/
    }
  }
    printf("\n\"Oh no! It looks like they're going to plant some device at the conference! This looks serious agent. You're going to need to deliever this message to another operative.\"\n");
    return 0;
  }
else if (side==2){/*Checks which side the user is on to allow for the correct path*/
  printf("\n\n\n\"Alright, you need to find another operative who goes by the name [REDACTED]. He should be at the coffee shop recieving the code now. See if you can find him.\"\n");
  printf("\n*You walk to the coffee shop where you see two men sitting on opposite sides of the room. The one on the right side seems to be watching the one on the left.*\nWhich do you choose? (1=right,0=left)\n");
  ans=answerCheck(2);
  if (ans==1){
    return 0;
  }
  else if (ans==0){
    return 1;
  }
}

}

void stage3(int side){
int ans;
  if (side == 1){/*Checks which side the user is on to allow for the correct path*/
    printf("\n\"You'll need to pass through enemy territory to deliver the message to Agent R. He's our double agent on the inside. He doesn't know about the device, but he may be able to do some digging as to where they may be planting it.\" \n*Once you finally arrive to the spot, you see a man approaching you. At first you think this is the agent you're meant to meet, but then he begins sprinting towards you. You need to think fast. (0=dodge right, 1=dodge left)\n");
    ans=answerCheck(2); 
    if (ans==1){
      printf("\n*You lunge out of the way and knocked the man out* \"Great work dodging that them Agent. Head to the meet point to deliver the message.\"\n");
    }
    else {
      printf("\n*You lunge into a wall and black out. The man grabs you and starts dragging you away. *\"Agent I think I'm losing you... Dangit, I knew i shouldn't have let a rookie handle this.\" *You were captured. Restart to return to the checkpoint.*");
      exit(0);/*boots the user from the game before checkpoint so they have a chance to replay the level*/
  }
  }
  else if (side == 2){/*Checks which side the user is on to allow for the correct path*/
    printf("\nMan: \"So you're an HQ agent, huh? Well kid, you should run along before you get hurt.\" \n*What do you respond?* (1=\"No\" 0=\"Tell me what I need to know\") \n");
    ans=answerCheck(2); 
    if (ans==1){
      printf("\n\"Oh really? Well then, I'll be taking you to the boss.\" *You follow him willingly to a weird odds and ends store across the street. You see a man standing behind th counter. He gives you a quick look.*\"You looking for a job kid?\"");
    }
    else {
      printf("\n\"Like I said son, you should've run.\" *You died. Restart to return to the checkpoint.*");
      exit(0);/*boots the user from the game before checkpoint so they have a chance to replay the level*/
    }
  }
}


int stage4(int side){/*fuction will return which side the user is on in case it changes during stage*/
  int ans;
  if (side == 1){/*Checks which side the user is on to allow for the correct path*/
    printf("\n*You find the meet point and realize no one is there. You report this to HQ* \n\"Sorry agent, looks like you'll need to deliver the message to a drop point instead. I recieved a map from Agent R. You'll need to choose the correct store on the intersection map. \"");
    mapsFunction ();
    printf("\n\"So Agent. what'll it be?\" \n");
    ans=answerCheck(4); 
    if (ans==2){
      printf("\n\"Alright, now that you've successfully delivered the message to the drop point, you'll need to wait until Agent R has done some digging.\"");
      printf("\nTHE NEXT DAY\n \"Agent, I've recieved word that Agent R has important information about the device that's going to be planted at the conference today. He's dropped it into a file on your messages directory. Find the file and report the details.\"");
      return 2;
    }
    else {
      printf("\n\"Agent the message was intercepted by a pack of wild kids. Our intel has been lost and you have no time to re deliver the message. I'm afraid you failed the mission.\"\n*You failed. Restart to return to the checkpoint.*");
      exit(0);/*boots the user from the game before checkpoint so they have a chance to replay the level*/
    }
  }
  else if (side == 2){/*Checks which side the user is on to allow for the correct path*/
    printf("\"You are, huh? Well if you want to prove yourself you'll need to intercept a messsage from HQ. We're sending you since they don't know you've been compromised yet and you still have access to sensitive information. The only issue is: We don't know where the drop will happen. All we have is this map.\"");
    mapsFunction ();
    printf("\n\"Maybe try to pick one of the stores and search it?\"\n"); 
    ans=answerCheck(4);
    if (ans==2){
      printf("\n\"Great work! It seems that the boss wants you to help us with the rest of this mission.\"");
      return 0;
    }
    else {
      printf("\n*You didn't find the message* \"Shame, I really saw potential in you kid. Go back to where you came from.\"");
    return 1;
  }
}
}


int stage5(int side){/*fuction will return which side the user is on in case it changes during stage*/
  int success, ans;
  int i=0, a,b[8]={3,6,5,5,2,1,2,1};
  if (side==1){/*Checks which side the user is on to allow for the correct path*/
    success=messageInterface();
    if (success==0){
    printf("\"It looks like the device could be dangerous. There's not enough time to cancel the conference today, so you'll need to find the device yourself.\"");
      return 0;
    }
    else if (success==1){
    printf("\"Too bad you didn't find that file. I guess we'll just need to send you in to assess the situation. Go meet the intelligence team to figure out where to start.\"");
      return 1;
    }
  }
  else{
    printf("\nTHE NEXT DAY\n*You've been sent to a hotel with a strangely heavy breifcase.* \"Alright, I need you to look at the device you've been given. You're going to need to input a code to start the device. *All you were given was a breifcase and a slip of paper. The paper reads: *Days* *weeks* *months* in a *year*. The breifcase has an option for 8 digits*\"\n");
    printf("Will you start the device (1=no, 0=yes)\n");
    ans=answerCheck(2);
    if (ans==1) return 2;/*checks user input and compares it with the code in array*/
    for(i = 0; i <= 7; i++) {
      printf ("Enter digit %d: ", (i+1));
      scanf(" %d,",&a);
      if (a!=b[i]){
        printf("Incorrect");
        i-=1;
        }
      }
    printf("*You start the device and escape.* \n\n*You helped the bad guys win.*");
    return 4;
  } 
}


void stage6 (int side){
  int ans;
  if (side==0){/*Checks which side the user is on to allow for the correct path*/
    printf("\n\"Alright, we've found a suitable location to stakeout. Remember, we need to find that device or everyone could die.\"\n *You wait for several hours until you see two men approach the center of the parking garage. One of them has a breifcase with them.*\n*You wait for the right time to approach them, but as you get closer you see one reach for his belt.* He has a weapon, you need to act fast agent. (1=pull your own weapon, 0=take cover)\n ");
    ans=answerCheck(2);
    if (ans==0){
      printf("*You take cover and wait until the man is close enough. You take him down just as the other runs at you. You manage to take the breifcase and knock him out with it.\n\"You managed to get the device before it was activated. Excellent work Agent! I'll see you back at HQ for a debreifing tomorrow. For now, enjoy the rest of the conference.\" \n*You successfully beat the bad guys and saved everyone!*");
    }
    else{
      printf("\n*You didn't manage to beat the bad guys and everyone died. Restart to return to the checkpoint.*");
      exit(0);/*boots the user from the game before checkpoint so they have a chance to replay the level*/
    }
  }
  else if (side==1){/*Checks which side the user is on to allow for the correct path*/
    printf("\n\"Welcome back agent. One of our specialists has some promising intel.The only issue is, he couldn't tell if the device was going to be planted in the janitors closet or in the parking garage. It's up to you to decide.\" (0=janitor closet, 1=parking garage)\n");
    ans=answerCheck(2);
    if (ans==0){
      printf("\n*You find the janitor closet and search around. There's nothing there. You decide to try the parking garage. As you walk down the stairs, you hear a blast and then everything goes silent.*\n*You couldn't find the device and everyone was killed. Restart to return to the checkpoint.*");
      exit(0);/*boots the user from the game before checkpoint so they have a chance to replay the level*/
    }
    else if (ans==1){
      printf("\n*You make your way to the parking garage. As you reach the first floor you see several men running to the stairs. You go towards the way they came and see a breifcase sitting open with a time counting down. You report the amount of time left to HQ. They are able to safely evacuate the building before time runs out.*\n\"You managed to get to the device in time. Excellent work Agent! I'll see you back at HQ for a debreifing.\" \n*You couldn't catch the bad guys, but you saved everyone.*");
    }
  }
  else if (side==2){/*Checks which side the user is on to allow for the correct path*/
    printf("*You secretly phone HQ and tell them you've intercepted the device. You need to ge out of there. You can either take the north or south exit. (1=north,0=south)\n");
    ans=answerCheck(2);
    if (ans==1) printf("*You run out the north exit and you reach another agent you know. He gives you a ride to HQ where you turn in the device to the higher level operatives*\n\n*You saved the day! Congratulations!*");
    else {
    printf ("*You take the South exit where you run into some goons. They apprehend you and turn on the device.* \n\n *You lost*");
    exit(0);/*boots the user from the game before checkpoint so they have a chance to replay the level*/
    }
  }
}