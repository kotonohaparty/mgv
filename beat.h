#ifndef _BEAT_H_
#define _BEAT_H_

#include "base.h"

/* for beat */
#define GSTRINGS   6
#define GFRETS     22

/*
class beat
*/
class beat
{
public:
  beat();
	beat(uchar *im);
	//beat(uchar_vector &vitem);
	beat(const beat &bt);
	int add_item(const uchar string, const uchar fret);
	int delete_item(const uchar gstr);
	void clean();

	beat operator=(const beat& bt);

	//
	void show();
private:
	uchar_vector item_vtr;
	bool useful;
};

typedef std::vector<beat*> beat_vector;

#endif
