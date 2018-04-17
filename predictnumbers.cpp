#include <iostream>

using namespace std;

int main(){

	int hand_result;
	int hand_number = 0;

	int row = 0;
	int col = 0;

   	float bank_sum10 = 0;
	float bank_sum20 = 0;
	float bank_sum30 = 0;
	int bank_last30[30] = {0};


	float playersum10 = 0;
	float playersum20 = 0;
	float playersum30 = 0;
	int player_last30[30] = {0};

	int sixtrack[6][14] = {0};
	
	while(hand_result != -1){
           hand_number++;
	   bank_sum10 = 0;
	   bank_sum20 = 0;
	   bank_sum30 = 0;
	   playersum10 = 0;
	   playersum20 = 0;
	   playersum30 = 0;
	   cout << "ENTER HAND RESULT" << endl;
	   cin >> hand_result;
           row = (hand_number -1) % 6;
	   col = (hand_number -1) / 6;	   
	   sixtrack[row][col] = hand_result;

	   for(int i = 29; i > 0; i--){
		bank_last30[i] = bank_last30[i-1];
	   	player_last30[i] = player_last30[i-1];
	   }
	   if(hand_result == 0){
		bank_last30[0] = 1;
		player_last30[0] = 0;
	   }
	   else if(hand_result == 1){
		player_last30[0] = 1;
		bank_last30[0] = 0;
	   }
	   else{
		bank_last30[0] = 0;
		player_last30[0] = 0;
	   }
	   for(int i = 0; i < 10; i++){
		bank_sum10 += bank_last30[i];
		playersum10 += player_last30[i];
	   }
	   for(int i = 0; i < 20; i++){
		bank_sum20 += bank_last30[i];
		playersum20 += player_last30[i];
	   }
	   for(int i = 0; i < 30; i++){
		bank_sum30 += bank_last30[i];
		playersum30 += player_last30[i];
	   }
	   if(hand_number <= 10){
		bank_sum10 /= hand_number;
		playersum10 /= hand_number;
	   }
	   else{
		bank_sum10 /= 10;
		playersum10 /= 10;
	   }
	   if(hand_number <= 20){
		bank_sum20 /= hand_number;
		playersum20 /= hand_number;
	   }
	   else{
		bank_sum20 /= 20;
		playersum20 /= 20;
	   }
	   if(hand_number <= 30){
		bank_sum30 /= hand_number;
		playersum30 /= hand_number;
	   }
	   else{
		bank_sum30 /= 30;
		playersum30 /= 30;
	   }
	   cout << "STREAK" << "BANK LAST 10:" << bank_sum10 << "  BANK LAST 20:" << bank_sum20 << "  BANK LAST 30:" << bank_sum30 << "  PLAYER LAST 10:" << playersum10 << "  PLAYER LAST 20:" << playersum20 <<  "  PLAYER LAST 30:" << playersum20 << endl;
	}
}
