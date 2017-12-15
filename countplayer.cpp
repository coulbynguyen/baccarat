#include "countplayer.h"
#include <iostream>
#include <string>

using namespace std;

countPlayer::countPlayer(int num){
	ai_name = "count player";
	capital = num;
	//bet will be handled in base class function
	//banker_bet will be implemented in below function
}

void countPlayer::set_bet_type(int*, int, int){
	banker_bet = 0;
}
void countPlayer::output_to_file(int p){
        ofstream output;
	if(p == 0){
		output.open("a/countplayerBET10.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 1){
		output.open("a/countplayerBET25.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 2){
		output.open("a/countplayerDOUBLEUP.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 3){
		output.open("a/countplayer1324.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 4){
		output.open("a/countplayerFIBONACCI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 5){
		output.open("a/countplayerDALEMBERT.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 6){
		output.open("a/countplayerPAROLI.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	if(p == 7){
		output.open("a/countplayerCOUNTBET.txt", ofstream::out | ofstream::app);
		output << capital << endl;
	}
	output.close();
}
