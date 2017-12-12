#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ai.h"


using namespace std;

void shuffle(int* shoe){
   srand(time(NULL));
   int card_counts [13] = {};
   for(int z = 0; z < 13; z++){
	card_counts[z] = 0;
   }
   for(int i = 0; i < 416; i++){
      int card = rand() % 13 + 1;
      int a = card_counts[card];
      while(a == 32){
	 card = rand() % 13 + 1;
	 a = card_counts[card];
      }

      card_counts[card] += 1;
      
      if(card < 10){
	 shoe[i] = card;
      }
      else{
	 shoe[i] = 0;
      }

   }

}


int main(){

   int* shoe = new int[416];
   int card_counts [13] = {};
   shuffle(shoe);
   ai** list_of_ai = new ai*[4];
   list_of_ai[0] = new ai("always banker");
   list_of_ai[1] = new ai("always player");
   list_of_ai[2] = new ai("alternate banker and player");
   list_of_ai[3] = new ai("copy last win");

   //this is how you access the data
   //cout << list_of_ai[0]->get_ai_name() << endl;
   return 0;
}
