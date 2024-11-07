/**
 * Copyright (C) 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include <cstdlib>
#include <format>
#include <iostream>
#include <vector>

#include "create_file.h"

void print_usage() {
  const auto message = "Usage: cf [OPTION]... FILE...\n"
                       "Create file(s) if they do not exists.\n"
                       "\n"
                       "Options:\n"
                       "    -h, --help        Display this message and exit.\n"
                       "    -v, --verbose     Explain what is being done.\n";

  std::cout << message << std::flush;
}

int main(int argc, char *argv[]) {
  std::string_view argument = "";
  std::vector<std::string_view> files = {};
  Options options;

  options.verbose = false;

  for (int i = 1; i < argc; i++) {
    argument = argv[i];

    if (argument == "-v" || argument == "--verbose") {
      options.verbose = true;

    } else if (argument == "-h" || argument == "--help") {
      print_usage();
      return EXIT_SUCCESS;

    } else if (argument.starts_with("-")) {
      std::cout << std::format("Invalid option: '{}'", argument) << std::endl
                << "Type '-h' for more info." << std::endl;
      return EXIT_FAILURE;

    } else if (argument.empty()) {
      std::cout << "No file name was given." << std::endl;
      return EXIT_FAILURE;

    } else {

      files.push_back(argument);
    }
  }

  create_file(files, options);

  return EXIT_SUCCESS;
}
