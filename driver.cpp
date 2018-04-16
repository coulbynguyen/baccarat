#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "driverfunctions.h"
#include <fstream>

using namespace std;

int main(){
   srand(time(NULL));

   int shoe[416] = {};
   int top_of_shoe = 0; //this number needs to change based on the first card
   int red_card = 416 - (rand()%52+52);
   int count = 0;
   int hand_number = 0;
   int streak_count = 0;

   float sum10 = 0;
   float sum20 = 0;
   float sum30 = 0;
   float playersum10 = 0;
   float playersum20 = 0;
   float playersum30 = 0;

   int last_hand = -1;
   int hand_result = -1; // -1 no hand has played yet // 0 = bank win // 1 = player win // 2 = tie
   int* cards_played; // first 3 corespond to player last 3 corespond to banker

   int bank_last10[10] = {0};
   int bank_last20[20] = {0};
   int bank_last30[30] = {0};
   int player_last10[10] = {0};
   int player_last20[10] = {0};
   int player_last30[10] = {0};



   fill_shoe(shoe);

   top_of_shoe = shoe[top_of_shoe+1];

   ofstream labels;
   labels.open("labels.txt", ios::app);

   ofstream newcount;
   newcount.open("newcount.txt", ios::app);

   ofstream handcount;
   handcount.open("handnumber.txt", ios::app);

   ofstream lasthand;
   lasthand.open("lasthandwin.txt", ios::app);

   ofstream streakcount;
   streakcount.open("streakcount.txt", ios::app);

   ofstream featuretable;
   featuretable.open("featuretable.txt", ios::app);

   ofstream sum10file;
   sum10file.open("sum10.txt", ios::app);

   ofstream sum20file;
   sum20file.open("sum20.txt", ios::app);

   ofstream sum30file;
   sum30file.open("sum30.txt", ios::app);

   ofstream player10file;
   player10file.open("player10file.txt", ios::app);

   ofstream player20file;
   player20file.open("player20file.txt", ios::app);

   ofstream player30file;
   player30file.open("player30file.txt", ios::app);

   featuretable << "The Way To Read This is A      A      A      A    -> B" << endl;
   featuretable << "                        B      B      B      B    -> C" << endl;
   featuretable << "this means that the 4 data descriptors are from the previous hands and are used to imply the C and does not include the C in their tallies" << endl;
   featuretable << endl;
   featuretable << setw(12) << "STREAK COUNT" << setw(12) << "BANK LAST10" << setw(12) << "PLAYERLAST10" << setw(12) << "BANK LAST20" << setw(12) << "PLAYERLAST20" << setw(12) << "BANK LAST30" << setw(12) << "PLAYERLAST30" << setw(12) << "LABEL" << endl;

   while(top_of_shoe < red_card){
      hand_number++;
      sum10 = 0;
      sum20 = 0;
      sum30 = 0;
      playersum10 = 0;
      playersum20 = 0;
      playersum30 = 0;

      //print out count, winner, cards
      //if((hand_number > 20)&&(hand_number < 50)){
      if(hand_number >= 30){
	 //only want to keep track of info of hands above 30
	 lasthand << last_hand << endl;
	 newcount << count << endl;
	 handcount << hand_number << endl;
	 //streakcount << streak_count << endl;
      }


      //deal hands & determine winner & update top_of_shoe
      cards_played = play_hand(shoe, top_of_shoe, count, hand_result);

      //if((hand_number > 20)&&(hand_number < 50)){
      if(hand_number >= 30){
	 labels << hand_result << endl;
      }

      //if hand result is equal to banker == 0
      for(int idx = 0; idx < 10; idx++){
	 sum10 += bank_last10[idx];
	 playersum10 += player_last10[idx];
      }
      //gets the previous sum before adding in the results of the hand that just happened
      if(hand_number <= 10){
        if(hand_number == 1){
          sum10 = (float)sum10 / 1;
          playersum30 = (float)playersum30 / 1;
        }
        else{
	         sum10 = (float)sum10 / (float)(hand_number-1);
	         playersum30 = (float)playersum30 / (float)(hand_number-1);
        }
      }
      else{
	 sum10 = (float)sum10 / 10;
	 playersum10 = (float)playersum10 / 10;
      }

      for(int idx = 9; idx > 0; idx--){
	 bank_last10[idx] = bank_last10[idx-1];
	 player_last10[idx] = player_last10[idx-1];
      }
      if(hand_result == 0){
	 bank_last10[0] = 1;
      }
      else{
	 bank_last10[0] = 0;
      }
      if(hand_result == 1){
	 player_last10[0] = 1;
      }
      else{
	player_last10[0] = 0;
      }

      for(int idx = 0; idx < 20; idx++){
	 sum20 += bank_last20[idx];
	 playersum20 += player_last20[idx];
      }
      //gets the previous sum before adding in the results of the hand that just happened
      if((hand_number) <= 20){
        if(hand_number == 1){
          sum20 = (float)sum20 / 1;
          playersum20 = (float)playersum20 / 1;
        }
        else{
	         sum20 = (float)sum20 / (float)(hand_number-1);
	         playersum20 = (float)playersum20 / (float)(hand_number-1);
        }
      }
      else{
	 sum20 = (float)sum20 / 20;
	 playersum20 = (float)playersum20 / 20;
      }

      for(int idx = 19; idx > 0; idx--){
	 bank_last20[idx] = bank_last20[idx-1];
	 player_last20[idx] = player_last20[idx-1];
      }
      if(hand_result == 0){
	 bank_last20[0] = 1;
      }
      else{
	 bank_last20[0] = 0;
      }
      if(hand_result == 1){
	player_last20[0] = 1;
      }
      else{
	player_last20[0] = 0;
      }

      for(int idx = 0; idx < 30; idx++){
	 sum30 += bank_last30[idx];
	 playersum30 += player_last30[idx];
      }
      //gets the previous sum before adding in the results of the hand that just happened
      if((hand_number) <= 30){
        if(hand_number == 1){
          sum30 = (float)sum30 / 1;
          player10 = (float)playersum10 / 1;
        }
        else{
	         sum30 = (float)sum30 / (float)(hand_number-1);
	         playersum10 = (float)playersum10 / (float)(hand_number-1);
        }
      }
      else{
	 sum30 = (float)sum30 / 30;
	 playersum30 = (float)playersum30 / 30;
      }

      for(int idx = 29; idx > 0; idx--){
	 bank_last30[idx] = bank_last30[idx-1];
	 player_last30[idx] = player_last30[idx-1];
      }
      if(hand_result == 0){
	 bank_last30[0] = 1;
      }
      else{
	 bank_last30[0] = 0;
      }
      if(hand_result == 1){
	player_last30[0] = 1;
      }
      else{
	player_last30[0] = 0;
      }

      if(hand_number >= 1){
	 //only want to check data that is above hand number 30
	 featuretable << setw(12) << streak_count << setw(12) << sum10 << setw(12) << playersum10 << setw(12) << sum20 << setw(12) << playersum20 <<  setw(12) << sum30 << setw(12) << playersum30 << setw(12) << hand_result << endl;
	 streakcount << streak_count << endl;
	 sum10file << sum10 << endl;
	 sum20file << sum20 << endl;
	 sum30file << sum30 << endl;
	 player10file << playersum10 << endl;
	 player20file << playersum20 << endl;
	 player30file << playersum30 << endl;
      }


      if(last_hand == hand_result){
	 streak_count++;
      }
      else{
	 streak_count = 1;
      }

      last_hand = hand_result;
      //print out hand and winner of every hand
      cout << "HAND " << hand_number << endl;
      for(int i = 0; i < 6; i++){
	 if(cards_played[i] == -1){
	    cout << " ";
	 }
	 else{
	    cout << cards_played[i] << " ";
	 }

	 if(i == 2){
	    cout << "|| ";
	 }
      }
      cout << "WINNER: " << hand_result << " COUNT: " << count <<  endl;
      cout << endl;
      //update count, winner
   }
   return 0;
   }
