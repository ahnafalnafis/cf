/**
 * Copyright 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#ifndef SRC_FILE_SYSTEM_H_
#define SRC_FILE_SYSTEM_H_

#include <string>

#include "types.h"

namespace fs {

[[nodiscard]] bool create_file(const std::string &file_name,
                               const Options &options);

}  // namespace fs

#endif  // SRC_FILE_SYSTEM_H_
