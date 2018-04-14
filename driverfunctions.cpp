#include "driverfunctions.h"
#include <fstream>

using namespace std;



void fill_shoe(int shoe[416]){
	ifstream read_deck;
	read_deck.open("deck_file");

	for(int i = 0; i < 416; i++){
		read_deck >> shoe[i];
	}
}

void adjustcount(int card, int& count){
	if((card == 1) || (card == 2) || (card == 3)){
		count += 1;
	}	   
	else if(card == 4){
		count += 2;	
	}
	else if((card == 5) || (card == 7) || (card == 8)){
		count -= 1;
	}
	else if(card == 6){
		count -= 2;
	}

}


int winner(int bank, int player){
	if(bank > player){
		//bank wins bank == 0 signifier
		return 0;
	}
	else if(bank < player){
		//player wins player == 1 signifier
		return 1;
	}
	else if(bank == player){
		//tie || tie == 2 signifier
		return 2;
	}
}

int* play_hand(int shoe[416], int& top_of_shoe, int& count, int& hand_result){
	int player = 0;
	int bank = 0;
	int* cards_played = new int[6]; //negative one means that card was not used
    
	for(int i = 0; i < 6; i++){
		cards_played[i] = -1;
	}

	//player gets first card -- its first card
	player += shoe[top_of_shoe];
	
	//need to adjust the count after every "draw"
	adjustcount(shoe[top_of_shoe], count);
	
	//puts that in the 1st slot of cards played
	cards_played[0] = shoe[top_of_shoe];
	
	//top_of_shoe increments by one
	top_of_shoe++;
	
	
	
	//bank gets second card -- its first card
	bank += shoe[top_of_shoe];
	
	//need to adjust the count after every "draw"
	adjustcount(shoe[top_of_shoe], count);
	
	//puts that in the 4th slot of cards played because player can have max 3 cards
	cards_played[3] = shoe[top_of_shoe];
	
	//top_of_shoe increments by one
	top_of_shoe++;

	
	
	//player gets third card -- its second card
	player += shoe[top_of_shoe];
	
	//need to adjust the count after every "draw"
	adjustcount(shoe[top_of_shoe], count);
	
	//puts that in the 2nd slot of cards played because this is player 2nd card
	cards_played[1] = shoe[top_of_shoe];
	
	//top_of_shoe increments by one
	top_of_shoe++;



	//bank gets fourth card -- its second card
	bank += shoe[top_of_shoe];

	//need to adjust the count after every "draw"
	adjustcount(shoe[top_of_shoe], count);

	//puts that in the 5th slot of cards played because this is banks 2nd card
	cards_played[4] = shoe[top_of_shoe];

	//top_of_shoe increments by one
	top_of_shoe++;



	// to get baccarat score, number mod 10;
	player %= 10;
	bank %= 10;

	if((player == 8) || (player == 9) || (bank == 8) || (bank == 9)){
	   //naturals no other cards are drawn
	   hand_result = winner(bank, player);
	   return cards_played;
	}
	else if(((player == 6) || (player == 7)) && (bank <= 5)){
	   //player hands stands on 6 and 7
	   //bank has to draw when their total is 6 or below

	   //bank gets fifth card -- its third card
	   bank += shoe[top_of_shoe];

	   //need to adjust the count after every "draw"
	   adjustcount(shoe[top_of_shoe], count);

	   //need to get the baccarat value of banker so mod it by 10
	   bank %= 10;

	   //puts that in the 6th slot of cards played because this is bank 3rd card
	   cards_played[5] = shoe[top_of_shoe];

	   //top_of_shoe increments by one
	   top_of_shoe++;

	   //calls a function to tell who wins or if tie
	   hand_result = winner(bank, player);
	   return cards_played;
	}
	else if(((player == 6) || (player == 7)) && (bank > 5)){
	   //if player = 6 or 7 and bank equals 6 or 7 just determine who wins

	   //calls a function to tell who wins or if tie
	   hand_result = winner(bank,player);
	   return cards_played;
	}
	else if(player < 6){
	   //if the players baccarat total is less than 6 = {0, 1, 2, 3, 4, 5}
	   //player has to draw

	   //player gets 5th card -- its third card
	   player += shoe[top_of_shoe];

	   //need to adjust the count after every "draw"
	   adjustcount(shoe[top_of_shoe], count);

	   //need to store that third card as bankers value is dependent on it
	   int player_third_card = shoe[top_of_shoe];

	   //need to get the baccarat value of banker so mod it by 10
	   player %= 10;

	   //puts that in the 3rd slot of cards played because this is player 3rd card
	   cards_played[2] = shoe[top_of_shoe];

	   //top_of_shoe increments by one
	   top_of_shoe++;

	   if(bank <= 2){
	      //bank has to draw if their total is less than 2

	      //bank gets 6th card -- its third card
	      bank += shoe[top_of_shoe];

	      //need to adjust the count after every "draw"
	      adjustcount(shoe[top_of_shoe], count);

	      //need to get the baccarat value of banker so mod it by 10
	      bank %= 10;

	      //put that in the 6th slot of cards played because this is bank 3rd card
	      cards_played[5] = shoe[top_of_shoe];

	      //top_of_shoe increments by one
	      top_of_shoe++;

	      //calls a function to tell who wins or if tie
	      hand_result = winner(bank, player);
	      return cards_played;
	   }
	   else if((bank == 3)&&(player_third_card != 8)){
	      //if the bank totals 3 and the players 3rd card IS NOT an 8

	      //bank gets 6th card -- its third card
	      bank += shoe[top_of_shoe];

	      //need to adjust the count after every "draw"
	      adjustcount(shoe[top_of_shoe], count);

	      //need to get the baccarat value of banker so mod it by 10
	      bank %= 10;

	      //put that in the 6th slot of cards played because this is bank 3rd card
	      cards_played[5] = shoe[top_of_shoe];

	      //top_of_shoe increments by one;
	      top_of_shoe++;

	      //calls a funciton to tell who wins or if tie
	      hand_result = winner(bank, player);
	      return cards_played;
	   }
	   else if((bank == 4)&&((player_third_card != 1)&&(player_third_card != 8)&&(player_third_card != 9)&&(player_third_card != 10))){
	      //if the bank totals 4 and the players 3rd card IS NOT 1 8 9 or 10

	      //bank gets 6th card -- its third card
	      bank += shoe[top_of_shoe];

	      //need to adjust the count after every "draw"
	      adjustcount(shoe[top_of_shoe], count);

	      //need to get the baccarat value of banker so mod it by 10
	      bank %= 10;

	      //put that in the 6th slot of cards played because this is bank 3rd card
	      cards_played[5] = shoe[top_of_shoe];

	      //top_of_shoe increments by one;
	      top_of_shoe++;

	      //calls a function to tell who wins or if tie
	      hand_result = winner(bank, player);
	      return cards_played;
	   }
	   else if((bank == 5)&&((player_third_card == 4)||(player_third_card == 5)||(player_third_card == 6)||(player_third_card == 7))){
	      //if the bank totals 5 and the player 3rd card IS either a 4 5 6 or 7

	      //bank gets 6th card -- its third card
	      bank += shoe[top_of_shoe];

	      //need to adjust the count after every "draw"
	      adjustcount(shoe[top_of_shoe], count);

	      //need to get the baccarat value of banker so mod it by 10;
	      bank %= 10;

	      //put that in the 6th slot of cards played because this is bank 3rd card
	      cards_played[5] = shoe[top_of_shoe];

	      //top_of_shoe increments by one;
	      top_of_shoe++;

	      //calls a function to tell who wins or if tie
	      hand_result = winner(bank, player);
	      return cards_played;
	   }
	   else if((bank == 6)&&((player_third_card == 6)||(player_third_card == 7))){
	      //if the bank totals 6 and the player 4rd card IS either a 6 or 7

	      //bank gets 6th card -- its third card
	      bank += shoe[top_of_shoe];

	      //need to adjust the count after every "draw"
	      adjustcount(shoe[top_of_shoe], count);

	      //needs to get the baccarat value of banker so mod it by 10;
	      bank %= 10;

	      //put that in the 6th slot of cards played because this is bank 3rd card
	      cards_played[5] = shoe[top_of_shoe];

	      //top_of_shoe increments by one;
	      top_of_shoe++;

	      //calls a function to tell who wins or if tie
	      hand_result = winner(bank, player);
	      return cards_played;
	   }
	   else if(bank == 7){
	      //if the bank totals 7 it doesnt draw a card ever

	      //calls a function to tell who wins or if tie
	      hand_result = winner(bank, player);
	      return cards_played;

	   }
	   else{
	      //the cases where the banker doesnt draw a card needs to be evaluated
	      hand_result = winner(bank, player);
	      return cards_played;
	   }
	}
}





















