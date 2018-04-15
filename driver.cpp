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
   
   int sum10 = 0;
   int sum20 = 0;
   int sum30 = 0;

   int last_hand = -1;
   int hand_result = -1; // -1 no hand has played yet // 0 = bank win // 1 = player win // 2 = tie
   int* cards_played; // first 3 corespond to player last 3 corespond to banker

   int bank_last10[10] = {0};
   int bank_last20[20] = {0};
   int bank_last30[30] = {0};



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
   
   featuretable << "The Way To Read This is A      A      A      A    -> B" << endl;
   featuretable << "                        B      B      B      B    -> C" << endl;
   featuretable << "this means that the 4 data descriptors are from the previous hands and are used to imply the C and does not include the C in their tallies" << endl;
   featuretable << endl;
   featuretable << setw(12) << "STREAK COUNT" << setw(12) << "BANK LAST10" << setw(12) << "BANK LAST20" << setw(12) << "BANK LAST30" << setw(12) << "LABEL" << endl;

   while(top_of_shoe < red_card){
      hand_number++;
      sum10 = 0;
      sum20 = 0; 
      sum30 = 0;

      //print out count, winner, cards
      //if((hand_number > 20)&&(hand_number < 50)){
      if(hand_number > 1){
	 lasthand << last_hand << endl;
	 newcount << count << endl;
	 handcount << hand_number << endl;
	 streakcount << streak_count << endl;
      }


      //deal hands & determine winner & update top_of_shoe
      cards_played = play_hand(shoe, top_of_shoe, count, hand_result);

      //if((hand_number > 20)&&(hand_number < 50)){
      if(hand_number > 1){
	 labels << hand_result << endl;
      }

      //if hand result is equal to banker == 0
      for(int idx = 0; idx < 10; idx++){
	 sum10 += bank_last10[idx];
      }
      
      for(int idx = 9; idx > 0; idx--){
	 bank_last10[idx] = bank_last10[idx-1];
      }
      if(hand_result == 0){
	 bank_last10[0] = 1;
      }
      else{
	 bank_last10[0] = 0;
      }

      for(int idx = 0; idx < 20; idx++){
	 sum20 += bank_last20[idx];
      }
      
      for(int idx = 19; idx > 0; idx--){
	 bank_last20[idx] = bank_last20[idx-1];
      }
      if(hand_result == 0){
	 bank_last20[0] = 1;
      }
      else{
	 bank_last20[0] = 0;
      }


      for(int idx = 0; idx < 30; idx++){
	 sum30 += bank_last30[idx];
      }
      
      for(int idx = 29; idx > 0; idx--){
	 bank_last30[idx] = bank_last30[idx-1];
      }
      if(hand_result == 0){
	 bank_last30[0] = 1;
      }
      else{
	 bank_last30[0] = 0;
      }


      featuretable << setw(12) << streak_count << setw(12) << sum10 << setw(12) << sum20 << setw(12) << sum30 << setw(12) << hand_result  << endl;


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
