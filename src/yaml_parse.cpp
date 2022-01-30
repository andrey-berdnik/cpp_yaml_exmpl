#include "include/yaml_parse.h"

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::vector<set_prog_start> parse_yaml(const std::string filename) {
  std::string line;
  std::vector<set_prog_start> out;

  ifstream file(filename);

  if (!file) {
    throw std::runtime_error("Could not open config file " + filename);
  }
  set_prog_start config_buffer;
  while (getline(file, line)) {
    if (line.find("  - name: ") == 0) {
      if (config_buffer.name != "" and config_buffer.executable_path != "") {
        out.push_back(config_buffer);
      }
      memset(&config_buffer, 0, sizeof(set_prog_start));
    }

    if (line.find("  - name: ") == 0) {
      config_buffer.name = line.substr(10);
      continue;
    }
    if (line.find("    executable-path: ") == 0) {
      config_buffer.executable_path = line.substr(21);
      continue;
    }
    if (line.find("      file: ") == 0) {
      config_buffer.stdout_config_file = line.substr(12);
      continue;
    }

    if (line.find("      - option-name: ") == 0) {
      config_buffer.cmd_arguments.push_back(line.substr(21));
      continue;
    }

    if (line.find("      - option-name: ") == 0) {
      if (line.substr(21) == "truncate") {
        config_buffer.stdout_config_truncate = true;
      } else {
        config_buffer.stdout_config_truncate = false;
      }
      continue;
    }
  }
  if (config_buffer.name != "" and config_buffer.executable_path != "") {
    out.push_back(config_buffer);
  }

  file.close();
  return out;
}