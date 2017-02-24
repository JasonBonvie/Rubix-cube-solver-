#include "structures.h"

//main function for testing.
int main() {
    Cube ayy;
    ayy.printCube();
    ayy.D();
    ayy.printCube();
    ayy.L();
    ayy.printCube();
    ayy.R();
    ayy.printCube();
    return 0;
};


// Node Functions
Node::Node() {
    colorDat['U'] = 'N';
    colorDat['D'] = 'N';
    colorDat['L'] = 'N';
    colorDat['R'] = 'N';
    colorDat['F'] = 'N';
    colorDat['B'] = 'N';
}

std::map<char, char> Node::getColors() {
    return colorDat;
}

void Node::setColors(std::map<char, char> cmap) {
    colorDat = cmap;
}

void Node::LRClock() {
    std::map <char, char> out;
    out = colorDat;
    out['U'] = colorDat['B'];
    out['F'] = colorDat['U'];
    out['D'] = colorDat['F'];
    out['B'] = colorDat['D'];
    colorDat = out;
}

void Node::UDClock() {
    std::map <char, char> out;
    out = colorDat;
    out['F'] = colorDat['R'];
    out['L'] = colorDat['F'];
    out['B'] = colorDat['L'];
    out['R'] = colorDat['B'];
    colorDat = out;
}

void Node::FBClock() {
    std::map <char, char> out;
    out = colorDat;
    out['D'] = colorDat['R'];
    out['L'] = colorDat['D'];
    out['U'] = colorDat['L'];
    out['R'] = colorDat['U'];
    colorDat = out;
}


    /*

     N - NULL
     w - U
     r - R
     o - L
     y - D
     g - F
     b - B
     */

// Cube functions
Cube::Cube() {
    populate();
}

void Cube::populate() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cubeArr[i][j][0].colorDat['L'] = 'o';
            cubeArr[i][j][2].colorDat['R'] = 'r';
            cubeArr[0][i][j].colorDat['F'] = 'g';
            cubeArr[2][i][j].colorDat['B'] = 'b';
            cubeArr[i][0][j].colorDat['U'] = 'w';
            cubeArr[i][2][j].colorDat['D'] = 'y';
        }
    }
}

void Cube::L() {
    LR(0);
}

void Cube::R() {
    LR(2);
}

void Cube::LR(int index) {
    std::map <char, char> colArr[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cubeArr[i][j][index].LRClock();
            colArr[i][j] = cubeArr[i][j][index].getColors();
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cubeArr[i][j][index].setColors(colArr[2-j][i]);
        }
    }
}

void Cube::F() {
    FB(0);
}

void Cube::B() {
    FB(2);
}

void Cube::FB(int index) {
    std::map <char, char> colArr[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cubeArr[index][i][j].FBClock();
            colArr[i][j] = cubeArr[index][i][j].getColors();
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cubeArr[index][i][j].setColors(colArr[2-j][i]);
        }
    }
}

void Cube::U() {
    UD(0);
}

void Cube::D() {
    UD(2);
}

void Cube::UD(int index) {
    std::map <char, char> colArr[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cubeArr[i][index][j].UDClock();
            colArr[i][j] = cubeArr[i][index][j].getColors();
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cubeArr[i][index][j].setColors(colArr[j][2-i]);
        }
    }
}

std::map <char, charArray> Cube::getCube() {
    std::map <char, charArray> out;
    charArray base(3, std::vector<char> (3, '0'));
    out['U'] = base;
    out['D'] = base;
    out['F'] = base;
    out['B'] = base;
    out['L'] = base;
    out['R'] = base; 
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            out['U'][i][j] = cubeArr[i][0][j].colorDat['U'];
            out['D'][i][j] = cubeArr[i][2][j].colorDat['D'];
            out['L'][i][j] = cubeArr[i][j][0].colorDat['L'];
            out['R'][i][j] = cubeArr[i][j][2].colorDat['R'];
            out['F'][i][j] = cubeArr[0][i][j].colorDat['F'];
            out['B'][i][j] = cubeArr[2][i][j].colorDat['B'];
            }
    }
    return out;
}

void Cube::printCube() {
    std::map<char, charArray> cube = getCube();
    char keys[6] = {'U','D','L','R','F','B'}; 
    charArray face;
    std::cout << "------\n";
    for (int i=0; i<6; i++) {
        face = cube[keys[i]];
        std::cout << std::endl << keys[i];
        for (int j=0; j<3; j++) {
            std::cout << '\n';
            for (int k=0; k<3; k++) {
                std::cout << face[j][k];
            }
        }
    }
    std::cout << '\n';
}
