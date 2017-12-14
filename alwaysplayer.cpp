#include "alwaysplayer.h"
#include <iostream>
#include <string
using namespace std;

alwaysPlayer::alwaysPlayer(int num){
	ai_name = "always player";
	capital = num;
	//bet will be handled by base class set bet function
	//banker_bet will be handled by function in this class
}

void alwaysPlayer::set_bet_type(int* shoe_card, int idx, int count){
	banker_bet = 0;
}
