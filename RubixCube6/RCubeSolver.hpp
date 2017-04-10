#ifndef RCubeSolver_H
#define RCubeSolver_H

#include "RCube.hpp"
#include <map>

class RCubeSolver : public RCube {
public:
  RCubeSolver(void);
  void Shuffle(void);
  void Solve(void);

private:
  // Solving
	void SolveCWhite(char* piece);
	void SolveWhiteCC(char* white, char* color1, char* color2);
	void SolveCC(char* color1, char* color2);

	// Top Solving
	void OrganizeTopCorners(char side, char* piece1, char* piece2);
	void SwitchTopCorners(char* piece);
	void SwitchTopMids(char* piece);
	void OrientAllPieces(void);
	void SolveTop(void);

  // Top Solving algorithms
  void Algorithm1(void);
  void Algorithm1Inverse(void);
  void Algorithm2(void);
  void Algorithm4(void);
  void Algorithm5(void);
  void Algorithm2Inverse(void);

  // Callback functions and mapping them to the solving functions
  typedef void (RCubeSolver::*Callback)(void);
  std::map<bool*, Callback> *MatrixMap;
};

#endif
