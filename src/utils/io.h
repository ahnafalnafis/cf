/**
 * Copyright 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_UTILS_IO_H_
#define SRC_UTILS_IO_H_

#include <string_view>

void print(std::string_view message);
void warn(std::string_view message);
void error(std::string_view message);

#endif  // SRC_UTILS_IO_H_
