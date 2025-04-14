//
// Copyright 2025 Fabian Stiewe
//

#include "D3/sol3.h"

#include <cctype>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "utils/utils.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int get_priority(char item) {
  if (std::islower(item)) {
    return item - 'a' + 1;
  } else if (std::isupper(item)) {
    return item - 'A' + 27;
  } else {
    return -1;
  }
}

int count_false_order(const vector<string>& lines) {
  int total_score = 0;

  for (const auto& line : lines) {
    vector<string> parts = split_string(line, "");
    int mid = static_cast<int>(parts.size()) / 2;
    std::set<std::string> seen_objects;
    for (int i = 0; i < mid; i++) {
      seen_objects.insert(parts[i]);
    }
    for (int i = mid; i < parts.size(); i++) {
      if (seen_objects.find(parts[i]) != seen_objects.end()) {
        total_score += get_priority(parts[i][0]);
        break;
      }
    }
  }

  return total_score;
}

int count_badge_numbers(const vector<string>& lines) {
  int total_score = 0;

  for (int i = 0; i < lines.size(); i += 3) {
    std::set<std::string> part_1;
    std::set<std::string> part_2;
    std::set<std::string> part_3;

    vector<string> parts_1 = split_string(lines[i], "");
    part_1.insert(parts_1.begin(), parts_1.end());

    vector<string> parts_2 = split_string(lines[i + 1], "");
    part_2.insert(parts_2.begin(), parts_2.end());

    vector<string> parts_3 = split_string(lines[i + 2], "");
    part_3.insert(parts_3.begin(), parts_3.end());

    std::set<std::string> intersection_12;
    std::set<std::string> intersection_123;
    // Compute intersection of part_1 and part_2
    std::set_intersection(part_1.begin(), part_1.end(), part_2.begin(), part_2.end(),
                          std::inserter(intersection_12, intersection_12.begin()));

    // Compute intersection of the result with part_3
    std::set_intersection(intersection_12.begin(), intersection_12.end(), part_3.begin(),
                          part_3.end(), std::inserter(intersection_123, intersection_123.begin()));

    total_score += get_priority((*intersection_123.begin())[0]);
  }

  return total_score;
}

void solve_3() {
  cout << "Day 3 solutions: " << endl;
  std::string filename = "D3/inp.txt";
  const vector<string> lines = readFile(filename);
  cout << "Part A: " << count_false_order(lines) << endl;
  cout << "Part B: " << count_badge_numbers(lines) << endl;
}
