#include <iostream>
#include <string>


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void shuffle(int*);
int compare_the_hands(int, int);
void adjust_count(int&, int, int&, int&, int&);
void streaks_to_file(int, int, int);
void update_streak(int&, int&, int);
int winner_of_hand(int*, int&, int&, int&, int&, int&);
void improved_shoe_card(int*, int, int shoe_card2[20][50]);
void update_shoe_card(int*, int&, int);
void burn_top_cards(int*, int&);
void print_winner(int, int&, int&, int&, int, int, int, int);
#endif
