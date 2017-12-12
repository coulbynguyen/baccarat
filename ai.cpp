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

void ai::set_bet_type(bool banker_player){
   //if bet = 0 the bet is for the player
   //   bet = false
   //if bet = 1 the bet is for the banker
   //   bet = true
	banker_bet = banker_player;
}

bool ai::get_bet_type(){
	return banker_bet;
}

void ai::set_bet(int num){
   //most likely this wont be called unless we change the program
   //to dynamic bets
	bet = num;
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
