#include "functions.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ai.h"

using namespace std;

int main(){

   int* shoe = new int[416];
   int top_of_deck = 0;
   int* shoe_card = new int[100];
   int shoe_card2[20][50] = {0};
   int idx = -1;
   int hand_result;
   int red_card = 416 - (rand()%52 + 35);
   int banker_wins = 0;
   int player_wins = 0;
   int ties = 0;
   int count = 0;
   shuffle(shoe);
   burn_top_cards(shoe, top_of_deck);

   for(int x = 0; x < 50; x++){
      for(int y = 0; y < 20; y++){
	 shoe_card2[y][x] = 8;
      }
   }

   ai** list_of_ai = new ai*[10];
   list_of_ai[0] = new ai("always banker");
   list_of_ai[1] = new ai("always player");
   list_of_ai[2] = new ai("alternate banker and player");
   list_of_ai[3] = new ai("copy last win");
   list_of_ai[4] = new ai("double up banker");
   list_of_ai[5] = new ai("double up player");
   list_of_ai[6] = new ai("count banker");
   list_of_ai[7] = new ai("count player");
   list_of_ai[8] = new ai("count high banker");
   list_of_ai[9] = new ai("count high player");
   //this is how you access the data
   //cout << list_of_ai[0]->get_ai_name() << endl;

   while(top_of_deck <= red_card){
      set_ai_bets(list_of_ai, shoe_card, idx, count);
      hand_result = winner_of_hand(shoe, top_of_deck, count);
      update_shoe_card(shoe_card, idx, hand_result);
      print_winner(hand_result, player_wins, banker_wins, ties);
      pay_ai_bets(list_of_ai, hand_result);
   }
   
   /* these lines of code shows the ai name and the amount of money they have*/
   for(int i = 0; i < 10; i++){
      cout << list_of_ai[i]->get_ai_name() << " HAS " << list_of_ai[i]->get_capital() << endl;
   }
   improved_shoe_card(shoe_card, idx, shoe_card2);
   
   for(int x = 0; x < 20; x++){
      for(int y = 0; y < 50; y++){
	 if(shoe_card2[x][y] == 0){
	    cout << " P "; 
	 }
	 if(shoe_card2[x][y] == 1){
	    cout << " B ";
	 }
	 if(shoe_card2[x][y] == 2){
	    cout << " T ";
	 }
	 if(shoe_card2[x][y] == 8){
	    cout << " - ";
	 }
      }	
      cout << endl;
   }
   
   cout << "TOTAL PLAYER WINS: " << player_wins << endl;
   cout << "TOTAL BANKER WINS: " << banker_wins << endl;
   cout << "TOTAL TIES: " << ties << endl;
   cout << "TOTAL HANDS: " << player_wins + banker_wins + ties << endl;

   return 0;
}
