#include "countbanker.h"
#include <iostream>
#include <string>

using namespace std;

countBanker::countBanker(int num){
	ai_name = "count banker";
	capital = num;
	//bet will be handled in base class set bet function
	//banker_bet will be implemented below
}

void countBanker::set_bet_type(int* shoe_card, int idx, int count){
	banker_bet = 1;
}
