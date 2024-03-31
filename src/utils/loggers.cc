/**
 * Copyright 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "utils/loggers.h"

#include <iostream>
#include <string>

// TODO: Add colors in console messages.

void warn(const std::string &message) {
  std::cout << "WARNING: " << message << std::endl;
}

void error(const std::string &message) {
  std::cout << "ERROR: " << message << std::endl;
}
