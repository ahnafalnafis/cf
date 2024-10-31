/**
 * Copyright (C) 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "utils/fs.h"

#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <string>

#include "types.h"
#include "utils/io.h"

using std::format;

std::string remove_cwd(std::string file_path) {
  const auto cwd = std::filesystem::current_path().string() + '/';

  if (file_path.rfind(cwd, 0) == 0) {
    file_path = file_path.erase(file_path.find(cwd), cwd.length());
  }
  return file_path;
}

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

    if (!std::filesystem::exists(parent_path)) {
      std::filesystem::create_directories(parent_path);

      if (options.at("verbose")) {
        print(format("Created parent directories: '{}'",
                     remove_cwd(parent_path)));
      }
    }

    std::ofstream file(file_name);
    file.close();

    if (options.at("verbose")) {
      print(format("Created file: '{}'", file_name));
    }
  }

  return EXIT_SUCCESS;
}
