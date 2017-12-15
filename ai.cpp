#include <iostream>
#include <string>
#include "ai.h"

using namespace std;

string ai::get_ai_name(){
	return ai_name;
}

int ai::bet10(){
	return 10;
}

int ai::bet25(){
	return 25;
}

int ai::doubleup(int local_bet, int* shoe_card, int idx){
   	if(idx == -1){
		local_bet = 10;
		return local_bet;
	}
	if(banker_bet == shoe_card[idx]){
		local_bet = 10;
		return local_bet;
	}
	else if(shoe_card[idx] == 2){
		local_bet += 0;
		return local_bet;
	}
	else{
		local_bet *= 2;
		return local_bet;
	}
}

int ai::one_three_two_four(int* shoe_card, int idx){
//	cycle1324 needs to be created under the protected variables
	if(idx == -1){
		return 10;
	}
	//check this conditional and the one below
	else if(banker_bet == shoe_card[idx]){
		if((cycle1324%4) == 0){
		        cycle1324++;
			return 10;
		}
		else if((cycle1324%4) == 1){
		        cycle1324++;
			return 30;
		}
		else if((cycle1324%4)==2){
		        cycle1324++;
			return 20;
		}
		else{
		        cycle1324++;
			return 40;
		}
	}
	else if(shoe_card[idx] == 2){
		//bet does not change
	}
	else{
	   	cycle1324 = 0;
		return 10;
	}
}
int ai::fibonacci(int* shoe_card, int idx){
	int fibnum[14] = {10, 10, 20, 30, 50, 80, 130, 210, 340, 550, 890, 1440, 2330, 3770};
	//need to declare fibidx in protected
	if(capital - fibnum[fibidx] < 0){
		fibidx = 0;
		return fibnum[fibidx];
	}
	if(idx == -1){
		fibidx = 0;
		return fibnum[fibidx];
	}
	else{
		if(banker_bet == shoe_card[idx]){
			if(fibidx - 2 < 0){
			   	fibidx = 0;
				return fibnum[fibidx];
			}
			else{
				fibidx -= 2;
				return fibnum[fibidx];
			}
		}
		else if(shoe_card[idx] == 2){
			//do nothing
		}
		else{
			fibidx++;
			return fibnum[fibidx];
		}
	}

}

int ai::dalembert(int* shoe_card, int idx, int local_bet){
	if(local_bet <= 10){
		return 10;
	}


   	if(idx == -1){
		return local_bet;
	}
	else{
		if(banker_bet == shoe_card[idx]){
			return local_bet - 1;
		}
		else if(shoe_card[idx] == 2){
			//do nothing
		}
		else{
			return local_bet + 1;
		}
	}
}

int ai::paroli(int* shoe_card, int idx){
   //paroli cycle needs to be added to protected
	if(idx == -1){
	        paroli_cycle = 0;
		return 10;
	}
	else{
		if(banker_bet == shoe_card[idx]){
			paroli_cycle++;
			if((paroli_cycle%3) == 0){
				return 10;
			}
			else if((paroli_cycle%3) == 1){
				return 20;
			}
			else if((paroli_cycle%3) == 2){
				return 40;
			}

		}
		else if(shoe_card[idx] == 2){
			//do nothing
		}
		else{
			paroli_cycle = 0;
			return 10;
		}

	}
}

int ai::count_bet(int count){
	if(count > 10){
		return 25;
	}
	else if(count > 5){
		return 10;
	}
	else if(count < -10){
		return 25;
	}
	else if(count < -5){
		return 10;
	}
	else{
		return 0;
	}
}

int ai::get_bet_type(){
	return banker_bet;
}

void ai::set_bet(int count, int* shoe_card, int idx, int position){
   //most likely this wont be called unless we change the program
   //to dynamic bets
   //bet = num;
   if(position == 0){
	bet = bet10();
   }
   else if(position == 1){
	bet = bet25();
   }
   else if(position == 2){
	bet = doubleup(bet, shoe_card, idx);
   }
   else if(position == 3){
	bet = one_three_two_four(shoe_card, idx);
   }
   else if(position == 4){
	bet = fibonacci(shoe_card, idx);
   }
   else if(position == 5){
	bet = dalembert(shoe_card, idx, bet);
   }
   else if(position == 6){
	bet = paroli(shoe_card, idx);
   }
   else if(position = 7){
	bet = count_bet(count);
   }
   bet *= 2; 
   if((capital - bet) <= 0){
	bet = capital;
   }
   
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

void ai::stop_betting(){
	bet = 0;
}

