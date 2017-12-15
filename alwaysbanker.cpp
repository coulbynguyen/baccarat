#include "alwaysbanker.h"
#include <string>
#include <iostream>

using namespace std;

alwaysBanker::alwaysBanker(int a){
	ai_name = "always banker";
	capital = a;
	//bet will be handled by set bet function in base class
	//banker bet will be handled by set bet type functionality	
}

void alwaysBanker::set_bet_type(int* shoe_card, int idx, int count){
	banker_bet = 1;
}
