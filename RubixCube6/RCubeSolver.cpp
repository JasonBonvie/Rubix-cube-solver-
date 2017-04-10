#include "RCubeSolver.hpp"
#include <iostream>

using namespace std;

RCubeSolver::RCubeSolver(void) {
  	// Matrix maps for solving the yellow face in the last step
  	MatrixMap = new std::map<bool*, Callback>();
  	/*
  	0 0 1
  	1   0
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 1, 0, 1, 1, 1, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	1 0 0
  	0   1
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 0, 0, 1, 1, 1, 1, 0
  	}, &RCubeSolver::Algorithm2Inverse));

  	/*
  	0 0 1
  	0   0
  	1 0 0
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 1, 0, 0, 0, 1, 0
  	}, &RCubeSolver::Algorithm4));

  	/*
  	1 0 0
  	1   0
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 0, 0, 0, 1, 1, 1, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	1 0 0
  	1   0
  	0 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 0, 0, 0, 1, 1, 0, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 0 1
  	1   0
  	1 1 0
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 1, 0, 0, 1, 1, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	1 0 0
  	0   0
  	1 0 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 0, 0, 0, 1, 0, 1, 0
  	}, &RCubeSolver::Algorithm5));

  	/*
  	1 0 1
  	0   0
  	1 0 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 0, 1, 0, 1, 0, 1, 0
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 1 0
  	0   0
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 1, 0, 0, 1, 1, 1, 0
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 0 1
  	1   0
  	0 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 1, 0, 1, 1, 0, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	1 0 0
  	0   1
  	1 1 0
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 0, 0, 1, 0, 1, 1, 0
  	}, &RCubeSolver::Algorithm2Inverse));

  	/*
  	1 0 1
  	1   0
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 0, 1, 0, 1, 1, 1, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 0 0
  	0   0
  	1 0 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 0, 0, 1, 0, 1, 0
  	}, &RCubeSolver::Algorithm1));

  	/*
  	0 0 0
  	1   1
  	1 0 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 0, 1, 1, 0, 1, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 0 0
  	0   1
  	0 1 0
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 0, 1, 0, 1, 0, 0
  	}, &RCubeSolver::Algorithm2Inverse));

  	/*
  	1 0 1
  	1   0
  	0 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 0, 1, 0, 1, 1, 0, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	1 1 0
  	0   0
  	0 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 1, 0, 0, 1, 1, 0, 0
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 1 1
  	0   0
  	1 1 0
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 1, 1, 0, 0, 1, 1, 0
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 1 1
  	0   0
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 1, 1, 0, 1, 1, 1, 0
  	}, &RCubeSolver::Algorithm2));

  	/*
  	1 1 0
  	0   0
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 1, 0, 0, 1, 1, 1, 0
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 0 0
  	0   1
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 0, 1, 1, 1, 1, 0
  	}, &RCubeSolver::Algorithm1));

  	/*
  	0 0 0
  	1   0
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 0, 0, 1, 1, 1, 1
  	}, &RCubeSolver::Algorithm1Inverse));

  	/*
  	1 1 1
  	1   1
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 1, 1, 1, 1, 1, 1, 1
  	}, &RCubeSolver::Algorithm1));

  	/*
  	0 1 1
  	1   1
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 1, 1, 1, 1, 1, 1, 1
  	}, &RCubeSolver::Algorithm1));

  	/*
  	0 1 1
  	1   1
  	1 0 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 1, 1, 1, 1, 0, 1, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 1 0
  	1   1
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 1, 0, 1, 1, 1, 1, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	1 1 1
  	0   0
  	1 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 1, 1, 0, 1, 1, 1, 0
  	}, &RCubeSolver::Algorithm2));

  	/*
  	1 1 0
  	1   1
  	0 1 1
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		1, 1, 0, 1, 1, 1, 0, 1
  	}, &RCubeSolver::Algorithm2));

  	/*
  	0 0 0
  	1   1
  	0 0 0
  	*/
  	MatrixMap->insert(make_pair(new bool[8] {
  		0, 0, 0, 1, 0, 0, 0, 1
  	}, &RCubeSolver::Algorithm1));
}

void RCubeSolver::Shuffle(void) {
	// New random seed
	int seed = time(NULL);
	cout << "Seed: " << seed << endl;
	srand(seed);

	// Random number between 20 and 40
	int numberOfTurns = rand() % 20 + 20;
	int rndSide;
	int rndDir;

	for (int i = 0; i < numberOfTurns; i ++) {
		// Random number between 0 and 6
		rndSide = rand() % 6;

		// Random number between -1 and 2
		rndDir = rand() % 3 - 1;

		switch(rndSide) {
		case 0:
			Front(rndDir);
			break;
		case 1:
			Back(rndDir);
			break;
		case 2:
			Left(rndDir);
			break;
		case 3:
			Right(rndDir);
			break;
		case 4:
			Top(rndDir);
			break;
		case 5:
			Bottom(rndDir);
			break;
		}
	}
}

