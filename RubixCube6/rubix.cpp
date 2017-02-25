#include <iostream>
#include "RCube.hpp"

using namespace std;

int main() {
	RCube* rubixCube = new RCube();
	rubixCube->Shuffle();
	rubixCube->Print();
	rubixCube->Solve();
	rubixCube->Print();
}