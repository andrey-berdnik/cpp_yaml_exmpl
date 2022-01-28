#ifndef _YAML_PARCE
#define _YAML_PARCE

#include <iostream>
#include <vector>

struct config {
  std::string name;
  std::string executable_path;
  std::string stdout_config_file;
  bool stdout_config_truncate;
  std::vector<std::string> cmd_arguments;
};

std::vector<config> parse(const std::string filename);
#endif