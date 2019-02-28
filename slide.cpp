#include "slide.h"
#include <fstream>
#include <algorithm>
using namespace std;

Slide::Slide(list<vector< int>> s)
{
	slide = s;
}

void Slide::Result()
{
	ofstream outputFile;
	outputFile.open("slide.out");
	
	if(outputFile.is_open())
	{
		outputFile << slide.size() << endl;
		for (list<vector<int>>::iterator it = slide.begin() ; it != slide.end() ; ++it)
		{
			for(vector<int>::iterator it2 = it->begin() ; it2 != it->end() ; ++it2)
			{
				outputFile << *it2 << " ";
			}
			outputFile << endl;
		}
		outputFile.close();
	}
}

Slide::~Slide()
{
}
