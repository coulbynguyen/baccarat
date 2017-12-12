#include <iostream>
#include <string>

using namespace std;

#ifndef AI
#define AI

class ai{
	private:
	   string ai_name;
	   bool banker_bet;
	   int bet;
	   int capital;
	public:
	   ai(string);
	   string get_ai_name();
	   void set_bet_type(bool);
	   bool get_bet_type();
	   void set_bet(int);
	   int get_bet();
	   void add_to_capital(int);
	   void sub_from_capital(int);
	   int get_capital();



};

#endif
