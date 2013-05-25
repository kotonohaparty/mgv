#include "bar.h"

bar::bar()
{
  for (int i = 0; i < BEAT_PER_BAR; ++i){
		beat *bt = new beat();
		beat_vtr.push_back(bt);
	}
	use = true;
}

void bar::show()
{
	//std::cout<< beat_vtr.size() << std::endl;

	for (int i = 0; i < BEAT_PER_BAR; ++i){
	//	std::cout<< beat_vtr[i] << std::endl;
		beat_vtr[i]->show();
		std::cout<<std::endl;
	}
}

int bar::add_beat(const beat &bt, const uchar n)
{
	if (BEAT_PER_BAR > n){
		*beat_vtr[n] = bt;
		return 1;		
	}
	return -1;
}

int bar::delete_beat(const uchar n)
{
	if (BEAT_PER_BAR > n){
		beat_vtr[n]->clean();
		return 1;
	}
	return -1;
}

void bar::clean()
{
	use = false;
}

bool bar::useful()
{
	return use;
}

//template <class BEAT>
int main()
{
	bar tn;

	tn.show();

	std::cout<<"//////////"<<std::endl;

	beat *bt1 = new beat();
	beat *bt2 = new beat();
	beat *bt3 = new beat();

	bt1->add_item(0, 1);
	bt1->add_item(1, 3);
	bt1->add_item(2, 5);
	bt1->add_item(3, 7);
	bt1->add_item(4, 9);
	bt1->add_item(5, 11);

	tn.add_beat(*bt1, 6);	

	bt2->add_item(0, 2);
	bt2->add_item(1, 4);
	bt2->add_item(2, 6);
	bt2->add_item(3, 8);
	bt2->add_item(4, 10);
	bt2->add_item(5, 12);	

	tn.add_beat(*bt2, 7);	

	tn.show();

	tn.clean();

	std::cout<<tn.useful()<<std::endl;

	return 1;
}
