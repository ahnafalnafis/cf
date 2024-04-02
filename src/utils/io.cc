/**
 * Copyright 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "utils/io.h"

#include <iostream>
#include <string_view>

void print(std::string_view message) { std::cout << message << std::endl; }

void warn(std::string_view message) {
  std::cout << "WARNING: " << message << std::endl;
}

void error(std::string_view message) {
  std::cout << "ERROR: " << message << std::endl;
}
