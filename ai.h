#include <iostream>
#include <string>

using namespace std;

#ifndef AI
#define AI

class ai{
	protected:
	   string ai_name;
	   int banker_bet;
	   int bet;
	   int capital;
	public:
	   ai(string);
	   string get_ai_name(); // this one is fine
	   int count_set_bet_type(string, int); //take these out of this class
	   int count_set_bet(int); //this one is fine since it is a global betting technique
	   virtual void set_bet_type(int*, int, int) = 0; //pure virtual so that in every ai class it is redefined
	   int get_bet_type(); // this one doesnt need to be redefined in every class
	   void set_bet(int, int*, int); //if i set this up in this base class i dont have to redefine it
	   int get_bet(); // doesnt need to be redefined
	   void add_to_capital(int); //doesnt need to be redefined in every class
	   void sub_from_capital(int); //doesnt need to be redefined in every class
	   int get_capital(); //doesnt need to be redefined in every class



};

#endif
