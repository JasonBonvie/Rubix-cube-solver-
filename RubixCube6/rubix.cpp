#include <iostream>
#include "RCubeSolver.hpp"

using namespace std;

int main() {
	RCubeSolver* rubixCube = new RCubeSolver();
	rubixCube->Shuffle();
	rubixCube->Print();
	rubixCube->Solve();
	rubixCube->Print();
}
