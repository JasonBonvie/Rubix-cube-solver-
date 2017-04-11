#include "RCube.hpp"
#include "INode.hpp"
#include <iostream>
#include <fstream>

using namespace std;

RCube::RCube(void) {
	// Create the rubix cube
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 4; j ++) {
			int k = j * 3;
			switch(j) {
				case 0:
					rhs[i][k] = rhs[i][k+1] = rhs[i][k+2] = 'r';
					yus[i][k] = yus[i][k+1] = yus[i][k+2] = 'y';
					break;
				case 1:
					rhs[i][k] = rhs[i][k+1] = rhs[i][k+2] = 'g';
					yus[i][k] = yus[i][k+1] = yus[i][k+2] = 'r';
					break;
				case 2:
					rhs[i][k] = rhs[i][k+1] = rhs[i][k+2] = 'o';
					yus[i][k] = yus[i][k+1] = yus[i][k+2] = 'w';
					break;
				case 3:
					rhs[i][k] = rhs[i][k+1] = rhs[i][k+2] = 'b';
					yus[i][k] = yus[i][k+1] = yus[i][k+2] = 'o';
					break;

			}
		}
	}

	char* rh[3][12];
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 12; j ++) {
			rh[i][j] = &rhs[i][j];
		}
	}

	char* yu[3][12] = {
		{&yus[0][0], &yus[0][1], &yus[0][2], rh[2][8], rh[1][8], rh[0][8], &yus[0][6], &yus[0][7], &yus[0][8], rh[0][0], rh[1][0], rh[2][0]},
		{&yus[1][0], &yus[1][1], &yus[1][2], rh[2][7], rh[1][7], rh[0][7], &yus[1][6], &yus[1][7], &yus[1][8], rh[0][1], rh[1][1], rh[2][1]},
		{&yus[2][0], &yus[2][1], &yus[2][2], rh[2][6], rh[1][6], rh[0][6], &yus[2][6], &yus[2][7], &yus[2][8], rh[0][2], rh[1][2], rh[2][2]}
	};

	char* gu[3][12] = {
		{rh[0][3], rh[1][3], rh[2][3], yu[2][0], yu[1][0], yu[0][0], rh[2][11], rh[1][11], rh[0][11], yu[0][8], yu[1][8], yu[2][8]},
		{rh[0][4], rh[1][4], rh[2][4], yu[2][1], yu[1][1], yu[0][1], rh[2][10], rh[1][10], rh[0][10], yu[0][7], yu[1][7], yu[2][7]},
		{rh[0][5], rh[1][5], rh[2][5], yu[2][2], yu[1][2], yu[0][2], rh[2][9],  rh[1][9],  rh[0][9],  yu[0][6], yu[1][6], yu[2][6]}
	};

	// Row based shift array
	rh0 = new ShiftArray(rh[0], 12);
	rh1 = new ShiftArray(rh[1], 12);
	rh2 = new ShiftArray(rh[2], 12);

	yu0 = new ShiftArray(yu[0], 12);
	yu1 = new ShiftArray(yu[1], 12);
	yu2 = new ShiftArray(yu[2], 12);

	gu0 = new ShiftArray(gu[0], 12);
	gu1 = new ShiftArray(gu[1], 12);
	gu2 = new ShiftArray(gu[2], 12);

	// Faces (top left corner is 0, goes clockwise, center not included)
	char* rfs[8] = {rh[2][0], rh[2][1], rh[2][2], rh[1][2], rh[0][2], rh[0][1], rh[0][0], rh[1][0]};
	char* gfs[8] = {rh[2][3], rh[2][4], rh[2][5], rh[1][5], rh[0][5], rh[0][4], rh[0][3], rh[1][3]};

	char* ofs[8] = {rh[2][6], rh[2][7],  rh[2][8],  rh[1][8],  rh[0][8],  rh[0][7],  rh[0][6], rh[1][6]};
	char* bfs[8] = {rh[2][9], rh[2][10], rh[2][11], rh[1][11], rh[0][11], rh[0][10], rh[0][9], rh[1][9]};

	char* yfs[8] = {yu[0][2], yu[1][2], yu[2][2], yu[2][1], yu[2][0], yu[1][0], yu[0][0], yu[0][1]};
	char* wfs[8] = {yu[0][8], yu[1][8], yu[2][8], yu[2][7], yu[2][6], yu[1][6], yu[0][6], yu[0][7]};


	// Enter the user input into the arrays here
	// Fill in Red Face Source (rfs) using user input and the rest of the arrays will be updated with it
	// Do the same for the rest of the Faces
	// Remember that the faces are single dimensional arrays that loop around the center of the face like so:
	// 0 1 2
	// 7   3
	// 6 5 4

	cout << "Please enter the input for the cube into input.txt follow the format in template.txt or for more information read instructions.txt" << endl;
	cin.ignore();

	string contents;
	string line;
	int j = 0;
	ifstream myfile("input.txt");

	if (myfile.is_open()) {
    while (getline(myfile, line)) {
      for (int i = 0; i < line.length(); i ++) {
				switch(j) {
					case 0:
						*rfs[i] = line.at(i);
						break;
					case 1:
						*gfs[i] = line.at(i);
						break;
					case 2:
						*ofs[i] = line.at(i);
						break;
					case 3:
						*bfs[i] = line.at(i);
						break;
					case 4:
						*yfs[i] = line.at(i);
						break;
					case 5:
						*wfs[i] = line.at(i);
						break;
				}
			}
			j ++;
    }
    myfile.close();
  } else {
    cout << "Unable to open file\n";
    exit(0);
  }

	// Face based arrays
	rf = new ShiftArray(rfs, 8);
	bf = new ShiftArray(bfs, 8);
	of = new ShiftArray(ofs, 8);
	gf = new ShiftArray(gfs, 8);
	wf = new ShiftArray(wfs, 8);
	yf = new ShiftArray(yfs, 8);
	frontf = rf;
	rightf = gf;
	backf = of;
	leftf = bf;
	topf = yf;
	bottomf = wf;

	// This was for testing only
	/**rf->Get(0) = 'k';
	*gf->Get(0) = 'l';
	*of->Get(0) = 'm';
	*bf->Get(0) = 'n';
	*yf->Get(0) = 'i';
	*wf->Get(0) = 'j';*/

	// Set the relative turning functions
	left = &RCube::Blue;
	right = &RCube::Green;
	top = &RCube::Yellow;
	bottom = &RCube::White;
	front = &RCube::Red;
	back = &RCube::Orange;

	// Set naming conventions for variables
	ShiftToNameAbsolute = new map<ShiftArray*, char>();
	ShiftToNameAbsolute->insert(make_pair(rf, 'r'));
	ShiftToNameAbsolute->insert(make_pair(bf, 'b'));
	ShiftToNameAbsolute->insert(make_pair(of, 'o'));
	ShiftToNameAbsolute->insert(make_pair(gf, 'g'));
	ShiftToNameAbsolute->insert(make_pair(wf, 'w'));
	ShiftToNameAbsolute->insert(make_pair(yf, 'y'));

	ShiftToNameRelative = new map<ShiftArray*, char>();
	ShiftToNameRelative->insert(make_pair(frontf, 'f'));
	ShiftToNameRelative->insert(make_pair(rightf, 'r'));
	ShiftToNameRelative->insert(make_pair(backf, 'b'));
	ShiftToNameRelative->insert(make_pair(leftf, 'l'));
	ShiftToNameRelative->insert(make_pair(topf, 't'));
	ShiftToNameRelative->insert(make_pair(bottomf, 'b'));
}










