// =============================================================================================================================================
// Top Solving Algorithms ---------------------------------------------------------------------------------------------------------------------------------
// =============================================================================================================================================
void RCubeSolver::Algorithm1(void) {
	//cout << "Algorithm1" << endl;

	Front(-1);
	Right(1);
	Front(1);
	Right(-2);
	Top(1);
	Right(1);
	Top(-1);
	Right(-1);
	Top(1);
	Right(1);
	Top(-1);

	Front(-1);
	Right(1);
	Front(1);
	Right(-1);
	Front(-1);
	Right(1);
	Front(1);
	Right(-1);
	Front(-1);
	Right(1);
	Front(1);
	Right(-1);
}

void RCubeSolver::Algorithm1Inverse(void) {
	//cout << "Algorithm1 Inverse" << endl;

	Front(1);
	Left(-1);
	Front(-1);
	Left(2);
	Top(-1);
	Left(-1);
	Top(1);
	Left(1);
	Top(-1);
	Left(-1);
	Top(1);

	Front(1);
	Left(-1);
	Front(-1);
	Left(1);
	Front(1);
	Left(-1);
	Front(-1);
	Left(1);
	Front(1);
	Left(-1);
	Front(-1);
	Left(1);
}

void RCubeSolver::Algorithm2(void) {
	//cout << "Algorithm2" << endl;

	Front(-1);
	Right(1);
	Front(1);
	Right(-1);
	Top(-1);
	Right(-1);
	Top(1);
	Right(1);
	Top(1);

	Front(-1);
	Right(1);
	Front(1);
	Right(-1);
	Top(-1);
	Right(-1);
	Top(1);
	Right(1);
	Top(1);
}

void RCubeSolver::Algorithm2Inverse(void) {
	//cout << "Algorithm2 Inverse" << endl;

	Front(1);
	Left(-1);
	Front(-1);
	Left(1);
	Top(1);
	Left(1);
	Top(-1);
	Left(-1);
	Top(-1);

	Front(1);
	Left(-1);
	Front(-1);
	Left(1);
	Top(1);
	Left(1);
	Top(-1);
	Left(-1);
	Top(-1);
}

void RCubeSolver::Algorithm4(void) {
	//cout << "Algorithm4" << endl;

	Right(-1);
	Top(-1);
	Right(1);
	Top(-1);
	Right(-1);
	Top(2);
	Right(1);
	Top(2);

	RotateH(1);

	Right(-1);
	Top(2);
	Right(1);
	Top(1);
	Right(-1);
	Top(-1);
	Right(1);
	Top(1);
	Right(-1);
	Top(1);
	Right(1);

	RotateH(-1);
}

void RCubeSolver::Algorithm5(void) {
	//cout << "Algorithm5" << endl;

	Right(-1);
	Top(-1);
	Right(1);
	Top(-1);
	Right(-1);
	Top(2);
	Right(1);
	Top(2);

	RotateH(1);

	Left(1);
	Top(1);
	Left(-1);
	Top(1);
	Left(1);
	Top(-1);
	Left(-1);
	Top(1);
	Left(1);
	Top(2);
	Left(-1);

	RotateH(-1);
}





















// =============================================================================================================================================
// Top Solving ---------------------------------------------------------------------------------------------------------------------------------
// =============================================================================================================================================
void RCubeSolver::OrientAllPieces(void) {
	// Orient the pieces on the yellow face for solving the top
	map<bool*, Callback>::iterator it;
	bool* matrix;
	bool match;

	while(1) {
		for (int i = 0; i < 4; i ++) {
			for (it = MatrixMap->begin(); it != MatrixMap->end(); it++ ) {
				matrix = it->first;

				match = true;
			    for (int i = 0; i < 8; i ++) {
			    	if (matrix[i] == (*yf->Get(i) == 'y')) {
			    		match = false;
			    		break;
			    	}
			    }

			    if (match) {
			    	(this->*it->second)();
			    	break;
			    }
			}

			if (match) break;
			RotateH(1);
		}

		if (!match) break;
	}
}

void RCubeSolver::OrganizeTopCorners(char side, char* piece1, char* piece2) {
	// Set our reference frame
	RotateHUntil(side);

	int location1 = GetLocationOnYellow(piece1);
	int location2 = GetLocationOnYellow(piece2);
	int tempLocation;

	// Make location1 less than location2
	if (location1 > location2) {
		tempLocation = location1;
		location1 = location2;
		location2 = tempLocation;
	}


	if ((location1 == 0 && location2 == 6) || location1 + 2 == location2) {
		// These two pieces are adjacent rotate the top so that they face their correct side
		int avg = 7;
		if (location1 != 0 || location2 != 6) avg = (location1 + location2) / 2;

		Top((avg / 2) - 2);
	}
}

