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

int fully_contained(const vector<string>& lines) {
  int result = 0;

  for (const auto& line : lines) {
    vector<string> elves = split_string(line, ",");
    vector<string> area_1 = split_string(elves[0], "-");
    vector<string> area_2 = split_string(elves[1], "-");
    if ((stoi(area_1[0]) >= stoi(area_2[0]) &&
         stoi(area_1[1]) <= stoi(area_2[1])) ||
        stoi(area_2[0]) >= stoi(area_1[0]) &&
            stoi(area_2[1]) <= stoi(area_1[1])) {
      result += 1;
    }
  }

  return result;
}

int overlap(const vector<string>& lines) {
  int result = 0;
  for (const auto& line : lines) {
    vector<string> elves = split_string(line, ",");
    vector<string> area_1 = split_string(elves[0], "-");
    vector<string> area_2 = split_string(elves[1], "-");

    if (stoi(area_1[0]) >= stoi(area_2[0]) &&
            stoi(area_1[0]) <= stoi(area_2[1]) ||
        stoi(area_2[0]) >= stoi(area_1[0]) &&
            stoi(area_2[0]) <= stoi(area_1[1])) {
      result += 1;
    }
  }
  return result;
}

void solve_4() {
  cout << "Day 4 solutions:" << endl;
  vector<string> lines = read_file("D4/inp.txt");
  cout << "Part A: " << fully_contained(lines) << endl;
  cout << "Part B: " << overlap(lines) << endl;
}
