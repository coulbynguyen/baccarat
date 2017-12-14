#include "ai.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef COUNTPLAYER_H
#define COUNTPLAYER_H
class countPlayer : public ai{
	protected:

	public:
	   countPlayer(int);
	   void set_bet_type(int*, int, int);

};

#endif
