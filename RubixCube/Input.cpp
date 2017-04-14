#include "Input.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */

#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */

#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define CLEAR "\033[2J"  // clear screen escape code

map< char, vector<char> > InputUI::cubeMap;

vector<char> InputUI::readLine() {
    char a;
    char b;
    char c;

    cin >> a;
    cin >> b;
    cin >> c;

    vector<char> out = {a, b, c};

    return out;
}


vector<char> InputUI::concatV(vector<char> a, vector<char> b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}


bool InputUI::isMember(char elem, vector<char> list) {
    for (unsigned int i=0; i<list.size(); i++) {
        if (list[i] == elem) {
            return true;
        }
    }
    return false;
}


void InputUI::printFace(vector<char> face) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++)
            cout << face[(i*3) + j] << " ";
        cout << endl;
    }
}


void InputUI::printCube() {
    char color;

    vector<char> empty(9, ' ');

    for (int i=0; i<6; i++) {
        color = colorList[i];
        switch(i) {
          case 0:
        cout << BOLDRED<<"Red side"<<" (Yellow side facing perpendicular to your body) ------" << endl;
        break;
          case 1:
        cout << BOLDGREEN <<"Green side"<< "(Yellow side facing perpendicular to your body) ----" << endl;
        break;
          case 2:
        cout << BOLDMAGENTA << "Orange side "<< "(Yellow side facing perpendicular to your body) ---" << endl;
        break;
          case 3:
        cout << BOLDBLUE<<"Blue side" << "(Yellow side facing perpendicular to your body) -----" << endl;
        break;
          case 4:
        cout << BOLDYELLOW<<"Yellow side"<<" (Orange side facing perpendicular to your body) --" << endl;
        break;
          case 5:
        cout << BOLDWHITE<<"White side "<<" (Red side facing perpendicular to your body) ------" << endl;
        break;
        }
        if (cubeMap[color].empty())
            cout << "Empty" << endl << endl << endl;
        else
            printFace(cubeMap[color]);
    }
}


void InputUI::catagorizeFace(vector<char> face) {
    char center = face[4];
    cubeMap[center] = face;
    printCube();
    loop();
}


void InputUI::sanitizeFace(vector<char> face) {
    bool badFace = false;
    if (face.size() != 9)
        badFace = true;

    for (unsigned int i=0; i < face.size(); i++) {
        if (!isMember(face[i], colorList)) {
                badFace = true;
        }
    }

    if (badFace) {
        cout << "Incorrect face format, please input again";
        cin.clear();
        cin.ignore(1000, '\n');
        loop();
    } else {
        catagorizeFace(face);
    }
}


void InputUI::loop() {

    bool emptyFlag = false;
    for (int i=0; i<6; i++) {
        char color = colorList[i];
        if (cubeMap[color].empty())
            emptyFlag = true;
    }

    if (!emptyFlag) {
        cout << "All faces have been filled\ntype Y to proceed to solving\n";
        cout << "type N to continue input\n";
        char choice;
        cin >> choice;
        switch (choice) {
            case 'Y':
              cin.clear();
              cin.ignore(1000, '\n');
              writeInput();
              return;
              break;
            case 'N':
              cin.clear();
              cin.ignore(1000, '\n');
              break;
            default :
              cout << "Not valid input\n\n";
              cin.clear();
              cin.ignore(1000, '\n');
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
        cin.clear();
        cin.ignore(1000, '\n');
        loop();
        return;
    }

    vector<char> second = readLine();

    for (int i=0; i<3; i++) {
        if (!isMember(second[i], colorList))
            charFlag = true;
    }

    if (charFlag) {
        cout << "I can't understand that input, can we start again?\n";
        cin.clear();
        cin.ignore(1000, '\n');
        loop();
        return;
    }

    vector<char> third = readLine();

    for (int i=0; i<3; i++) {
        if (!isMember(third[i], colorList))
            charFlag = true;
    }

    if (charFlag) {
        cout << "I can't understand that input, can we start again?\n";
        cin.clear();
        cin.ignore(1000, '\n');
        loop();
        return;
    }
    cout << endl;

    cin.clear();
    cin.ignore(1000, '\n');

    vector<char> face = concatV(concatV(first,second), third);

    sanitizeFace(face);
}


void InputUI::writeInput() {
    vector<int> map = {0,1,2,5,8,7,6,3};
    for (int i=0; i<6; i++) {
        char color = colorList[i];

        switch(i) {
        case 0:
          for (int j=0; j<8; j++)
            *(rfs[j]) = cubeMap[color][map[j]];
          break;
        case 1:
          for (int j=0; j<8; j++)
            *(gfs[j]) = cubeMap[color][map[j]];
          break;
        case 2:
          for (int j=0; j<8; j++)
            *(ofs[j]) = cubeMap[color][map[j]];
          break;
        case 3:
          for (int j=0; j<8; j++)
            *(bfs[j]) = cubeMap[color][map[j]];
          break;
        case 4:
          for (int j=0; j<8; j++)
            *(yfs[j]) = cubeMap[color][map[j]];
          break;
        case 5:
          for (int j=0; j<8; j++)
            *(wfs[j]) = cubeMap[color][map[j]];
          break;
        }

    }
}


InputUI::InputUI(char* rfs[8], char* gfs[8], char* ofs[8], char* bfs[8], char* yfs[8], char* wfs[8]) {
    colorList = {'r', 'g','o','b','y','w'};
    this->rfs = rfs;
    this->gfs = gfs;
    this->ofs = ofs;
    this->bfs = bfs;
    this->yfs = yfs;
    this->wfs = wfs;

    start();
}


void InputUI::start() {
    cout << "\n\n\n";
    cout << "Please input the 6 faces of your cube in any order" << endl;
    cout << "Here are the characters that correspond to each color" << endl;
    cout << "w - white, b - blue, g - green" << endl;
    cout << "r - red, y - yellow, o - orange" << endl;
    cout << "Either input the 9 character face linearly, like so" << endl;
    cout << "\nrgrgrgrgr \n\nor 3x3 like this" << endl;
    cout << "\nrgr\ngrg\nrgr\n" << endl;

    printCube();
    loop();
}
