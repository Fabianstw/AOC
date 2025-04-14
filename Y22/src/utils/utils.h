//
// Copyright Fabian Stiewe
//
#pragma once

#include <iostream>
#include <string>
#include <vector>

#ifndef UTILS_H
#define UTILS_H

std::vector<std::string> split_string(const std::string& str,
                                      const std::string& delimiter);
std::vector<std::string> read_file(const std::string& filename);

#endif  // UTILS_H
