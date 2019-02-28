#include <iostream>
#include <fstream>

#include "photos.h"

void Photos::readFile(string filename)
{
	string line;
	
	ifstream inputFile;
	inputFile.open(filename);

	if(inputFile.is_open())
	{
		int lineCount = 0; // line counter
		while ( getline (inputFile, line) )
	    {
	    	if (lineCount==0)
	    	{
	    		nbPhotos = stoi(line);
	    	}
	    	else
	    	{
	    		string::size_type spacePosition = line.find(' ');
	    		string orientation = line.substr(0, spacePosition);
	    		bool vertical;
	    		if(orientation == "H")
	    		{
	    			vertical = false;
	    		}
	    		else
	    		{
	    			vertical = true;
	    		}
	    		string::size_type newSpacePosition = line.find(' ', spacePosition);
	    		string nbTag = line.substr(spacePosition+1, newSpacePosition + 1 - spacePosition);
	    		int nbTags = stoi(nbTag);

	    		spacePosition = newSpacePosition;
	    		newSpacePosition = line.find(' ', spacePosition);

	    		for(int i=0; i<nbTags-2 ; i++)
	    		{
	    			string tag = line.substr(spacePosition+1, newSpacePosition + 1 - spacePosition);
	    			multimap<string, int> tempMap;
	    			tempMap.insert(make_pair(tag, lineCount-1));
	    			photoSet.insert(make_pair(vertical, tempMap));

	    			spacePosition = newSpacePosition;
	    			newSpacePosition = line.find(' ', spacePosition);
	    		}
	    		string tag = line.substr(spacePosition+1, newSpacePosition + 1 - spacePosition);
	    		multimap<string, int> tempMap;
    			tempMap.insert(make_pair(tag, lineCount-1));
    			photoSet.insert(make_pair(vertical, tempMap));
    			
    			spacePosition = newSpacePosition;
	    		size_t lineLength = line.length();		    			
    			newSpacePosition = lineLength;

	    		string lastTag = line.substr(spacePosition+1, lineLength - spacePosition);
    			multimap<string, int> tempMap2;
    			tempMap2.insert(make_pair(tag, lineCount-1));
    			photoSet.insert(make_pair(vertical, tempMap));

	    	}
			lineCount++;
	    }
	}
	else
	{
		cout << "Couldn't read " << filename << endl;
	}
}

void Photos::printPhotoSet()
{
	cout << "printing photo set" << endl;
	if(photoSet.empty())
	{
		cout << "the map is empty" << endl;
	}
	multimap<bool,multimap<string, int>>::iterator itOrient;
	for(itOrient = photoSet.begin() ; itOrient != photoSet.end() ; ++itOrient)
	{
		cout << (*itOrient).first << " photo with tag:" << endl;
		multimap<string, int>::iterator itTag;
		for (itTag = (*itOrient).second.begin() ; itTag != (*itOrient).second.end() ; ++itTag)
		{
			cout << "tag = " << (*itTag).first <<  " ==> photo id = " << (*itTag).second << endl;
		}
	}
}

list<vector<int>> Photos::getSolution()
{
	list<vector<int>> res;
	multimap<bool, multimap<string, int>>::iterator it;
	multimap<string, int>::iterator it2;
	for ( it = photoSet.begin() ; it != photoSet.end() ; ++it)
	{
		if(it->first)
		{
			for ( it2 = (it->second).begin() ; it2 != (it->second).end() ; ++it2)
			{
				vector<int> v;
				v.push_back(it2->second);
				it2++;
				if(it2 != (it->second).end())
				{
					res.push_back(v);
					 break;
				}
				v.push_back(it2->second);
				res.push_back(v);
			}
		}
		else
		{
			for ( it2 = (it->second).begin() ; it2 != (it->second).end() ; ++it2)
			{
				vector<int> v;
				v.push_back(it2->second);
				res.push_back(v);
				
			}
		}
	}
	return res;
}