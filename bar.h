#ifndef _BAR_H_
#define _BAR_H_

#include "beat.h"

/* for tune */
#define BEAT_PER_BAR 8

class bar
{
public:
        bar();
	int add_beat(const beat &bt, const uchar n);
	int delete_beat(const uchar n);
	void clean();
	bool useful();

	void show();

private:
	beat_vector beat_vtr;
	bool use;
};

typedef std::vector<bar*> bar_vector;

#endif
