//don't edit anything in this file
#ifndef PLAYTOOLS_H
#define PLAYTOOLS_H

vector<string> fileToStringList(string FName);

string stripString(string str);

string stripPunctuationAndMakeLowerCase(string str);

vector<string> splitString(string str, char delimiter=' ');

vector<Speech> makeListOfSpeeches(string p);

vector<Scene> makeListOfScenes(string p);

#endif
