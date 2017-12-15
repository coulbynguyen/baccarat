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

void alternate::output_to_file(int p){
   	ofstream output;
	if(p == 0){
		
		output.open("a/alternateBET10.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 1){
		output.open("a/alternateBET25.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 2){
		output.open("a/alternateDOUBLEUP.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 3){
		output.open("a/alternate1324.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 4){
		output.open("a/alternateFIBONACCI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 5){
		output.open("a/alternateDALEMBERT.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 6){
		output.open("a/alternatePAROLI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 7){
		output.open("a/alternateCOUNTBET.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	output.close();
}
