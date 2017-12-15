#include "ai.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef GOAGAINSTLAST_H
#define GOAGAINSTLAST_H
class goAgainstLast : public ai{
	protected:

	public:
	   goAgainstLast(int);
	   void set_bet_type(int*, int, int);
	   void output_to_file(int);
};

#endif
