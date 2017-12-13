#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ai.h"


using namespace std;
//======================================
//shuffle function put into its own .cpp and .h file
void shuffle(int* shoe){
   srand(time(NULL));
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
void set_ai_bets(ai** list_of_ai, int* shoe_card, int idx){
	for(int i = 0; i < 4; i++){
		list_of_ai[i]->set_bet_type(shoe_card, idx);
	}

}
//==================================

//=================================
//Paying out ai bets
void pay_ai_bets(ai** list_of_ai, int hand_result){
	for(int i = 0; i < 4; i++){
		if(list_of_ai[i]->get_bet_type() == hand_result){
			//ai wins -> add bet to capital
			list_of_ai[i]->add_to_capital(list_of_ai[i]->get_bet());
		}
		else if(hand_result == 2){
			//tie add 0 to capital
			list_of_ai[i]->add_to_capital(0);
		}
		else{
			//ai loses -> sub bet from capital
			list_of_ai[i]->sub_from_capital(list_of_ai[i]->get_bet());
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

//=================================
//determining who won the hands
int winner_of_hand(int* shoe, int& top_of_deck){
	int player = 0;
	int banker = 0;
	player = (player + shoe[top_of_deck])%10;
	top_of_deck += 1;
	banker = (banker + shoe[top_of_deck])%10;
	top_of_deck += 1;
	player = (player + shoe[top_of_deck])%10;
	top_of_deck += 1;
	banker = (banker + shoe[top_of_deck])%10;
	top_of_deck += 1;
	
	if((player == 8) || (player == 9) || (banker == 8) || (banker == 9)){
		//compare the hands and return the result
		return compare_the_hands(player, banker);
	}
	else if(((player == 6) || (player == 7)) && (banker <= 5)){
		//banker draws a card
		banker = (banker + shoe[top_of_deck])%10;
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
		top_of_deck += 1;

		if(banker <= 2){
			//banker draws a card
			banker = (banker + shoe[top_of_deck])%10;
			top_of_deck += 1;
			//compare the hands and return the result
			return compare_the_hands(player, banker);
		}
		else if((banker == 3) && (p3 != 8)){
			//banker draws a card
			banker = (banker + shoe[top_of_deck])%10;
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
void print_winner(int result){
	if(result == 0){
	   cout << "PLAYER WINS" << endl;
	}
	if(result == 1){
	   cout << "BANKER WINS" << endl;
	}
	if(result == 2){
	   cout << " TIE " << endl;
	}
}
//==============================
int main(){

   int* shoe = new int[416];
   int top_of_deck = 0;
   int* shoe_card = new int[100];
   int idx = -1;
   int hand_result;
   int red_card = 416 - (rand()%52 + 35);
   shuffle(shoe);
   burn_top_cards(shoe, top_of_deck);
   ai** list_of_ai = new ai*[4];
   list_of_ai[0] = new ai("always banker");
   list_of_ai[1] = new ai("always player");
   list_of_ai[2] = new ai("alternate banker and player");
   list_of_ai[3] = new ai("copy last win");

   //this is how you access the data
   //cout << list_of_ai[0]->get_ai_name() << endl;

   while(top_of_deck <= red_card){
   set_ai_bets(list_of_ai, shoe_card, idx);
   /* these lines of code shows the ai name and the bet they are betting on
   for(int i = 0; i < 4; i++){
	cout << list_of_ai[i]->get_ai_name() << " BETS ON " << list_of_ai[i]->get_bet_type() << endl;
   }*/

   hand_result = winner_of_hand(shoe, top_of_deck);
   update_shoe_card(shoe_card, idx, hand_result);
   print_winner(hand_result);
   pay_ai_bets(list_of_ai, hand_result);
   /* these lines of code shows the ai name and the amount of money they have
   for(int i = 0; i < 4; i++){
	cout << list_of_ai[i]->get_ai_name() << " HAS " << list_of_ai[i]->get_capital() << endl;
   }*/
   }
   /* these lines of code shows the ai name and the amount of money they have*/
   for(int i = 0; i < 4; i++){
	cout << list_of_ai[i]->get_ai_name() << " HAS " << list_of_ai[i]->get_capital() << endl;
   }

   return 0;
}
