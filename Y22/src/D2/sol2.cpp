//
// Copyright 2025 Fabian Stiewe
//

#include "D2/sol2.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

vector<string> readFileLines_2() {
  vector<string> lines;

  if (ifstream file("D2/inp.txt"); file.is_open()) {
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

std::vector<std::string> split(const std::string& str, char delimiter) {
  std::vector<std::string> tokens;
  std::stringstream ss(str);
  std::string token;

  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}

std::map<std::string, std::string> mapping = {
    {"A", "X"}, {"B", "Y"}, {"C", "Z"}};
std::map<std::string, int> scores = {{"X", 1}, {"Y", 2}, {"Z", 3}};
std::map<std::string, int> game_scores = {
    {"AX", 3}, {"AY", 6}, {"AZ", 0}, {"BX", 0}, {"BY", 3},
    {"BZ", 6}, {"CX", 6}, {"CY", 0}, {"CZ", 3},
};

int total_score(const vector<string>& lines) {
  int total_score = 0;

  for (const auto& line : lines) {
    vector<string> line_parts = split(line, *" ");
    total_score += scores[line_parts[1]];
    total_score += game_scores[line_parts[0] + line_parts[1]];
  }

  return total_score;
}

int total_score_changed_rules(const vector<string>& lines) {
  int total_score = 0;

  std::map<std::string, std::string> win_map = {
      {"A", "Y"}, {"B", "Z"}, {"C", "X"}};
  std::map<std::string, std::string> loose_map = {
      {"A", "Z"}, {"B", "X"}, {"C", "Y"}};

  for (const auto& line : lines) {
    vector<string> line_parts = split(line, *" ");
    if (line_parts[1] == "X") {
      total_score += scores[loose_map[line_parts[0]]];
    } else if (line_parts[1] == "Y") {
      total_score += scores[mapping[line_parts[0]]] + 3;
    } else if (line_parts[1] == "Z") {
      total_score += scores[win_map[line_parts[0]]] + 6;
    }
  }

  return total_score;
}

void solve_2() {
  cout << "Day 2 solutions:" << endl;
  const vector<string> lines = readFileLines_2();
  cout << "Part A: " << total_score(lines) << endl;
  cout << "Part B: " << total_score_changed_rules(lines) << endl;
}