void RCubeSolver::SwitchTopCorners(char* piece) {
	// Switching edge pieces to solve the yellow side
	RotateHUntil(piece[0]);

	if (GetLocationOnYellow(piece) == 6) {
		// Switch these two
		Left(-1);
		Front(1);
		Left(1);
		Front(-1);

		Top(-1);
		Front(-1);
		Top(1);
		Front(1);

		Top(1);
	}
}

void RCubeSolver::SwitchTopMids(char* piece) {
	int location = GetLocationOnYellow(piece);

	if (location == 1) {
		Left(1);
		Top(1);
		Left(-1);
		Top(1);
		Left(1);
		Top(-1);
		Left(-1);
		Top(1);
		Left(1);
		Top(2);
		Left(-1);
		RotateH(1);
	} else if (location == 3) {
		Right(-1);
		Top(-1);
		Right(1);
		Top(-1);
		Right(-1);
		Top(1);
		Right(1);
		Top(-1);
		Right(-1);
		Top(2);
		Right(1);
		RotateH(1);
	} else if (location == 5) {
		RotateH(1);
		Right(-1);
		Top(-1);
		Right(1);
		Top(-1);
		Right(-1);
		Top(1);
		Right(1);
		Top(-1);
		Right(-1);
		Top(2);
		Right(1);
		RotateH(-1);

		SwitchTopMids(piece);
	} else {
		RotateH(1);
	}
}

void RCubeSolver::SolveTop(void) {
	// Holds the basic fomat for solving the yellow face
	OrganizeTopCorners('b', (char*) "ybr", (char*) "ybo");
	OrganizeTopCorners('r', (char*) "yrg", (char*) "ybr");

	SwitchTopCorners((char*) "goy");
	SwitchTopCorners((char*) "oby");
	SwitchTopCorners((char*) "bry");
	SwitchTopCorners((char*) "rgy");

	SwitchTopMids((char*) "yb");
	SwitchTopMids((char*) "yo");
	SwitchTopMids((char*) "yg");
	SwitchTopMids((char*) "yr");

	OrientAllPieces();
}

























// =============================================================================================================================================
// First and Second Row Solving ----------------------------------------------------------------------------------------------------------------
// =============================================================================================================================================
void RCubeSolver::SolveWhiteCC(char* white, char* color1, char* color2) {
	int location[2];
	GetLocation(white, false, location);

	if (location[0] == 'w') {
		// The piece may already be in place
		int tempLocation[2];
		GetLocation(color1, false, tempLocation);
		if (tempLocation[0] == color1[0]) {
			GetLocation(color2, false, tempLocation);
			if (tempLocation[0] == color2[0]) {
				// The piece was already in the correct position
				return;
			}
		}
	}

	int location2[2];
	int location3[2];

	GetLocation(color1, false, location2);
	GetLocation(color2, false, location3);
	int loc;
	if (location[0] == 'w' || location2[0] == 'w' || location3[0] == 'w') {
		if 		(location[0] == 'w') 	loc = location[1];
		else if (location2[0] == 'w') 	loc = location2[1];
		else 							loc = location3[1];

		// The piece is on the white face but not in the correct position, it must be removed from the white face
		int turnRights = loc / 2;
		RotateH(-turnRights);
		Left(1);
		Top(1);
		Left(-1);
		RotateH(turnRights);
	}

	// Rotate cube so that front is on our piece
	RotateHUntil(color1[0]);

	// Make sure white face is not on top
	GetLocation(white, false, location);
	if (location[0] == 'y') { // White face was on top
		// Rotate piece into the proper corner
		int rot = (location[1] / 2) - 2;
		Top(rot);

		Right(-1);
		Top(1);
		Right(1);
		Top(2);
	}

	// The piece is now on the yellow face, white side not up
	GetLocation(color1, false, location2);
	char face = color1[0];
	if (location2[0] == 'y') {
		// This face is useless to us, get the other one
		GetLocation(color2, false, location2);
		face = color2[0];
	}

	Top(GetDistance(face, (char) location2[0], face));

	// Find the orientation
	GetLocation(white, false, location);

	// Put piece into place
	if (location[0] == color1[0]) {
		Right(1);
		Front(-1);
		Right(-1);
		Front(1);
	} else {
		Front(-1);
		Right(1);
		Front(1);
		Right(-1);
	}
}

