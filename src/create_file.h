/**
 * Copyright (C) 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_CREATE_FILE_H_
#define SRC_CREATE_FILE_H_

#include <string_view>
#include <vector>

/**
 * TODO:
 * Add following options:
 *   - Permissions
 */
struct Options {
  bool verbose;
};

void create_file(const std::vector<std::string_view> &files,
                 const Options &options);

#endif // SRC_UTILS_FS_H_
