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
	    		string::size_type newSpacePosition = line.find(' ', spacePosition+1);
	    		string nbTag = line.substr(spacePosition+1, newSpacePosition + 1 - spacePosition);
	    		int nbTags = stoi(nbTag);

	    		spacePosition = newSpacePosition;
	    		cout << "1er espace a la position : " << spacePosition << endl;
	    		newSpacePosition = line.find(' ', spacePosition+1);
	    		cout << "2e espace a la position : " << newSpacePosition << endl;
				
				Multimap::iterator itOrient;
	    		for(int i=0; i<nbTags-2 ; i++)
	    		{
	    			string tag = line.substr(spacePosition+1, newSpacePosition - 1 - spacePosition);
	    			cout << i << "eme tag de la photo " << lineCount-1 << " est " << tag << endl;
	    			for(itOrient = photoSet.begin() ; itOrient != photoSet.end() ; ++itOrient)
					{
						if((*itOrient).second.find(tag)!= (*itOrient).second.end()) // tag found
		    			{
		    				cout << "new pair!" << endl;
		    				InnerMap tempMap;
			    			tempMap.insert(make_pair(tag, lineCount-1));
			    			photoSet.insert(make_pair(vertical, tempMap));
			    			break;
		    			}
						
					}
	    			spacePosition = newSpacePosition+1;
	    			newSpacePosition = line.find(' ', spacePosition);
	    			cout << i+3 << "e espace a la position : " << newSpacePosition << endl;
	    		}
	    		string tag = line.substr(spacePosition, newSpacePosition - spacePosition);
	    		cout << nbTags-2 << "eme tag de la photo " << lineCount-1 << " est " << tag << endl;

				for(itOrient = photoSet.begin() ; itOrient != photoSet.end() ; ++itOrient)
				{
					if((*itOrient).second.find(tag)!= (*itOrient).second.end()) // tag found
	    			{
	    				cout << "new pair!" << endl;
	    				multimap<string, int> tempMap;
		    			tempMap.insert(make_pair(tag, lineCount-1));
		    			photoSet.insert(make_pair(vertical, tempMap));
		    			break;
	    			}
				}	    		
    			
    			spacePosition = newSpacePosition+1;
	    		size_t lineLength = line.length();	    			
    			newSpacePosition = lineLength;

	    		string lastTag = line.substr(spacePosition, lineLength - spacePosition);
	    		cout << nbTags-1 << "eme tag de la photo " << lineCount-1 << " est " << lastTag << endl;
    			for(itOrient = photoSet.begin() ; itOrient != photoSet.end() ; ++itOrient)
				{
					if((*itOrient).second.find(tag)!= (*itOrient).second.end()) // tag found
	    			{
	    				cout << "new pair!" << endl;
	    				multimap<string, int> tempMap;
		    			tempMap.insert(make_pair(tag, lineCount-1));
		    			photoSet.insert(make_pair(vertical, tempMap));
		    			break;
	    			}
				}
    			cout << endl;
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
		cout << "There are " << photoSet.count((*itOrient).first) << " elements with key " << (*itOrient).first << endl;
		cout << "[ " ;
		multimap<string, int>::iterator itTag;
		for (itTag = (*itOrient).second.begin() ; itTag != (*itOrient).second.end() ; ++itTag)
		{
			cout << "There are " << (*itOrient).second.count((*itTag).first) << " elements with key " << (*itTag).first << ":";
			multimap<string, int>::iterator it;
			for (it=(*itOrient).second.equal_range((*itTag).first).first; it!=(*itOrient).second.equal_range((*itTag).first).second; ++it)
	    	{
	    		cout << ' ' << (*it).second;
	    	}
	    	cout << endl;
		}
		cout << "]" << endl;
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