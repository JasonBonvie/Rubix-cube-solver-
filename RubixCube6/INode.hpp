#ifndef INode_H
#define INode_H

// A simple node for a linked list of integers
struct INode {
	int i;
	struct INode* Next;
	INode(void) { i = -1; Next = nullptr; };
};

#endif
