#include <iostream>
#include <string>
#include <map>

using namespace std;

class Photos
{
	public:
		multimap<bool, multimap<string, int>> photoSet; 
		// multimap<orientation, multimap<tag, photoNum>>
		int nbPhotos;

	public:
		void readFile(string filename);
};