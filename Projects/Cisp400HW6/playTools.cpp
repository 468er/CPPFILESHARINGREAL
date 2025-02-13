//don't edit anything in this file
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#define elif else if //just a lazy python thing
using std::string;
using std::vector;
using std::map;
#include "play-1.h"
#include "playTools.h"

vector<string> fileToStringList(string FName){
    /* Returns a list of strings L with the property that
    listOfStrings[k] is line k in the file with name FName.

    PreC: FName is a string that names the file that is to be read.
    It should include the filename's suffix, e.g., for file
    MyFile.txt, FName must be 'MyFile.txt', not 'MyFile'.
    The file must be in the current working directory.
    */
    vector<string> listOfStrings;
    std::ifstream inFile(FName);
    if (!inFile){
        std::cout<<"no file named: "<<FName<<std::endl;
    }
    while (!inFile.eof()){
        string line;
        getline(inFile,line);
        if (short(line[line.length()-1])==13){
            line[line.length()-1]=' ';
        }
        listOfStrings.push_back(line);//.substr(0,line.length()-3));
    }
    return listOfStrings;
}

string stripString(string str){
    /* strips whitespace from given string */
    //this probably could be more efficient
    while((str[0]==' ' || str[0]=='\t') && str.length()>0){
        str=str.substr(1);//cut off first char
    }
    while (str[str.length()-1]==' '){
        str=str.substr(0,str.length()-1); //cut off last char
    }
    return str;
}

string stripPunctuationAndMakeLowerCase(string str){
    string outStr="";
    for (int i=0; i<str.length(); i++){
        int ord=int(str[i]);
        if (ord>=65 && ord<=90){
            outStr+=std::tolower(str[i]);
        } elif (ord>=97 && ord<=122){
            outStr+=str[i];
        }//else ignore
    }
    return outStr;
}

vector<string> splitString(string str, char delimiter){
    /* splits given string at each delimiter and appends that piece to a vector
        if no delimiter given, uses a space
    */
    if (str.length()==0){
        return vector<string>();
    }
    std::stringstream strStream(str);
    //std::cout<<"lenstr"<<str.length()<<std::endl;
    vector<string> splitStr;
    while (strStream){
        string piece;
        getline(strStream,piece,delimiter);
        if (piece.length()>0){
            splitStr.push_back(piece);
            //std::cout<<piece<<std::endl;
        }
    }
    //std::cout<<"|"<<short(str[0])<<"| "<<splitStr.size()<<std::endl<<std::endl;
    return splitStr;
}

vector<Speech> makeListOfSpeeches(string p){
    /*
    Returns a list of Speech objects. Collectively, these objects
    encode "all" the speeches in the play named by p.

    ("all" is in quotes because this simple code does miss some irregularities.
        Example: it includes stage directions.)

    PreC: p is an all-caps string that names a Shakespearean play in
        directory ThePlays. (No suffixes, e.g., 'HAMLET', not 'HAMLET.txt'.)
        The folder ThePlays must be in the current working directory.
    */

    vector<string> listOfStrings = fileToStringList("ThePlays/"+p+".txt");
    int n = listOfStrings.size();
    //std::cout<<n<<std::endl;
    int k = 0;
    // the list of speeches will be built up in listOfSpeeches...
    vector<Speech> listOfSpeeches;
    while (k<n) {
        vector<string> pieces = splitString(listOfStrings[k]);
        //if (pieces.size()>0)
        //    std::cout<<k<<" "<<n<<" "<<pieces[0]<<" "<<listOfStrings[k]<<std::endl;
        if (listOfStrings[k].length()<=1 || pieces.size()==0 || listOfStrings[k][0]==' '){
            // Skip over any line that begins with a blank that is not part of a speech...
            // (example: stage directions, as in the famous "Exit, pursued by a bear"
            //  in _The Winter's Tale_.)
            k+=1;
        } elif (pieces[0] == "ACT" || pieces[0] == "SCENE") {
            //Skip over new act and new scene lines...
            k+=1;
        } else {
            // A speech is starting...
            string theSpeaker = stripString(listOfStrings[k]);

            //std::cout<<"theSpeaker:"<<theSpeaker<<std::endl;
            k+=2;
            //std::cout<<listOfStrings[k]<<listOfStrings[k].length() << " "<< int(listOfStrings[k][0])<<std::endl;
            vector<string> lines;
            while (k<n && ((listOfStrings[k].length()>1 && listOfStrings[k][0]==' ')
                   || splitString(listOfStrings[k]).size()==0)){
                string line = stripString(listOfStrings[k]);
                if (line.length()>0){
                    lines.push_back(line);
                }
                //std::cout<<listOfStrings[k]<<std::endl;
                k+=1;
            }
            listOfSpeeches.push_back(Speech(theSpeaker,lines));
        }
    }
    return listOfSpeeches;
}


vector<Scene> makeListOfScenes(string p){
    /* Returns a list of Scene objects. Collectively, these objects
    encode all the act/scene information in the play named by p.

    If there is more than one piece of locale information given
    (example: ALLS WELL THAT ENDS WELL I.1: "Rousillon. The COUNT's palace"),
    only the portion before the first paragraph will be entered as the
    location.

     PreC: p is an all-caps string that names a Shakespearean play in
        directory ThePlays. (No suffixes, e.g., 'HAMLET', not 'HAMLET.txt'.)
        The folder ThePlays must be in the current working directory.
    */
    vector<string> listOfStrings = fileToStringList("ThePlays/"+p+".txt");
    int n = listOfStrings.size();
    int k = 0;
    int actNumber = 0;
    int sceneNumber=0;
    // The list of scenes will be built up in listOfScenes...
    vector<Scene> listOfScenes;
    while (k<n) {
        vector<string> pieces = splitString(listOfStrings[k]);
        if (pieces.size()==0 || listOfStrings[k][0]==' '){
            // Skip over a blank line or any line that begins with a blank
            k+=1;
        } elif (pieces[0] == "ACT") {
            // A new act is starting
            actNumber +=1;
            sceneNumber = 0;
            k+=1;
        } elif (pieces[0] == "SCENE"){
            // a new scene is starting
            sceneNumber +=1;
            string location="";
            for (int i=2; i<pieces.size(); i++){
                location+=pieces[i];
                location+=" ";
            }
            location=stripString(location);
            listOfScenes.push_back(Scene(actNumber,sceneNumber,location));
            k+=1;
        } else {
            k+=1;
        }
    }
    return listOfScenes;
}
