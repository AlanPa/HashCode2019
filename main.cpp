#include <iostream>
#include <string>

#include "slide.h"
#include "photos.h"

using namespace std;

int main()
{
	Photos photoSet;
	photoSet.readFile("input_files/a_example.txt");
	return 0;
}
