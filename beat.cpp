
#include "beat.h"

beat::beat()
{
  item_vtr = uchar_vector(GSTRINGS, 0xff);
	useful = true;
}

beat::beat(uchar *im)
{
	if (NULL != im){
		item_vtr = uchar_vector(im, im + GSTRINGS);
	}		
}

beat::beat(const beat &bt)
{
	item_vtr = bt.item_vtr;
}

int beat::add_item(const uchar string, const uchar fret)
{
	if (GSTRINGS > string && GFRETS > fret){
		item_vtr[string] = fret;
		return 1;
	}
	return -1;
}

int beat::delete_item(const uchar string)
{
	if (GSTRINGS > string)
	{
		item_vtr[string] = 0xff;
		return 1;
	}	
	return -1;
}

void beat::clean()
{
	useful = false;
	//item_vtr = uchar_vector(GSTRINGS, 0xff);
}

beat beat::operator=(const beat& bt)
{
	item_vtr = bt.item_vtr;
	return *this;
}

void beat::show()
{
	for (int i = 0; i < GSTRINGS; ++i){
		std::cout << i + 1 << " " << (int)item_vtr[i] << std::endl;
	}

	//std::cout<<item_vtr.size()<<std::endl;
	//std::cout<<item_vtr.empty()<<std::endl;
}

/*
int main()
{

	beat *bt = new beat();

	//bt->show();

	bt->add_item(0, 3);
	bt->add_item(1, 8);
	bt->add_item(2, 12);
	bt->add_item(3, 21);
	bt->add_item(4, 9);
	bt->add_item(5, 7);

	//bt->show();

	beat *bt2 = new beat(*bt);
	//beat bt2 = *bt;

	bt2->show();

	uchar *p = new uchar(GSTRINGS);
	for (int i = 0; i < GSTRINGS; ++i){
		p[i] = i + 2;
	}
	beat *bt3 = new beat(p);

	bt3->show();

	//beat bt = 0;

	//bt.show();


	return 1;
}
*/
