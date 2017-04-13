#ifndef Output_H
#define Output_H

#include <string>

using namespace std;

class OutputNode {
public:
  string color;
  int dir;

  void Print(void);

  OutputNode* next;
  OutputNode* previous;

  OutputNode(void);

  void Add(int dir);
};

class Output {
public:
  bool liveAdd;
  OutputNode* first;
  OutputNode* last;

  void Add(string color, int dir);
  void RemoveLast(void);

  Output(void);
};

#endif
