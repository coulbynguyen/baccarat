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
void countPlayerHigh::output_to_file(int p){
        ofstream output;
	if(p == 0){
		output.open("a/countplayerhighBET10.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 1){
		output.open("a/countplayerhighBET25.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 2){
		output.open("a/countplayerhighDOUBLEUP.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 3){
		output.open("a/countplayerhigh1324.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 4){
		output.open("a/countplayerhighFIBONACCI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 5){
		output.open("a/countplayerhighDALEMBERT.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 6){
		output.open("a/countplayerhighPAROLI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 7){
		output.open("a/countplayerhighCOUNTBET.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	output.close();
}
