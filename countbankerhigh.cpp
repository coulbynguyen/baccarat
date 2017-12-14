#include "countbankerhigh.h"
#include <iostream>
#include <string>

using namespace std;
countBankerHigh(int num){
	ai_name = "count banker high";
	capital = num;
	//bet will be handled in the base class set bet function
	//banker_bet will be implemented below

}

void countBankerHigh::set_bet_type(int* shoe_card, int idx, int count){
	if(count >= 0){
		banker_bet = 1;

	}
	else{
		banker_bet = 0;
	}

}
