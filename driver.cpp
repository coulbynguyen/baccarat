#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "driverfunctions.h"
#include <fstream>

using namespace std;

int main(){
	srand(time(NULL));
   
   	int shoe[416] = {};
	int top_of_shoe = 0; //this number needs to change based on the first card
	int red_card = 416 - (rand()%52+52);
	int count = 0;
	int hand_number = 0;
        
	int hand_result = -1; // -1 no hand has played yet // 0 = bank win // 1 = player win // 2 = tie
	int* cards_played; // first 3 corespond to player last 3 corespond to banker
	fill_shoe(shoe);
	
	top_of_shoe = shoe[top_of_shoe+1];
	
	ofstream labels;
	labels.open("labels.txt", ios::app);

	ofstream newcount;
	newcount.open("newcount.txt", ios::app);

	ofstream handcount;
	handcount.open("handnumber.txt", ios::app);

	while(top_of_shoe < red_card){
	   	hand_number++;
		
		
		//print out count, winner, cards
	   	if(hand_number > 1){
			labels << hand_result << endl;
			newcount << count << endl;
			handcount << hand_number << endl;		

		}
		
		
		//deal hands & determine winner & update top_of_shoe
		cards_played = play_hand(shoe, top_of_shoe, count, hand_result);
	   	
		//print out hand and winner of every hand
	/*
		cout << "HAND " << hand_number << endl;
		for(int i = 0; i < 6; i++){
		   if(cards_played[i] == -1){
		      cout << " ";
		   }
		   else{
		      cout << cards_played[i] << " ";
		   }

		   if(i == 2){
			cout << "|| ";
		   }
		}
		cout << "WINNER: " << hand_result << " COUNT: " << count <<  endl;
		cout << endl;
	*/
		//update count, winner
	}
	return 0;
}
