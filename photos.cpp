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

			    		spacePosition = newSpacePosition;
			    		newSpacePosition = line.find(' ', spacePosition);

			    		int nbTags = stoi(nbTag);
			    		for(int i=0; i<nbTags-2 ; i++)
			    		{
			    			string tag = line.substr(spacePosition+1, newSpacePosition + 1 - spacePosition);
			    			multimap<string, int> tempMap;
			    			tempMap.insert(pair<string, int>(tag, lineCount-1));
			    			photoSet.insert(pair<bool, multimap<string, int>>(vertical, tempMap));

			    			spacePosition = newSpacePosition;
			    			newSpacePosition = line.find(' ', spacePosition);
			    		}
			    		string tag = line.substr(spacePosition+1, newSpacePosition + 1 - spacePosition);
			    		multimap<string, int> tempMap;
		    			tempMap.insert(pair<string, int>(tag, lineCount-1));
		    			photoSet.insert(pair<bool, multimap<string, int>>(vertical, tempMap));
		    			
		    			spacePosition = newSpacePosition;
			    		size_t lineLength = line.length();		    			
		    			newSpacePosition = lineLength;

			    		string lastTag = line.substr(spacePosition+1, lineLength - spacePosition);
		    			multimap<string, int> tempMap2;
		    			tempMap2.insert(pair<string, int>(tag, lineCount-1));
		    			photoSet.insert(pair<bool, multimap<string, int>>(vertical, tempMap));

			    	}
			    }
			}
		}