#include "ai.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef COUNTBANKER_H
#define COUNTBANKER_H
class countBanker : public ai{
	protected:

	public:
	   countBanker(int);
	   void set_bet_type(int*, int, int);

};

#endif
