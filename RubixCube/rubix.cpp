#include <iostream>
#include "RCubeSolver.hpp"

using namespace std;

int main() {
	RCubeSolver* rubixCube = new RCubeSolver();
	// Shuffle feature was for debug only
	rubixCube->Shuffle();

	// Solve the rubix cube
	rubixCube->Solve();
}
