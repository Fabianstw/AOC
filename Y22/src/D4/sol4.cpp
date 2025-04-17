//
// Copyright 2025 Fabian Stiewe
//

#include "D4/sol4.h"

#include <iostream>
#include <string>
#include <vector>

#include "utils/utils.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int fullyContained(const vector<string>& lines) {
  int result = 0;

  for (const auto& line : lines) {
    vector<string> elves = split_string(line, ",");
    vector<string> area1 = split_string(elves[0], "-");
    vector<string> area2 = split_string(elves[1], "-");
    if ((stoi(area1[0]) >= stoi(area2[0]) &&
         stoi(area1[1]) <= stoi(area2[1])) ||
        stoi(area2[0]) >= stoi(area1[0]) && stoi(area2[1]) <= stoi(area1[1])) {
      result += 1;
    }
  }

  return result;
}

int overlap(const vector<string>& lines) {
  int result = 0;
  for (const auto& line : lines) {
    vector<string> elves = split_string(line, ",");
    vector<string> area1 = split_string(elves[0], "-");
    vector<string> area2 = split_string(elves[1], "-");

    if (stoi(area1[0]) >= stoi(area2[0]) && stoi(area1[0]) <= stoi(area2[1]) ||
        stoi(area2[0]) >= stoi(area1[0]) && stoi(area2[0]) <= stoi(area1[1])) {
      result += 1;
    }
  }
  return result;
}

void solve4() {
  cout << "Day 4 solutions:" << endl;
  const vector<string> LINES = read_file("D4/inp.txt");
  cout << "Part A: " << fullyContained(LINES) << endl;
  cout << "Part B: " << overlap(LINES) << endl;
}