void RCubeSolver::SolveCWhite(char* piece) {
	int location[2];
	GetLocation(piece, false, location);

	if (location[0] == 'w') {
		// The piece is facing the wrong way on the white surface
		switch (location[1]) {
		case 1:
			Red(1);
			Green(1);
			Red(-1);
			Green(-1);
			break;
		case 3:
			Green(1);
			Orange(1);
			Green(-1);
			Orange(-1);
			break;
		case 5:
			Orange(1);
			Blue(1);
			Orange(-1);
			Blue(-1);
			break;
		case 7:
			Blue(1);
			Red(1);
			Blue(-1);
			Red(-1);
			break;
		}
		GetLocation(piece, false, location);
	} else if (location[0] == 'y') {
		switch (location[1]) {
		case 1:
			Green(-1);
			Orange(1);
			Green(1);
			Orange(-1);
			break;
		case 3:
			Red(-1);
			Green(1);
			Red(1);
			Green(-1);
			break;
		case 5:
			Blue(-1);
			Red(1);
			Blue(1);
			Red(-1);
			break;
		case 7:
			Orange(-1);
			Blue(1);
			Orange(1);
			Blue(-1);
			break;
		}
		GetLocation(piece, false, location);
	}

	if (location[0] != piece[0]) {
		// The piece is not on the correct side to be rotated into place
		int rotateUpDir = (location[1] - 7) / 2 - 1;
		if (rotateUpDir < -2) rotateUpDir += 4;
		else if (rotateUpDir > 2) rotateUpDir -= 4;

		char initialSide = (char) location[0];
		RotateAbsolute(initialSide, rotateUpDir);

		// The piece is now white facing down, we must rotate horizontally until it is on its matching face
		int topRotate = GetDistance(initialSide, initialSide, piece[0]);
		Top(topRotate);

		// Set the initial side back to the rotation that it was currently at
		RotateAbsolute(initialSide, -rotateUpDir);

		// Get the new position for the next step
		GetLocation(piece, false, location);
	}

	// The piece is currently on the correct side, we just need to rotate it so that the white faces up
	RotateAbsolute((char) location[0], (location[1] - 7) / 2 + 1);
}

void RCubeSolver::SolveCC(char* color1, char* color2) {
	int location[2];
	GetLocation(color1, false, location);

	if (location[0] != 'y' && (location[1] == 3 || location[1] == 7)) {
		// The piece may already be in the correct position
		int location2[2];
		GetLocation(color2, false, location);
		if (location[0] == color1[0] && location2[0] == color2[0]) {
			// The piece was in the correct position
			return;
		}

		// The piece was not in the correct position, but it is in a side position, it must be removed

		// Rotate to the proper side
		RotateHUntil(location[0]);

		if (location[1] == 3) {
			// Piece was located on the right hand side, remove it respectively
			Front(1);
			Top(-1);
			Front(-1);

			Right(1);
			Front(-1);
			Right(-1);
			Front(1);
		} else {
			// Piece was located on the left hand side
			Front(-1);
			Top(1);
			Front(1);

			Left(-1);
			Front(1);
			Left(1);
			Front(-1);
		}
	}

	// Piece is located in the top row
	GetLocation(color1, false, location);
	char* color = color1;
	if (location[0] == 'y') {
		// This face is facing up, it is useless to us, get the other one
		GetLocation(color2, false, location);
		color = color2;
	}

	// Get one side matching
	int distance = GetDistance(color[0], (char) location[0], color[0]);
	Top(distance);

	// Offset it by one
	distance = -GetDistance(color[1], (char) color[0], color[1]);
	Top(distance);

	// Set our reference frame
	RotateHUntil(color[0]);

	if (distance == -1) {
		// The piece is on the left
		Right(-1);
		Top(1);
		Right(1);

		Front(-1);
		Right(1);
		Front(1);
		Right(-1);
	} else {
		// The piece is on the right
		Left(1);
		Top(-1);
		Left(-1);

		Front(1);
		Left(-1);
		Front(-1);
		Left(1);
	}
}

void RCubeSolver::Solve(void) {
	// Holdes the basic structure for solving the first two rows
	SolveCWhite((char*) "rw");
	SolveCWhite((char*) "gw");
	SolveCWhite((char*) "ow");
	SolveCWhite((char*) "bw");

	// Random cout seems to solve the heisenbug issue. Hopefully when we print the steps this can be removed
	cout << "";
	SolveWhiteCC((char*) "wrg", (char*) "rwg", (char*) "grw");
	SolveWhiteCC((char*) "wgo", (char*) "gwo", (char*) "ogw");
	SolveWhiteCC((char*) "wob", (char*) "owb", (char*) "bow");
	SolveWhiteCC((char*) "wbr", (char*) "bwr", (char*) "rbw");

	cout << "";
	SolveCC((char*) "rg", (char*) "gr");
	SolveCC((char*) "go", (char*) "og");
	SolveCC((char*) "ob", (char*) "bo");
	SolveCC((char*) "br", (char*) "rb");

	SolveTop();
}
