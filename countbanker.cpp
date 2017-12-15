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
void countBanker::output_to_file(int p){
   	ofstream output;
	if(p == 0){
		output.open("a/countbankerBET10.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 1){
		output.open("a/countbankerBET25.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 2){
		output.open("a/countbankerDOUBLEUP.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 3){
		output.open("a/countbanker1324.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 4){
		output.open("a/countbankerFIBONACCI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 5){
		output.open("a/countbankerDALEMBERT.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 6){
		output.open("a/countbankerPAROLI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 7){
		output.open("a/countbankerCOUNTBET.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	output.close();
}
