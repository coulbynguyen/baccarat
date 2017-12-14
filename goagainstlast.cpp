#include "goagainstlast.h"
#include <string>
#include <iostream>

using namespace std;

goAgainstLast::goAgainstLast(int num){
	ai_name = "go against last win";
	capital = num;
	//bet will be handled by base class set bet function
	//banker_bet will be handled by a function below

}

void goAgainstLast::set_bet_type(int* shoe_card, int idx, int count){
	if(idx == -1){
		banker_bet = 1;
	}
	else{
		if(shoe_card[idx] == 0){
			banker_bet = 1;
		}
		else if(shoe_card[idx] == 1){
			banker_bet = 0;
		}
	}
}
