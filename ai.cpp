#include <iostream>
#include <string>
#include "ai.h"

using namespace std;

ai::ai(string name){
	ai_name = name;
	capital = 1000;
	bet = 10;
}

string ai::get_ai_name(){
	return ai_name;
}

void ai::set_bet_type(int* shoe_card, int idx){
   //if bet = 0 the bet is for the player
   //   bet = false
   //if bet = 1 the bet is for the banker
   //   bet = true
   //if bet = 2 the result is a tie
   //	banker_bet = banker_player;
   if((ai_name == "always banker")||(ai_name == "double up banker")){
	banker_bet = 1;
   }
   if((ai_name == "always player")||(ai_name == "double up player")){
	banker_bet = 0;
   }
   if(ai_name == "alternate banker and player"){
	if(banker_bet == 1){
		banker_bet = 0;
	}
	else{
		banker_bet = 1;
	}
   }
   if(ai_name == "copy last win"){
        if(idx == -1){
		banker_bet = 1;
	}
	else if(shoe_card[idx] == 2){
		banker_bet = 1;
	}
	else{
   	   banker_bet = shoe_card[idx];
	}
   }

   if((capital - bet) < 0){
	bet = capital;
   }

}

int ai::get_bet_type(){
	return banker_bet;
}

void ai::set_bet(int num, int* shoe_card, int idx){
   //most likely this wont be called unless we change the program
   //to dynamic bets
   //bet = num;
   if(idx == -1){
	bet = 10;
   }
   else if(shoe_card[idx] == banker_bet){
	bet = 10;
   }
   else if(shoe_card[idx] == 2){
	bet += 0;
   }
   else{
	bet *= 2;
	if(bet > 300){
		bet = 300;
	}
   }
   if((capital - bet) < 0){
	bet = capital;
   }

}

int ai::get_bet(){
	return bet;
}

void ai::add_to_capital(int num){
	capital += num;
} 

void ai::sub_from_capital(int num){
	capital -= num;
}

int ai::get_capital(){
	return capital;
}
