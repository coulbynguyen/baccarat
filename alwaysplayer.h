#include "ai.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef ALWAYSPLAYER_H
#define ALWAYSPLAYER_H
class alwaysPlayer : public ai{
	protected:

	public:
	   alwaysPlayer(int);
	   void set_bet_type(int*, int, int);

};
#endif
