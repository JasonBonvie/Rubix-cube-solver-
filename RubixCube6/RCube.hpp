#ifndef RCube_H
#define RCube_H

#include "ShiftArray.hpp"
//#include "ShiftArrayP.hpp"
#include <map>
#include <string>

class RCube {
public:
	RCube(void);
	void PrintRed(void);
	void PrintBlue(void);
	void PrintGreen(void);
	void PrintWhite(void);
	void PrintYellow(void);
	void PrintOrange(void);
	void Print(void);
	void Shuffle(void);

	// Change reference frame
	void RotateH(int RIGHT);
	void RotateU(int UP);
	void RotateY(int YAW);
	void RotateHUntil(char c);

	// Non reference motion
	void Red(int dir);
	void Blue(int dir);
	void Orange(int dir);
	void Green(int dir);
	void White(int dir);
	void Yellow(int dir);
	void RotateAbsolute(char side, int dir);

	// Reference functions
	void Left(int dir);
	void Right(int dir);
	void Top(int dir);
	void Bottom(int dir);
	void Front(int dir);
	void Back(int dir);

	// Location
	void GetLocation(char* piece, bool relative, int (&result)[2]);
	int GetLocationOnYellow(char* piece);
	int GetDistance(char currFace, char face1, char face2);

	// Solving
	void SolveCWhite(char* piece);
	void SolveWhiteCC(char* white, char* color1, char* color2);
	void SolveCC(char* color1, char* color2);
	void Solve(void);

	// Top Solving
	void OrganizeTopCorners(char side, char* piece1, char* piece2);
	void SwitchTopCorners(char* piece);
	void SwitchTopMids(char* piece);
	void OrientAllPieces(void);
	void SolveTop(void);


private:
	ShiftArray* rh0;
	ShiftArray* rh1;
	ShiftArray* rh2;
	ShiftArray* yu0;
	ShiftArray* yu1;
	ShiftArray* yu2;
	ShiftArray* gu0;
	ShiftArray* gu1;
	ShiftArray* gu2;

	ShiftArray* rf;
	ShiftArray* bf;
	ShiftArray* of;
	ShiftArray* gf;
	ShiftArray* wf;
	ShiftArray* yf;

	// Extraneous variables
	char rhs[3][12];
	char yus[3][12];

	// Temp (Because I'm lazy)
	void (RCube::*temp)(int);
	ShiftArray* tempf;

	// Reference variables
	void (RCube::*left)(int);
	void (RCube::*right)(int);
	void (RCube::*top)(int);
	void (RCube::*bottom)(int);
	void (RCube::*back)(int);
	void (RCube::*front)(int);
	ShiftArray* frontf;
	ShiftArray* backf;
	ShiftArray* leftf;
	ShiftArray* rightf;
	ShiftArray* topf;
	ShiftArray* bottomf;
	char SideArr[3][4] = {{'r', 'b', 'o', 'g'}, {'r', 'y', 'o', 'w'}, {'w', 'g', 'y', 'b'}};

	// Map
	std::map<ShiftArray*, char> *ShiftToNameAbsolute;
	std::map<ShiftArray*, char> *ShiftToNameRelative;

	typedef void (RCube::*Callback)(void);
	std::map<bool*, Callback> *MatrixMap;



	// Top Solving algorithms
	void Algorithm1(void);
	void Algorithm1Inverse(void);
	void Algorithm2(void);
	void Algorithm4(void);
	void Algorithm5(void);
	void Algorithm2Inverse(void);
};

#endif