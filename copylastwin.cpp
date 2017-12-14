#include "copylastwin.h"
#include <iostream>
#include <string>

using namespace std;

copyLastWin::copyLastWin(int num){
	ai_name = "copy last win";
	capital = num;
	//bet will be handled in bas class function
	//banker_bet will be set in function below

}

void copyLastWin::set_bet_type(int* shoe_card, int idx, int count){
	if(idx == -1){
		banker_bet = 1;
	}
	else{
	   if(shoe_card[idx] != 2){
		banker_bet = shoe_card[idx];
	   }
	}
}
