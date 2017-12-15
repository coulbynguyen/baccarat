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
void goAgainstLast::output_to_file(int p){
        ofstream output;
	if(p == 0){
		output.open("a/goagainstlastBET10.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 1){
		output.open("a/goagainstlastBET25.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 2){
		output.open("a/goagainstlastDOUBLEUP.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 3){
		output.open("a/goagainstlast1324.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 4){
		output.open("a/goagainstlastFIBONACCI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 5){
		output.open("a/goagainstlastDALEMBERT.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 6){
		output.open("a/goagainstlastPAROLI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 7){
		output.open("a/goagainstlastCOUNTBET.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	output.close();
}
