#include "input.h"

void inputUI::constructPrintVector() {

    vector< vector<char> > con(5, vector<char>(25, ' '));

    printVector = con;

    for (int i=0; i<6; i++)
        printVector[0][2+(4*i)] = colorList[i];
    
    for (int i=0; i<7; i++) {
        for (int j=0; j<5; j++)
            printVector[j][4*i] = '|';
   }

}

void inputUI::updatePrintVector() {
    for (int i=0; i<6; i++) {
        vector<char> face = cubeMap[colorList[i]];

        if (face.empty()) continue;

        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++)
                printVector[2+j][(i+1)+k+(3*i)] = face[k+(j*3)];
        }
    }
}



vector<char> inputUI::readLine() {
    char a;
    char b;
    char c;

    cin >> a;
    cin >> b;
    cin >> c;

    vector<char> out = {a, b, c};


    return out;
}


vector<char> inputUI::concatV(vector<char> a, vector<char> b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}


bool inputUI::isMember(char elem, vector<char> list) {
    for (unsigned int i=0; i<list.size(); i++) {
        if (list[i] == elem) {
            return true;
        }
    }
    return false;
}


void inputUI::printFace(vector<char> face) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++)
            cout << face[(i*j) + j];
        cout << endl;
    }
}


void inputUI::printCube() {
    updatePrintVector();
    for (vector<char> i : printVector) {
        for (char j : i)
            cout << j;
        cout << endl;
    }
    cout << endl;
}


void inputUI::catagorizeFace(vector<char> face) {
    char center = face[4];
    cubeMap[center] = face;
    printCube();
    loop();
}


void inputUI::sanitizeFace(vector<char> face) {
    bool badFace = false;
    if (face.size() != 9)
        badFace = true;

    for (unsigned int i=0; i < face.size(); i++) {
        if (!isMember(face[i], colorList)) {
                badFace = true;
        }
    }

    if (badFace) {
        cout << "Incorrect face format, please input again\n";
        loop();
    } else {
        catagorizeFace(face);
    }
}


void inputUI::loop() {

    bool emptyFlag = false;
    for (int i=0; i<6; i++) {
        char color = colorList[i];
        if (cubeMap[color].empty())
            emptyFlag = true;
    }

    if (!emptyFlag) {
        cout << "All faces have been filled\ntype Y to solve cube\n";
        cout << "type N to continue input\n";
        cout << "or type P to print faces and continue input\n\n";
        char choice;
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 'Y': writeInput(); return; break;
            case 'N': break;
            case 'P': printCube(); break;
            default : 
                cout << "Not valid input\n\n";
                loop();
                break; 
        }
    }
            
    cout << ">" << endl;
    vector<char> first = readLine();

    bool charFlag = false;
    for (int i=0; i<3; i++) {
        if (!isMember(first[i], colorList))
            charFlag = true;
    }

    if (charFlag) {
        cout << "I can't understand that input, can we start again?\n";
        loop();
        return;
    }
    vector<char> second = readLine();
    vector<char> third = readLine();
    cout << endl;
    
    cin.clear();
    cin.ignore(100, '\n');

    vector<char> face = concatV(concatV(first,second), third);

    sanitizeFace(face);
}


void inputUI::writeInput() {
    vector<char> outArray(8, ' ');
    vector<char> bufferV = {};
    vector<int> map = {0,1,2,5,8,7,6,3};
    for (int i=0; i<6; i++) {
        char color = colorList[i];

        for (int j=0; j<8; j++)
            outArray[j] = cubeMap[color][map[j]];

        bufferV = concatV(bufferV, outArray);
        bufferV.push_back('\n');
    }

    char* buffer = &bufferV[0];

    ofstream file("input.txt");
    file.write(buffer, 54);
    file.close();
}


inputUI::inputUI() {
    colorList = {'r', 'g','o','b','y','w'};
    constructPrintVector();
    
    for (int i=0; i<6; i++)
        cubeMap[colorList[i]] = {};
    
    start();
}


void inputUI::start() {
    cout << "\n\n\n";
    cout << "Please input the 6 faces of your cube in any order" << endl;
    cout << "Here are the characters that correspond to each color" << endl;
    cout << "w - white, b - blue, g - green" << endl;
    cout << "r - red, y - yellow, o - orange" << endl;
    cout << "Either input the 9 character face linearly, like so" << endl;
    cout << "\nrgrgrgrgr \n\nor 3x3 like this" << endl;
    cout << "\nrgr\ngrg\nrgr\n\n" << endl;
    loop();
}


int main() {
    inputUI run;
}
