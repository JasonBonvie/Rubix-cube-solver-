#ifndef INode_H
#define INode_H

struct INode {
	int i;
	struct INode* Next;
	INode(void) { i = -1; Next = nullptr; };
};

#endif