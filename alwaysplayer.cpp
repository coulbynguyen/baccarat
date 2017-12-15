#include "alwaysplayer.h"
#include <iostream>
#include <string>
using namespace std;

alwaysPlayer::alwaysPlayer(int num){
	ai_name = "always player";
	capital = num;
	//bet will be handled by base class set bet function
	//banker_bet will be handled by function in this class
}

void alwaysPlayer::set_bet_type(int* shoe_card, int idx, int count){
	banker_bet = 0;
}
void alwaysPlayer::output_to_file(int p){
        ofstream output;
	if(p == 0){
		output.open("a/alwaysplayerBET10.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 1){
		output.open("a/alwaysplayerBET25.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 2){
		output.open("a/alwaysplayerDOUBLEUP.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 3){
		output.open("a/alwaysplayer1324.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 4){
		output.open("a/alwaysplayerFIBONACCI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 5){
		output.open("a/alwaysplayerDALEMBERT.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 6){
		output.open("a/alwaysplayerPAROLI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 7){
		output.open("a/alwaysplayerCOUNTBET.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	output.close();
}
