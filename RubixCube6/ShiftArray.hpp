#ifndef ShiftArray_H
#define ShiftArray_H

#include "INode.hpp"

class ShiftArray {
public:
	ShiftArray(char* list[], int length);
	void PushForward3(void);
	void PushBackward3(void);
	void PushForward2(void);
	void PushBackward2(void);
	void PushPointerForward2(void);
	void PushPointerBackward2(void);
	char* Get(int num);
	void Print(void);
	INode* Search(char value);

private:
	char* arr[12];
	int length;
};

#endif
