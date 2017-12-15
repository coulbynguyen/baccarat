#include "ai.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef ALTERNATE_H
#define ALTERNATE_H
class alternate : public ai{
	protected:

	public:
	   alternate(int);
	   void set_bet_type(int*, int, int);
	   void output_to_file(int);

};
#endif
