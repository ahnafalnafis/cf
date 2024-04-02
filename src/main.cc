/**
 * Copyright (C) 2024 Ahnaf Al Nafis
 * SPDX-License-Identifier: MIT
 */

#include <cstdlib>
#include <format>
#include <map>
#include <string>
#include <vector>

#include "types.h"
#include "utils/fs.h"
#include "utils/io.h"

void show_help_message() {
  print("Usage: cf FILE_NAME [OPTIONS...]");
  print("");
  print("Options:");
  print("    --verbose, -v        To show message.");
  print("");
}

int main(int argc, char *argv[]) {
  auto argument = std::string{""};
  auto files = std::vector<std::string>{};
  auto options = Options{};

  options["verbose"] = false;

  for (int i = 1; i < argc; i++) {
    argument = argv[i];

    if (argument == "-v" || argument == "--verbose") {
      options["verbose"] = true;

    } else if (argument == "-h" || argument == "--help") {
      show_help_message();
      return EXIT_SUCCESS;

    } else if (argument.starts_with("-")) {
      print(std::format("Argument '{}' is not valid option.", argument));
      print("Type -h for more info.");
      return EXIT_FAILURE;

    } else {
      files.push_back(argument);
    }
  }

  const bool status = fs::create_files(files, options);

  return status;
}
