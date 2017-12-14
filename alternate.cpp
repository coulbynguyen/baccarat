#include "alternate.h"
#include <iostream>
#include <string>

using namespace std;

alternate::alternate(int num){
	ai_name = "alternate B P";
	capital = num;
	//bet will be handled by base class function
	//banker_bet will be set in a function below

}

void alternate::set_bet_type(int* shoe_card, int idx, int count){
	if(banker_bet == 1){
		banker_bet = 0;
	}
	else{
		banker_bet = 1;
	}

}