// =============================================================================================================================================
// Convenience functions -----------------------------------------------------------------------------------------------------------------------
// =============================================================================================================================================
void RCube::RotateHUntil(char c) {
	while((*ShiftToNameAbsolute)[frontf] != c) RotateH(1);
}

int RCube::GetLocation(char* piece, bool relative, int (&result)[2]) {

	result[0] = -1; result[1] = -1;
	map<ShiftArray*, char>* ShiftToName;
	if (relative) ShiftToName = ShiftToNameRelative;
	else ShiftToName = ShiftToNameAbsolute;

	for (int i = 0; i < 6; i ++) {
		if (result[0] == -1) {

			INode* base = frontf->Search(piece[0]);

			if (piece[2] == '\0') {
				for (; base->Next != nullptr; base = base->Next) {
					switch(base->i) {
					case 1:
						if (*(topf->Get(5)) == piece[1]) {
								result[0] = (*ShiftToName)[frontf]; result[1] = base->i;
							}
						break;
					case 3:
						if (*(rightf->Get(7)) == piece[1]) {
								result[0] = (*ShiftToName)[frontf]; result[1] = base->i;
							}
						break;
					case 5:
						if (*(bottomf->Get(1)) == piece[1]) {
								result[0] = (*ShiftToName)[frontf]; result[1] = base->i;
							}
						break;
					case 7:
						if (*(leftf->Get(3)) == piece[1]) {
								result[0] = (*ShiftToName)[frontf]; result[1] = base->i;
							}
						break;
					}
				}
			} else {
				for (; base->Next != nullptr; base = base->Next) {
					switch(base->i) {
					case 0:
						if ((*(leftf->Get(2)) == piece[1] || *(leftf->Get(2)) == piece[2]) &&
							(*(topf->Get(6)) == piece[1] || *(topf->Get(6)) == piece[2])) {
								result[0] = (*ShiftToName)[frontf]; result[1] = base->i;
							}
						break;
					case 2:
						if ((*(rightf->Get(0)) == piece[1] || *(rightf->Get(0)) == piece[2]) &&
							(*(topf->Get(4)) == piece[1] || *(topf->Get(4)) == piece[2])) {
								result[0] = (*ShiftToName)[frontf]; result[1] = base->i;
							}
						break;
					case 4:
						if ((*(rightf->Get(6)) == piece[1] || *(rightf->Get(6)) == piece[2]) &&
							(*(bottomf->Get(2)) == piece[1] || *(bottomf->Get(2)) == piece[2])) {
								result[0] = (*ShiftToName)[frontf]; result[1] = base->i;
							}
						break;
					case 6:
						if ((*(leftf->Get(4)) == piece[1] || *(leftf->Get(4)) == piece[2]) &&
							(*(bottomf->Get(0)) == piece[1] || *(bottomf->Get(0)) == piece[2])) {
								result[0] = (*ShiftToName)[frontf]; result[1] = base->i;
							}
						break;
					}
				}
			}
		}

		if (i < 3) RotateH(-1);
		else if (i == 3) { RotateH(-1); RotateU(-1); }
		else if (i == 4) RotateU(2);
	}
	RotateU(-1);

	if (result[0] == -1) {
		cout << "Sorry, the piece could not be found: " << piece[0] << " " << piece[1] << " " << piece[2] << endl;
		return 0;
	} else {
		//cout << (char) result[0] << " " << result[1] << endl;
		return 1;
	}
}

