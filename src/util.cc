#include "util.h"

#include <filesystem>
#include <string>

std::string remove_cwd(std::string file_path) {
  const auto cwd = std::filesystem::current_path().string() + '/';

  if (file_path.rfind(cwd, 0) == 0) {
    file_path = file_path.erase(file_path.find(cwd), cwd.length());
  }

  return file_path;
}
