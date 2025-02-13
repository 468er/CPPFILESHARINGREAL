
//Assignment done with the help of this stack overflow https://stackoverflow.com/questions/64782/how-do-you-append-an-int-to-a-string-in-c
//implement the given methods

#include <iostream>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;
using std::cout;
using std::endl;
#include "play.h"
#include "playTools.h"
#include <sstream>
Speech::Speech(string speaker,vector<string> lines){
    theSpeaker = speaker;
    theLines = lines;
    //initialize theSpeaker and theLines
    //to speaker and lines
}

string Speech::getSpeaker(){
    //return theSpeaker
    return theSpeaker;
}

vector<string> Speech::getLines(){
    //return theLines
    return theLines;
}

void Speech::print(){
    cout << theSpeaker << endl;
    for (int i = 0; i < theLines.size(); i++) {
        cout << theLines[i] << endl;

    }
    //print the speech using cout
    //this is primarily meant for debugging
    //so print what is useful to you
    //I'd recommend, theSpeaker and each line of the speech
    //at the very least
}


Scene::Scene(int actNum, int sceneNum, string loc){
    actNumber = actNum;
    sceneNumber = sceneNum;
    location = loc;
    //initialize actNumber, sceneNumber, and location to the
    //appropriate values
}

string Scene::toString(){
	std::stringstream oss;
	oss << "Act: " << actNumber << " Scene: " << sceneNumber << " Location: " << location;
    //Act: 2 Scene: 2 Location: Capulet's orchard.
    return oss.str();
//	return "test";
}

Play::Play(string title){
  	int stuff = 0;
	  theTitle = title;
    this->theScenes = makeListOfScenes(title);
    this->theSpeeches = makeListOfSpeeches(title);
    for (int i = 0; i < theSpeeches.size(); i++) { 
        
 	stuff = stuff + theSpeeches[i].getLines().size();
        
    }
	this->numLines = stuff;
//	this->numLines = theSpeeches.size();  
  //this will take in the title,set theTitle, and use it to generate
    //theScenes (see playTools.cpp), theSpeeches (see playTools.cpp),
    //and numLines (this one you'll have to do yourself)
        //numLines is the total number of lines in the play
        //this can be found by counting all of the lines in each
        //speech in theSpeeches
}

void Play::printAllScenes(){
    for (int i = 0; i < theScenes.size(); i++) {
        Scene currentScene = theScenes[i];
        cout << currentScene.toString() << endl;
        
    }
    //this will loop through all of the scenes in theScenes,
    //call its toString() method, and cout each scene on a
    //separate line
}

vector<string> Play::allParts(){
    vector<string> returnVectorOfString;
//		returnVectorOfString.push_back("test");
	int fstArLoopCnt = theSpeeches.size();
	int scndArLoopCnt = returnVectorOfString.size();
	 for (int a = 0; a <  fstArLoopCnt; a++) {
        for (int b = 0; b < scndArLoopCnt; b++) {
	if(a < theSpeeches.size() && b < returnVectorOfString.size()){
	//	std::string 
		
            if (theSpeeches[a].getSpeaker() == returnVectorOfString[b]) {
			
				a++;
				b=-1;
            }
	}
        }
	if(a < fstArLoopCnt){
		        returnVectorOfString.push_back(theSpeeches[a].getSpeaker());
	 scndArLoopCnt = returnVectorOfString.size();
//						returnVectorofString.capacity();
	}
    }
    //this loops through theSpeeches and saves each speaker
    //but only saves them once.

    //Hints:
    //Build up a vector of roles through repeated push_back.
    //This will involve looking at the speaker associated with every speech
    //in the play. If the speaker is not already in the “current” version of
    //of the vector, then push_back. Otherwise, there is nothing to do because
    //the speaker is in the vector already.

    //Note: the list returned by allParts should have no repeated entries
    //and the order does not matter.
    return returnVectorOfString;
}

map<string,int> Play::speakersAndLineCnt(){
    map<string, int> returnMap;
	    	//returnMap.insert(std::pair<string, int>("test",3));
	//	returnMap["test"] = 1;
    for (int i = 0; i < theSpeeches.size(); i++) {
    
	if(returnMap.size() > 0){
		int trackIt = 0;
		for(map<string, int>::iterator it = returnMap.begin(); it!=returnMap.end();){
			if(it->first == theSpeeches[i].getSpeaker()){
				returnMap[theSpeeches[i].getSpeaker()] += theSpeeches[i].getLines().size();
				for(int a = 0; a <trackIt; a++){
					it--;
				}
				trackIt = 0; 
				i++;
			}
			else{
			it++;
			trackIt++;
			}
		}
	}
        returnMap[ theSpeeches[i].getSpeaker()] = theSpeeches[i].getLines().size();
		
	}
    //this loops through theSpeeches and counts how many lines
    //each speaker has, which it saves as a speaker,numLines pair
    return returnMap;
}

int Play::wordFreq(string word){
    int count = 0;
    for (int i = 0; i < theSpeeches.size(); i++) {
        for (int a = 0; a < theSpeeches[i].getLines().size(); a++) {
		for(int b = 0; b < theSpeeches[i].getLines()[a].length(); b++){
			string currentLine = theSpeeches[i].getLines()[a];
//			std::transform(currentLine.begin(), currentLine.end(), currentLine.begin(),[](unsigned char c){ return std::tolower(c); });
			bool FoundWord = false;
			bool misMatch = false;
        	    if ((currentLine[b] == word[0] || std::tolower(currentLine[b]) == std::tolower(word[0])) && (b == 0 || currentLine[b - 1] == ' ')) {
			//try using substring instead of all the code below
			string testStr = currentLine.substr(b, word.length());
			for(int d = 0; d < word.length(); d++){
				if(/*std::tolower(testStr[d]) != std::tolower(word[d]) ||*/ word[d] != std::tolower(testStr[d])){
					misMatch = true;
				}
			}
			if(misMatch){

			}
			else{
				count++;
			}
/*	                for(int c = 0; c < word.length(); c++){
			if(b+c >= currentLine.length()){	
				c = word.length();
				b = currentLine.length();
			}
			else{
				if(word[c] == currentLine[b+c] || std::tolower(currentLine[b+c]) == std::tolower(word[c])){
//move foundword check in here									
					if(c == word.length() - 1){
					FoundWord = true;	
				}
			
				}
				else{
					b += c - 1;
				 	c = word.length();
					
				}
			  }
			}*/
		}
		//if(FoundWord == true){
		//	count++;
		//	FoundWord = false;
		//}
            }
        }
    }
    //this loops through theSpeeches and counts how many times
    //the given word appears in the play
    return count;
}
