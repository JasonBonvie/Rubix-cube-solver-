#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;


class inputUI {
    
    private:
        map< char, vector<char> > cubeMap;
        vector<char> colorList;

        vector<char> readLine();
        vector<char> concatV(vector<char>, vector<char>); 
        bool isMember(char, vector<char>);
        void sanitizeFace(vector<char>);
        void catagorizeFace(vector<char>);
        void loop();

        void printFace(vector<char>);
        void printCube();
        void writeInput();


    public:
        inputUI();
        void start();
};
