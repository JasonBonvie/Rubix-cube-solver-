#include "Output.hpp"
#include <iostream>

OutputNode::OutputNode(void) {
  next = nullptr;
  previous = nullptr;
  dir = 0;
}

void OutputNode::Print(void) {
  if (dir == 2 || dir == -2) {
    cout << color << " 180 degrees" << endl;
  } else if (dir == 1) {
    cout << color << " counter-clockwise" << endl;
  } else if (dir == -1) {
    cout << color << " clockwise" << endl;
  } else {
    cout << "ERROR: Broken output" << endl;
    exit(0);
  }

  cin.ignore();
}

void OutputNode::Add(int dir) {
  this->dir += dir;
  if (this->dir < -2) this->dir += 4;
  if (this->dir > 2) this->dir -= 4;
}

Output::Output(void) {
  first = nullptr;
  last = nullptr;
}

void Output::Add(string color, int dir) {
  if (!first) {
    first = new OutputNode();
    last = first;

    last->color = color;
    last->dir = dir;
  } else {
    //if (color != last->color) {
      last->next = new OutputNode();
      last = last->next;

      last->color = color;
      last->dir = dir;
    /*} else {
      last->Add(dir);
      if (last->dir == 0) {
        RemoveLast();
      }
    }*/
  }

  if (liveAdd) {
    if (dir == 2 || dir == -2) {
      cout << color << " 180 degrees" << endl;
    } else if (dir == 1) {
      cout << color << " counter-clockwise" << endl;
    } else if (dir == -1) {
      cout << color << " clockwise" << endl;
    } else {
      cout << "ERROR: Broken output" << endl;
      exit(0);
    }

    cin.ignore();
  }
}

void Output::RemoveLast(void) {
  if (last) {
    last = last->previous;
    if (!last) {
      first = nullptr;
    }
  }
}
