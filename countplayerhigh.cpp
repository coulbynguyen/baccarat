#include "countplayerhigh.h"
#include <iostream>
#include <string>

using namespace std;

countPlayerHigh::countPlayerHigh(int num){
	ai_name = "count player high";
	capital = num;
	//bet will be handled in the base class set bet function
	//banker_bet will be handled in the function below

}

void countPlayerHigh::set_bet_type(int* shoe_card, int idx, int count){
	if(count > 0){
		banker_bet = 0;
	}
	else{
		banker_bet = 1;
	}

}
