#include "ShiftArray.hpp"
#include <iostream>

ShiftArray::ShiftArray(char* list[], int length) {
	// Set the length of the shift array and copy the contents of the list
	this->length = length;
	for (int i = 0; i < length; i ++) {
		arr[i] = list[i];
	}
}

INode* ShiftArray::Search(char value) {
	// Search for a character in our string and return a linked list of all occurances
	INode* base = new INode();
	INode* last = base;

	for (int i = 0; i < length; i ++) {
		if (*arr[i] == value) {
			last->i = i;
			last->Next = new INode();
			last = last->Next;
		}
	}

	return base;
}

void ShiftArray::PushForward3(void) {
	// Push the rvalue of the pointers in our array forward by 3
	char temp3 = *Get(length - 3);
	char temp2 = *Get(length - 2);
	char temp1 = *Get(length - 1);

	for (int i = length - 1; i >= 3; i --) {
		*Get(i) = *Get(i - 3);
	}

	*Get(0) = temp3;
	*Get(1) = temp2;
	*Get(2) = temp1;
}

void ShiftArray::PushForward2(void) {
	// Push the rvalues forward by 2
	char temp2 = *Get(length - 2);
	char temp1 = *Get(length - 1);

	for (int i = length - 1; i >= 2; i --) {
		*Get(i) = *Get(i - 2);
	}

	*Get(0) = temp2;
	*Get(1) = temp1;
}

void ShiftArray::PushBackward3(void) {
	// Push rvalues back by 3
	char temp0 = *Get(0);
	char temp1 = *Get(1);
	char temp2 = *Get(2);

	for (int i = 0; i < length - 3; i ++) {
		*Get(i) = *Get(i + 3);
	}

	*Get(length - 3) = temp0;
	*Get(length - 2) = temp1;
	*Get(length - 1) = temp2;
}

void ShiftArray::PushBackward2(void) {
	// Push rvalues back by 2
	char temp0 = *Get(0);
	char temp1 = *Get(1);

	for (int i = 0; i < length - 2; i ++) {
		*Get(i) = *Get(i + 2);
	}

	*Get(length - 2) = temp0;
	*Get(length - 1) = temp1;
}

void ShiftArray::PushPointerForward2(void) {
	// Push the contents of our array forward 2
	char* temp2 = arr[length - 2];
	char* temp1 = arr[length - 1];

	for (int i = length - 1; i >= 2; i --) {
		arr[i] = arr[i - 2];
	}

	arr[0] = temp2;
	arr[1] = temp1;
}

void ShiftArray::PushPointerBackward2(void) {
	// Push the contents of our array backwards 2
	char* temp0 = arr[0];
	char* temp1 = arr[1];

	for (int i = 0; i < length - 2; i ++) {
		arr[i] = arr[i + 2];
	}

	arr[length - 2] = temp0;
	arr[length - 1] = temp1;
}

char* ShiftArray::Get(int num) {
	// Get the value of the array without breaking the program
	if (num < 0 || num >= length) {
		std::cout << "FATAL ERROR: Index out of range\n";
		exit(-1);
	}

	return arr[num];
}

void ShiftArray::Print(void) {
	// Print the rvalues of our array
	for (int i = 0; i < length; i ++) {
		std::cout << *Get(i) << ", ";
	}

	std::cout << "\n";
}
