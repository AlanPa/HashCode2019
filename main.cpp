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
	return 0;
}
