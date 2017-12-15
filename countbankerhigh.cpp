#include "countbankerhigh.h"
#include <iostream>
#include <string>

using namespace std;
countBankerHigh::countBankerHigh(int num){
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
void countBankerHigh::output_to_file(int p){
        ofstream output;
	if(p == 0){
		output.open("a/countbankerhighBET10.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 1){
		output.open("a/countbankerhighBET25.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 2){
		output.open("a/countbankerhighDOUBLEUP.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 3){
		output.open("a/countbankerhigh1324.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 4){
		output.open("a/countbankerhighFIBONACCI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 5){
		output.open("a/countbankerhighDALEMBERT.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 6){
		output.open("a/countbankerhighPAROLI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 7){
		output.open("a/countbankerhighCOUNTBET.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	output.close();
}
