#include <iomanip>
#include "functions.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){

   int* shoe = new int[416];
   int top_of_deck = 0;
   int* shoe_card = new int[100];
   int shoe_card2[30][50] = {0};
   int idx = -1;
   int hand_result;
   int red_card = 416 - (rand()%52 + 35);
   int banker_wins = 0;
   int player_wins = 0;
   int ties = 0;
   int count = 0;
   int prevcount = 0;
   int c = 100;
   int handnumber = 0;
   
   int prevplayercount = 0;
   int prevbankcount = 0;
   int prevtiecount = 0;

   int playercount = 0;
   int bankcount = 0;
   int tiecount = 0;
   
   shuffle(shoe);
   burn_top_cards(shoe, top_of_deck);

   for(int x = 0; x < 50; x++){
      for(int y = 0; y < 20; y++){
	 shoe_card2[y][x] = 8;
      }
   }

   while(top_of_deck <= red_card){

      hand_result = winner_of_hand(shoe, top_of_deck, count, playercount, bankcount, tiecount);

      update_shoe_card(shoe_card, idx, hand_result);

      print_winner(hand_result, player_wins, banker_wins, ties, prevcount, prevplayercount, prevbankcount, prevtiecount);

      prevcount = count;
      prevplayercount = playercount;
      prevbankcount = bankcount;
      prevtiecount = tiecount;
      handnumber++;
   }

   cout << "TOTAL PLAYER WINS: " << player_wins << endl;
   cout << "TOTAL BANKER WINS: " << banker_wins << endl;
   cout << "TOTAL TIES: " << ties << endl;
   cout << "TOTAL HANDS: " << player_wins + banker_wins + ties << endl;

   return 0;
}
