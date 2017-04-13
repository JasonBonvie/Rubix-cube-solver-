#ifndef Input_H
#define Input_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class InputUI {

    private:
        static map< char, vector<char> > cubeMap;
        vector<char> colorList;
        vector< vector<char> > printVector;

        void constructPrintVector();
        void updatePrintVector();

        vector<char> readLine();
        vector<char> concatV(vector<char>, vector<char>);
        bool isMember(char, vector<char>);
        void sanitizeFace(vector<char>);
        void catagorizeFace(vector<char>);
        void loop();

        void printFace(vector<char>);
        void printCube();
        void writeInput();

        char** rfs;
        char** gfs;
        char** ofs;
        char** bfs;
        char** yfs;
        char** wfs;


    public:
        InputUI(char* rfs[8], char* gfs[8], char* ofs[8], char* bfs[8], char* yfs[8], char* wfs[8]);
        void start();
};

#endif
