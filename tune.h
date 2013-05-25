#ifndef _TUNE_H_
#define _TUNE_H_

#include "bar.h"

class tune
{
public:
  tune();
	int add_bar();
	int delete_bar();
	bool useful();
	int clean();

	void show();
private:
	bar_vector bar_vtr;
	bool use;
}

#endif
