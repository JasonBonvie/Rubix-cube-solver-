#include "Output.hpp"
#include <iostream>

#define RESET   "\033[0m"

#define BOLDRED     "\033[7m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDORANGE  "\033[1m\033[31m"

#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define CLEAR "\033[2J"  // clear screen escape code

OutputNode::OutputNode(void) {
  next = nullptr;
  previous = nullptr;
  dir = 0;
}

void OutputNode::Print(void) {

  string font;
  switch (color.at(0)) {
    case 'R':
      font = BOLDRED;
      break;
    case 'G':
      font = BOLDGREEN;
      break;
    case 'O':
      font = BOLDORANGE;
      break;
    case 'B':
      font = BOLDCYAN;
      break;
    case 'Y':
      font = BOLDYELLOW;
      break;
    case 'W':
      font = BOLDWHITE;
      break;
  }

  if (dir == 2 || dir == -2) {
    cout << font << color << " 180 degrees" << RESET << endl;
  } else if (dir == 1) {
    cout << font << color << " counter-clockwise" << RESET << endl;
  } else if (dir == -1) {
    cout << font << color << " clockwise" << RESET << endl;
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
  liveAdd = false;
}

void Output::Add(string color, int dir) {
  if (!first) {
    first = new OutputNode();
    last = first;

    last->color = color;
    last->dir = dir;
  } else {
    if (color != last->color) {
      last->next = new OutputNode();
      last->next->previous = last;
      last = last->next;

      last->color = color;
      last->dir = dir;
    } else {
      last->Add(dir);
      if (last->dir == 0) {
        RemoveLast();
      }
    }
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
    if (last) last->next = nullptr;
    else {
      first = nullptr;
    }
  }
}
