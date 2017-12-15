#include <iomanip>
#include "functions.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ai.h"
#include "alternate.h"
#include "alwaysbanker.h"
#include "alwaysplayer.h"
#include "copylastwin.h"
#include "countbanker.h"
#include "countplayer.h"
#include "countbankerhigh.h"
#include "countplayerhigh.h"
#include "goagainstlast.h"

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
   int c = 100;
   shuffle(shoe);
   burn_top_cards(shoe, top_of_deck);

   for(int x = 0; x < 50; x++){
      for(int y = 0; y < 20; y++){
	 shoe_card2[y][x] = 8;
      }
   }
/*
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
  */ 
   ai*** matrix = new ai**[9];
   /*
   matrix[0] = new alwaysBanker*[8];
   matrix[1] = new alwaysPlayer*[8];
   matrix[2] = new copyLastWin*[8];
   matrix[3] = new alternate*[8];
   matrix[4] = new goAgainstLast*[8];
   matrix[5] = new countBanker*[8];
   matrix[6] = new countPlayer*[8];
   matrix[7] = new countBankerHigh*[8];
   matrix[8] = new countPlayerHigh*[8];
  */


   for(int i = 0; i < 9; i++){
	matrix[i] = new ai*[8];
   }
   for(int i = 0; i < 8; i++){
	matrix[0][i] = new alwaysBanker(c);
	matrix[1][i] = new alwaysPlayer(c);
	matrix[2][i] = new copyLastWin(c);
	matrix[3][i] = new alternate(c);
	matrix[4][i] = new goAgainstLast(c);
	matrix[5][i] = new countBanker(c);
	matrix[6][i] = new countPlayer(c);
	matrix[7][i] = new countBankerHigh(c);
	matrix[8][i] = new countPlayerHigh(c);
   }

   while(top_of_deck <= red_card){
      set_ai_bets(matrix, shoe_card, idx, count);

      hand_result = winner_of_hand(shoe, top_of_deck, count);

      update_shoe_card(shoe_card, idx, hand_result);

      print_winner(hand_result, player_wins, banker_wins, ties);

      pay_ai_bets(matrix, hand_result);
   }
   
   /* these lines of code shows the ai name and the amount of money they have*/
   cout << "                      bet10      bet25     doubleup    1324    fib      d'alem    paroli   count bet" << endl;
   for(int i = 0; i < 9; i++){
	cout << setw(20) << matrix[i][0]->get_ai_name() << " : ";
	for(int j = 0; j < 8; j++){
		cout << setw(8) << matrix[i][j]->get_capital() << " ";
	}
	cout << endl;

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
