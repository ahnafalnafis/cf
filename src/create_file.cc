/**
 * Copyright (C) 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include "create_file.h"

#include <filesystem>
#include <format>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <string_view>

#include "util.h"

void create_file(const std::vector<std::string_view> &files,
                 const Options &options) {

  for (const auto file_name : files) {
    if (std::filesystem::exists(file_name)) {
      std::cout << "File already exists" << std::endl;
      return;
    }

    const std::string parent_path =
        remove_cwd(std::filesystem::path(std::filesystem::absolute(file_name))
                       .parent_path()
                       .string());

    if (!std::filesystem::exists(parent_path)) {
      std::filesystem::create_directories(parent_path);

      if (options.verbose) {
        std::cout << std::format("Created parent directories '{}'", parent_path)
                  << std::endl;
      }
    }

    std::ofstream file(std::string(file_name), std::ios_base::app);
    file.close();

    if (options.verbose) {
      std::cout << std::format("Created file '{}'", file_name) << std::endl;
    }
  }

  return;
}
