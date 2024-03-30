/**
 * Copyright 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "file_system.h"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "types.h"
#include "utils.h"

// TODO: Refactor this function
[[nodiscard]] bool fs::create_file(const std::string &file_name,
                                   Options &options) {
  const auto file_exists = std::filesystem::exists(file_name);

  if (file_exists) {
    if (!options["force"]) {
      std::cout << "File '" << file_name << "' already exists" << std::endl;
      return EXIT_FAILURE;
    }

    warn("File already exists and is being overwritten");
  }

  std::ofstream file(file_name);

  if (options["verbose"]) {
    if (file_exists && options["force"]) {
      std::cout << "Overwritten file '" << file_name << "'" << std::endl;
    } else {
      std::cout << "Created file '" << file_name << "'" << std::endl;
    }
  }

  file.close();

  return EXIT_SUCCESS;
}
