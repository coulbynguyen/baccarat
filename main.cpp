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
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
   srand(time(NULL));

   for(int loop = 0; loop < 100; loop++){
      cout << loop << endl;
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
/*
      for(int x = 0; x < 50; x++){
	 for(int y = 0; y < 20; y++){
	    shoe_card2[y][x] = 8;
	 }
      }
*/
      ai*** matrix = new ai**[9];
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

//	 print_winner(hand_result, player_wins, banker_wins, ties);

	 pay_ai_bets(matrix, hand_result);
      }

      /* these lines of code shows the ai name and the amount of money they have*/
//      cout << "                      bet10      bet25     doubleup    1324    fib      d'alem    paroli   count bet" << endl;
      for(int i = 0; i < 9; i++){
//	 cout << setw(20) << matrix[i][0]->get_ai_name() << " : ";
	 for(int j = 0; j < 8; j++){
//	    cout << setw(8) << matrix[i][j]->get_capital() << " ";
	    matrix[i][j]->output_to_file(j);
	 }
//	 cout << endl;

      }
  //    improved_shoe_card(shoe_card, idx, shoe_card2);
/*
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
*/
    /*  for(int i = 0; i < 9; i++){
	for(int j = 0; j < 8; j++){
		delete  matrix[i][j];
	}
	delete [] matrix[i];
      }
      delete [] matrix;*/
      }

      return 0;
}
