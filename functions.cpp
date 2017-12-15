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
//======================================
//shuffle function put into its own .cpp and .h file
void shuffle(int* shoe){
//   srand(time(NULL));
   int card_counts [13] = {};
   for(int z = 0; z < 13; z++){
	card_counts[z] = 0;
   }
   for(int i = 0; i < 416; i++){
      int card = rand() % 13 + 1;
      int a = card_counts[card];
      while(a == 32){
	 card = rand() % 13 + 1;
	 a = card_counts[card];
      }

      card_counts[card] += 1;
      
      if(card < 10){
	 shoe[i] = card;
      }
      else{
	 shoe[i] = 0;
      }

   }

}
//===================================

//===================================
//setting ai bets
void set_ai_bets(ai*** matrix, int* shoe_card, int idx, int count){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 8; j++){
			matrix[i][j]->set_bet_type(shoe_card, idx, count);
		}
	} 

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 8; j++){
			matrix[i][j]->set_bet(count, shoe_card, idx, j);
		}
	}

}
//==================================

//=================================
//Paying out ai bets
void pay_ai_bets(ai*** matrix, int hand_result){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 8; j++){
			if(matrix[i][j]->get_bet_type() == hand_result){
				//ai wins -> add bet to capital
				matrix[i][j]->add_to_capital(matrix[i][j]->get_bet());
			}
			else if(hand_result == 2){
			   //ai ties -> add 0 to capital 
				matrix[i][j]->add_to_capital(0);
			}
			else{
			   //ai loses -> subtract bet from capital
				matrix[i][j]->sub_from_capital(matrix[i][j]->get_bet());
			}
		}
	}
}





//================================

//================================
//Compare the hands and return the result
int compare_the_hands(int player, int banker){
	if(player > banker){
		return 0;
	}
	else if(player < banker){
		return 1;
	}
	else if(player == banker){
		return 2;
	}
}


//================================

//===============================
//count the cards
void adjust_count(int& count, int card){
   if((card >= 1)&&(card <= 6)){
      count += 1;
   }
   else if(card == 7){
      count += 0;
   }
   else{
      count -= 1;
   }

}


//================================


//=================================
//determining who won the hands
int winner_of_hand(int* shoe, int& top_of_deck, int& count){
   int player = 0;
   int banker = 0;
   player = (player + shoe[top_of_deck])%10;
   adjust_count(count, shoe[top_of_deck]);
   top_of_deck += 1;

   banker = (banker + shoe[top_of_deck])%10;
   adjust_count(count, shoe[top_of_deck]);
   top_of_deck += 1;

   player = (player + shoe[top_of_deck])%10;
   adjust_count(count, shoe[top_of_deck]);
   top_of_deck += 1;

   banker = (banker + shoe[top_of_deck])%10;
   adjust_count(count, shoe[top_of_deck]);
   top_of_deck += 1;

   if((player == 8) || (player == 9) || (banker == 8) || (banker == 9)){
      //compare the hands and return the result
      return compare_the_hands(player, banker);
   }
   else if(((player == 6) || (player == 7)) && (banker <= 5)){
      //banker draws a card
      banker = (banker + shoe[top_of_deck])%10;
      adjust_count(count, shoe[top_of_deck]);
      top_of_deck += 1;
      //compare the hands and return the result
      return compare_the_hands(player, banker);
   }
   else if(((player == 6) || (player == 7)) && (banker > 5)){
      //compare the hands and return the result
      return compare_the_hands(player, banker);
   }
   else if(player <= 5){
      //player draws a card
      int p3 = shoe[top_of_deck];
      player = (player + p3)%10;
      adjust_count(count, shoe[top_of_deck]);
      top_of_deck += 1;

      if(banker <= 2){
	 //banker draws a card
	 banker = (banker + shoe[top_of_deck])%10;
	 adjust_count(count, shoe[top_of_deck]);
	 top_of_deck += 1;
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }
      else if((banker == 3) && (p3 != 8)){
	 //banker draws a card
	 banker = (banker + shoe[top_of_deck])%10;
	 adjust_count(count, shoe[top_of_deck]);
	 top_of_deck += 1;
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }
      else if((banker == 3) && (p3 == 8)){
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }
      else if((banker == 4) && ((p3 == 2) || (p3 == 3) || (p3 == 4) || (p3 == 5) || (p3 == 6) || (p3 == 7))){
	 //banker draws a card
	 banker = (banker + shoe[top_of_deck])%10;
	 adjust_count(count, shoe[top_of_deck]);
	 top_of_deck += 1;
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }
      else if((banker == 4) && ((p3 != 2) && (p3 != 3) && (p3 != 4) && (p3 != 5) && (p3 != 6) && (p3 != 7))){
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }
      else if((banker == 5) && ((p3 == 4) || (p3 == 5) || (p3 == 6) || (p3 == 7))){
	 //banker draws a card
	 banker = (banker + shoe[top_of_deck])%10;
	 top_of_deck += 1;
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }
      else if((banker == 5) && ((p3 != 4) && (p3 != 5) && (p3 != 6) && (p3 != 7))){
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }
      else if((banker == 6) && ((p3 == 6) || (p3 == 7))){
	 //banker draws a card
	 banker = (banker + shoe[top_of_deck])%10;
	 adjust_count(count, shoe[top_of_deck]);
	 top_of_deck += 1;
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }
      else if((banker == 6) && ((p3 != 6) && (p3 != 7))){
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }
      else if(banker == 7){
	 //compare the hands and return the result
	 return compare_the_hands(player, banker);
      }

   }


}


//================================

//==============================
//improved shoe card

void improved_shoe_card(int* shoe_card, int idx, int shoe_card2[20][50]){
   //array[Y][X]
   //array[DEPTH][WIDTH]

   shoe_card2[0][0] = shoe_card[0];
   int x = 1;
   int y = 0;
   for(int i = 1; i < idx; i++){
      if((shoe_card[i] == shoe_card2[0][y])||(shoe_card[i] == 2)){
	 shoe_card2[x][y] = shoe_card[i];
	 x += 1;
      }
      else{
	 y += 1;
	 x = 0;
	 shoe_card2[x][y] = shoe_card[i];
	 x += 1;
      }
   }


   /*int x = 1;
     int y = 0;
     for(int i = 1; i <= idx; i++){
     if((shoe_card[i] == shoe_card2[x-1][y])||(shoe_card[i] == 2)){
     shoe_card2[x][y] = shoe_card[i];
     x += 1;
     }
     else{
     y += 1;
     x = 0;
     shoe_card2[x][y] = shoe_card[i];
     }
     }
     */
}

//================================


//===============================
//Updating the shoe card
void update_shoe_card(int* shoe_card, int& idx, int result){
   idx += 1;
   shoe_card[idx] = result;
}


//==============================

//============================
//burning the top x cards
void burn_top_cards(int* shoe, int& top_of_deck){
   int x = shoe[top_of_deck];
   top_of_deck = x+1;
}
//=============================
//=============================
//Print the winner of the round
void print_winner(int result, int& player_wins, int& banker_wins, int& ties){
   if(result == 0){
      cout << "PLAYER WINS" << endl;
      player_wins += 1;
   }
   if(result == 1){
      cout << "BANKER WINS" << endl;
      banker_wins += 1;
   }
   if(result == 2){
      cout << " TIE " << endl;
      ties += 1;
   }
}
