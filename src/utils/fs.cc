/**
 * Copyright (C) 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "utils/fs.h"

#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>

#include "types.h"
#include "utils/io.h"

using std::format;

[[nodiscard]] bool fs::create_files(const std::vector<std::string> &files,
                                    const Options &options) {
  if (files.empty()) {
    error("No file name was given.");
    return EXIT_FAILURE;
  }

  for (const auto file_name : files) {
    if (std::filesystem::exists(file_name)) {
      error(format("File '{}' already exists!", file_name));
      return EXIT_FAILURE;
    }

    const auto parent_path =
        std::filesystem::path(std::filesystem::absolute(file_name))
            .parent_path()
            .string();

    std::filesystem::create_directories(parent_path);

    if (options.at("verbose")) {
      print(format("Created parent directories '{}'", parent_path));
    }

    std::ofstream file(file_name);

    if (options.at("verbose")) {
      print(format("Created file '{}'", file_name));
    }

    file.close();
  }

  return EXIT_SUCCESS;
}
