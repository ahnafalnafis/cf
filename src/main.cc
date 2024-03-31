/**
 * Copyright 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#include "file_system.h"
#include "utils/loggers.h"

int main(int argc, char *argv[]) {
  const auto has_arguments = argc > 1;

  if (!has_arguments) {
    error("No file name was given.");
    return EXIT_FAILURE;
  }

  // Each argument will be temporarily stored here.
  auto argument = std::string();

  // TODO: Move option parsing to another module.
  auto options = std::map<std::string, bool>();
  options["verbose"] = false;

  auto files = std::vector<std::string>();

  // Parsing arguments:
  for (int i = 1; i < argc; i++) {
    argument = argv[i];
    if (argument == "-v" || argument == "--verbose") {
      options["verbose"] = true;
    } else {
      files.push_back(argument);
    }
  }

  if (files.empty()) {
    error("No file name was given.");
    return EXIT_FAILURE;
  }

  // Finally, create specified files.
  for (auto file : files) {
    const bool failure = fs::create_file(file, options);
    if (failure) return failure;
  }

  return EXIT_SUCCESS;
}
