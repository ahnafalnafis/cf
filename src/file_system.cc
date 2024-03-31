/**
 * Copyright 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "file_system.h"

#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>

#include "types.h"
#include "utils/loggers.h"

[[nodiscard]] bool fs::create_file(const std::string &file_name,
                                   const Options &options) {
  const auto file_exists = std::filesystem::exists(file_name);

  if (file_exists) {
    error(std::format("File '{}' already exists!", file_name));

    return EXIT_FAILURE;
  }

  std::ofstream file(file_name);

  if (options.at("verbose")) {
    std::cout << std::format("Created file '{}'", file_name) << std::endl;
  }

  file.close();

  return EXIT_SUCCESS;
}
