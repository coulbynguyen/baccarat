#include <iostream>
#include <string>
#include "ai.h"


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void shuffle(int*);
void set_ai_bets(ai**, int*, int, int);
void pay_ai_bets(ai**, int);
int compare_the_hands(int, int);
void adjust_count(int&, int);
int winner_of_hand(int*, int&, int&);
void improved_shoe_card(int*, int, int shoe_card2[20][50]);
void update_shoe_card(int*, int&, int);
void burn_top_cards(int*, int&);
void print_winner(int, int&, int&, int&);
#endif
