#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

typedef multimap<string, int> InnerMap;
typedef multimap<bool, InnerMap> Multimap;

class Photos
{
	public:
		Photos(){}
		~Photos(){}
		
		Multimap photoSet; 
		// multimap<orientation, multimap<tag, photoNum>>
		int nbPhotos;

		void readFile(string filename);
		void printPhotoSet();
		list<vector<int>> getSolution();
};