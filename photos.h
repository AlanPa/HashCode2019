#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

class Photos
{
	public:
		Photos(){}
		~Photos(){}
		multimap<bool, multimap<string, int>> photoSet; 
		// multimap<orientation, multimap<tag, photoNum>>
		int nbPhotos;

		void readFile(string filename);
		void printPhotoSet();
		list<vector<int>> getSolution();
};