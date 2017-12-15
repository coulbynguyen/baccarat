#include "ai.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef COUNTPLAYERHIGH_H
#define COUNTPLAYERHIGH_H
class countPlayerHigh : public ai{
	protected:
	   
	public:
	   countPlayerHigh(int);
	   void set_bet_type(int*, int, int);
	   void output_to_file(int);

};
#endif
