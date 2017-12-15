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

void alwaysBanker::output_to_file(int p){
   	ofstream output;
	if(p == 0){
		output.open("a/alwaysbankerBET10.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 1){
		output.open("a/alwaysbankerBET25.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 2){
		output.open("a/alwaysbankerDOUBLEUP.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 3){
		output.open("a/alwaysbanker1324.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 4){
		output.open("a/alwaysbankerFIBONACCI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 5){
		output.open("a/alwaysbankerDALEMBERT.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 6){
		output.open("a/alwaysbankerPAROLI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 7){
		output.open("a/alwaysbankerCOUNTBET.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	output.close();
}
