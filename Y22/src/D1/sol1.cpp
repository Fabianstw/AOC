//
// Copyright 2025 Fabian Stiewe
//

#include "D1/sol1.h"

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::greater;
using std::ifstream;
using std::sort;
using std::stoi;
using std::string;
using std::vector;

vector<string> readFileLines() {
  vector<string> lines;
  ifstream file("D1/inp.txt");

  if (file.is_open()) {
    string line;
    while (std::getline(file, line)) {
      lines.push_back(line);
    }
    file.close();
  } else {
    std::cerr << "Unable to open file" << std::endl;
  }

  return lines;
}

int get_most_calories(const vector<string>& elves) {
  int current_calories = 0;
  int current_max = 0;
  for (const auto& elve : elves) {
    if (!elve.empty()) {
      current_calories += stoi(elve);
    } else {
      if (current_calories > current_max) {
        current_max = current_calories;
      }
      current_calories = 0;
    }
  }
  return current_max;
}

int top_three_calories(const vector<string>& elves) {
  int current_calories = 0;
  vector<int> calories;
  for (const auto& elve : elves) {
    if (!elve.empty()) {
      current_calories += stoi(elve);
    } else {
      calories.push_back(current_calories);
      current_calories = 0;
    }
  }
  // sort in decreasing order
  sort(calories.begin(), calories.end(), greater<>());

  return calories[0] + calories[1] + calories[2];
}

void solve() {
  const vector<string> lines = readFileLines();
  cout << "Day 1 solutions:" << endl;
  cout << get_most_calories(lines) << endl;
  cout << top_three_calories(lines) << endl;
}
