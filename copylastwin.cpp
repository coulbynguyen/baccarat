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
void copyLastWin::output_to_file(int p){
        ofstream output;
	if(p == 0){
		output.open("a/copylastwinBET10.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 1){
		output.open("a/copylastwinBET25.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 2){
		output.open("a/copylastwinDOUBLEUP.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 3){
		output.open("a/copylastwin1324.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 4){
		output.open("a/copylastwinFIBONACCI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 5){
		output.open("a/copylastwinDALEMBERT.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 6){
		output.open("a/copylastwinPAROLI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 7){
		output.open("a/copylastwinCOUNTBET.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	output.close();
}
