#include <iostream>
#include <string>

#include "slide.h"
#include "photos.h"

using namespace std;

int main()
{
	Photos photoSet;
	photoSet.readFile("inputFiles/a_example.txt");
	photoSet.printPhotoSet();
	list<vector<int>> r = photoSet.getSolution();
	Slide s(r);
	s.Result();

	return 0;
}
