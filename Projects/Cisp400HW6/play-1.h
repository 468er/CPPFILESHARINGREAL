#ifndef PLAY_H_
#define PLAY_H_
#include <iostream>

class Speech{
    public:
        Speech(std::string speaker, std::vector<std::string> lines);
        std::string getSpeaker();
        std::vector<std::string> getLines();
        void print();
    private:
        std::string theSpeaker;
        std::vector<std::string> theLines;
};
class Scene{
    public:
        Scene(int actNum, int sceneNum, std::string loc);
        string toString();
    private:
        int actNumber;
        int sceneNumber;
        std::string location;
};
class Play {
    public:
        std::string theTitle;
        std::vector<Speech> theSpeeches;
        int numLines;
        Play(string title);
        void printAllScenes();
        std::vector<string> allParts();
        std::map<std::string, int> speakersAndLineCnt();
        int wordFreq(std::string word);
    private:
        std::vector<Scene> theScenes;
};
#endif
