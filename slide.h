#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;


class Slide
{
	public:
		Slide(list<vector< int>> s);
		void Result();
		~Slide();
	protected:
		list<vector< int>> slide;


};