int RCube::GetLocationOnYellow(char* piece) {
	// Gets the location of a given piece exclusively on the yellow face
	if (piece[2] == '\0') {
		char tempPiece[3];
		tempPiece[0] = piece[0];
		tempPiece[1] = piece[1];
		tempPiece[2] = '\0';

		int location[2];

		for (int i = 0; i < 2; i ++) {

			GetLocation(tempPiece, false, location);
			if (location[0] == 'y') return location[1];

			// Rotate the front color
			char tempChar = tempPiece[0];
			tempPiece[0] = tempPiece[1];
			tempPiece[1] = tempChar;
		}
	} else {
		char tempPiece[4];
		tempPiece[0] = piece[0];
		tempPiece[1] = piece[1];
		tempPiece[2] = piece[2];
		tempPiece[3] = '\0';

		int location[2];

		for (int i = 0; i < 3; i ++) {

			GetLocation(tempPiece, false, location);
			if (location[0] == 'y') return location[1];

			// Rotate the front color
			char tempChar = tempPiece[0];
			tempPiece[0] = tempPiece[1];
			tempPiece[1] = tempPiece[2];
			tempPiece[2] = tempChar;
		}
	}

	return -1;
}

void RCube::RotateAbsolute(char side, int dir) {
	switch (side) {
	case 'r':
		Red(dir);
		break;
	case 'b':
		Blue(dir);
		break;
	case 'o':
		Orange(dir);
		break;
	case 'g':
		Green(dir);
		break;
	case 'w':
		White(dir);
		break;
	case 'y':
		Yellow(dir);
		break;
	}
}

int RCube::GetDistance(char currFace, char face1, char face2) {
	int arrNum = 0;
	int face1Num = -1, face2Num = -1;
	bool currFaceIncluded = false;

	for (; arrNum < 3; arrNum ++) {
		for (int i = 0; i < 4; i ++) {
			if (SideArr[arrNum][i] == face1) face1Num = i;
			else if (SideArr[arrNum][i] == face2) face2Num = i;

			if (SideArr[arrNum][i] == currFace) currFaceIncluded = true;
		}

		if (face1Num != -1 && face2Num != -1) break;
		else {
			face1Num = -1;
			face2Num = -1;
			currFaceIncluded = false;
		}
	}

	int dir = face1Num - face2Num;

	if (dir < -2) dir += 4;
	else if (dir > 2) dir -= 4;

	if (!currFaceIncluded && (currFace == 'o' || currFace == 'y' || currFace == 'g')) dir = -dir;

	return dir;
}


















// =============================================================================================================================================
// Printing ------------------------------------------------------------------------------------------------------------------------------------
// =============================================================================================================================================
void RCube::Print(void) {
	PrintRed();
	PrintGreen();
	PrintOrange();
	PrintBlue();
	PrintYellow();
	PrintWhite();
}

