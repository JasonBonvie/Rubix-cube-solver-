#ifndef RCube_H
#define RCube_H

#include "ShiftArray.hpp"
#include <map>
#include <string>
#include "Output.hpp"

class RCube {
public:
	RCube(void);
	void Print(void);

protected:
	// Horizontal and vertical shift arrays
	ShiftArray* rh0;
	ShiftArray* rh1;
	ShiftArray* rh2;
	ShiftArray* yu0;
	ShiftArray* yu1;
	ShiftArray* yu2;
	ShiftArray* gu0;
	ShiftArray* gu1;
	ShiftArray* gu2;

	// Face shift arrays
	ShiftArray* rf;
	ShiftArray* bf;
	ShiftArray* of;
	ShiftArray* gf;
	ShiftArray* wf;
	ShiftArray* yf;

	// Extraneous variables used for setting. They had to be declared here so that their information wasn't destroyed
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

	// Printing
	void PrintRed(void);
	void PrintBlue(void);
	void PrintGreen(void);
	void PrintWhite(void);
	void PrintYellow(void);
	void PrintOrange(void);

	// Maps for naming
	std::map<ShiftArray*, char> *ShiftToNameAbsolute;
	std::map<ShiftArray*, char> *ShiftToNameRelative;

	// Change reference frame
	void RotateH(int RIGHT);
	void RotateU(int UP);
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
	void GetLocation(char* piece, int (&result)[2]);
	int GetLocationOnYellow(char* piece);
	int GetDistance(char currFace, char face1, char face2);

	// Restart the cube
	virtual void Restart(void);

	// Outputs
	Output* out;
};

#endif
