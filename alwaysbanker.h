#include "ai.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef ALWAYSBANKER_H
#define ALWAYSBANKER_H
class alwaysBanker : public ai{
	protected:

	public:
	   alwaysBanker(int);
	   void set_bet_type(int*, int, int);
	   

};


#endif