// Prints this colored side of the face 0, 0 being bottom left corner (white being top / red being front / blue being right)
void RCube::PrintRed(void) {
	cout << "Red";
	if (rf == frontf) cout << " (front)";
	else if (rf == topf) cout << " (top)";
	else if (rf == rightf) cout << " (right)";
	cout << endl;
	cout << *rf->Get(0) << " " << *rf->Get(1) << " " << *rf->Get(2) << "\n";
	cout << *rf->Get(7) << " r " << *rf->Get(3) << "\n";
	cout << *rf->Get(6) << " " << *rf->Get(5) << " " << *rf->Get(4) << "\n";
}

void RCube::PrintBlue(void) {
	cout << "Blue";
	if (bf == frontf) cout << " (front)";
	else if (bf == topf) cout << " (top)";
	else if (bf == rightf) cout << " (right)";
	cout << endl;
	cout << *bf->Get(0) << " " << *bf->Get(1) << " " << *bf->Get(2) << "\n";
	cout << *bf->Get(7) << " b " << *bf->Get(3) << "\n";
	cout << *bf->Get(6) << " " << *bf->Get(5) << " " << *bf->Get(4) << "\n";
}

void RCube::PrintOrange(void) {
	cout << "Orange";
	if (of == frontf) cout << " (front)";
	else if (of == topf) cout << " (top)";
	else if (of == rightf) cout << " (right)";
	cout << endl;
	cout << *of->Get(0) << " " << *of->Get(1) << " " << *of->Get(2) << "\n";
	cout << *of->Get(7) << " o " << *of->Get(3) << "\n";
	cout << *of->Get(6) << " " << *of->Get(5) << " " << *of->Get(4) << "\n";
}

void RCube::PrintGreen(void) {
	cout << "Green";
	if (gf == frontf) cout << " (front)";
	else if (gf == topf) cout << " (top)";
	else if (gf == rightf) cout << " (right)";
	cout << endl;
	cout << *gf->Get(0) << " " << *gf->Get(1) << " " << *gf->Get(2) << "\n";
	cout << *gf->Get(7) << " g " << *gf->Get(3) << "\n";
	cout << *gf->Get(6) << " " << *gf->Get(5) << " " << *gf->Get(4) << "\n";
}

void RCube::PrintWhite(void) {
	cout << "White";
	if (wf == frontf) cout << " (front)";
	else if (wf == topf) cout << " (top)";
	else if (wf == rightf) cout << " (right)";
	cout << endl;
	cout << *wf->Get(0) << " " << *wf->Get(1) << " " << *wf->Get(2) << "\n";
	cout << *wf->Get(7) << " w " << *wf->Get(3) << "\n";
	cout << *wf->Get(6) << " " << *wf->Get(5) << " " << *wf->Get(4) << "\n";
}

void RCube::PrintYellow(void) {
	cout << "Yellow";
	if (yf == frontf) cout << " (front)";
	else if (yf == topf) cout << " (top)";
	else if (yf == rightf) cout << " (right)";
	cout << endl;
	cout << *yf->Get(0) << " " << *yf->Get(1) << " " << *yf->Get(2) << "\n";
	cout << *yf->Get(7) << " y " << *yf->Get(3) << "\n";
	cout << *yf->Get(6) << " " << *yf->Get(5) << " " << *yf->Get(4) << "\n";
}


















// =============================================================================================================================================
// Wrappers for relative rotating --------------------------------------------------------------------------------------------------------------
// =============================================================================================================================================
void RCube::Left(int dir) {
	(this->*left)(dir);
}

void RCube::Right(int dir) {
	(this->*right)(dir);
}

void RCube::Top(int dir) {
	(this->*top)(dir);
}

void RCube::Bottom(int dir) {
	(this->*bottom)(dir);
}

void RCube::Front(int dir) {
	(this->*front)(dir);
}

void RCube::Back(int dir) {
	(this->*back)(dir);
}















// =============================================================================================================================================
// Full Cube rotations -------------------------------------------------------------------------------------------------------------------------
// =============================================================================================================================================
void RCube::RotateH(int RIGHT) {
	if (RIGHT > 0) {
		for (int i = 0; i < RIGHT; i ++) {
			temp = front;	tempf = frontf;
			front = left;	frontf = leftf;
			left = back;	leftf = backf;
			back = right;	backf = rightf;
			right = temp;	rightf = tempf;

			bottomf->PushPointerForward2();
			topf->PushPointerBackward2();
		}
	} else {
		for (int i = 0; i < -RIGHT; i ++) {
			temp = front;	tempf = frontf;
			front = right;	frontf = rightf;
			right = back;	rightf = backf;
			back = left;	backf = leftf;
			left = temp; 	leftf = tempf;

			bottomf->PushPointerBackward2();
			topf->PushPointerForward2();
		}
	}
}

