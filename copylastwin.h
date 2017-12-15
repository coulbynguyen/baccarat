#include "ai.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef COPYLASTWIN_H
#define COPYLASTWIN_H
class copyLastWin : public ai{
	protected:

	public:
	   copyLastWin(int);
	   void set_bet_type(int*, int, int);
	   void output_to_file(int);


};

#endif
