/**
 * Copyright (C) 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_UTILS_FS_H_
#define SRC_UTILS_FS_H_

#include <string>
#include <vector>

#include "types.h"

namespace fs {
[[nodiscard]] bool create_files(const std::vector<std::string> &files,
                                const Options &options);
}  // namespace fs

#endif  // SRC_UTILS_FS_H_