void RCube::RotateU(int UP) {
	if (UP > 0) {
		for (int i = 0; i < UP; i ++) {
			temp = front;	tempf = frontf;
			front = top;	frontf = topf;
			top = back;		topf = backf;
			back = bottom;	backf = bottomf;
			bottom = temp;	bottomf = tempf;

			leftf->PushPointerForward2();
			rightf->PushPointerBackward2();
			topf->PushPointerForward2();
			topf->PushPointerForward2();
			backf->PushPointerForward2();
			backf->PushPointerForward2();
		}
	} else {
		for (int i = 0; i < -UP; i ++) {
			temp = front;	tempf = frontf;
			front = bottom;	frontf = bottomf;
			bottom = back;	bottomf = backf;
			back = top;		backf = topf;
			top = temp;		topf = tempf;

			leftf->PushPointerBackward2();
			rightf->PushPointerForward2();
			backf->PushPointerBackward2();
			backf->PushPointerBackward2();
			bottomf->PushPointerForward2();
			bottomf->PushPointerForward2();
		}
	}
}



















// =============================================================================================================================================
// Absolute rotations --------------------------------------------------------------------------------------------------------------------------
// =============================================================================================================================================
void RCube::Red(int dir) {
	if (dir == 0) return;

	if (dir > 0) {
		cout << "Red face counterclockwise " << dir << " time(s)"<< endl;
		for (int i = 0; i < dir; i ++)  {
			gu0->PushForward3();
			rf->PushBackward2();
		}
	} else {
		cout << "Red face clockwise " << -dir << " time(s)"<< endl;
		for (int i = 0; i < -dir; i ++) {
			gu0->PushBackward3();
			rf->PushForward2();
		}
	}
}

void RCube::Green(int dir) {
	if (dir == 0) return;

	if (dir > 0) {
		cout << "Green face counterclockwise " << dir << " time(s)"<< endl;
		for (int i = 0; i < dir; i ++)  {
			yu2->PushBackward3();
			gf->PushBackward2();
		}
	} else {
		cout << "Green face clockwise " << -dir << " time(s)"<< endl;
		for (int i = 0; i < -dir; i ++) {
			yu2->PushForward3();
			gf->PushForward2();
		}
	}
}

void RCube::Orange(int dir) {
	if (dir == 0) return;

	if (dir > 0) {
		cout << "Orange face counterclockwise " << dir << " time(s)"<< endl;
		for (int i = 0; i < dir; i ++)  {
			gu2->PushBackward3();
			of->PushBackward2();
		}
	} else {
		cout << "Orange face clockwise " << -dir << " time(s)"<< endl;
		for (int i = 0; i < -dir; i ++) {
			gu2->PushForward3();
			of->PushForward2();
		}
	}
}

void RCube::Blue(int dir) {
	if (dir == 0) return;

	if (dir > 0) {
		cout << "Blue face counterclockwise " << dir << " time(s)"<< endl;
		for (int i = 0; i < dir; i ++)  {
			yu0->PushForward3();
			bf->PushBackward2();
		}
	} else {
		cout << "Blue face clockwise " << -dir << " time(s)"<< endl;
		for (int i = 0; i < -dir; i ++) {
			yu0->PushBackward3();
			bf->PushForward2();
		}
	}
}

void RCube::Yellow(int dir) {
	if (dir == 0) return;

	if (dir > 0) {
		cout << "Yellow face counterclockwise " << dir << " time(s)"<< endl;
		for (int i = 0; i < dir; i ++)  {
			rh2->PushForward3();
			yf->PushBackward2();
		}
	} else {
		cout << "Yellow face clockwise " << -dir << " time(s)"<< endl;
		for (int i = 0; i < -dir; i ++) {
			rh2->PushBackward3();
			yf->PushForward2();
		}
	}
}

void RCube::White(int dir) {
	if (dir == 0) return;

	if (dir > 0) {
		cout << "White face counterclockwise " << dir << " time(s)"<< endl;
		for (int i = 0; i < dir; i ++)  {
			rh0->PushBackward3();
			wf->PushBackward2();
		}
	} else {
		cout << "White face clockwise " << -dir << " time(s)"<< endl;
		for (int i = 0; i < -dir; i ++) {
			rh0->PushForward3();
			wf->PushForward2();
		}
	}
}
