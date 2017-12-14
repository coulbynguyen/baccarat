#include "countplayer.h"
#include <iostream>
#include <string>

using namespace std;

countPlayer::countPlayer(int num){
	ai_name = "count player";
	capital = num;
	//bet will be handled in base class function
	//banker_bet will be implemented in below function
}

void countPlayer::set_bet_type(int*, int, int){
	banker_bet = 0;
}
