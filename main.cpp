#include "yaml_parce.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc > 1) {
    try {

      for (auto program : parse(argv[1])) {
        std::cout << "name: " << program.name << '\n'
                  << "path: " << program.executable_path << '\n'
                  << "stdout_file: " << program.stdout_config_file << '\n'
                  << "truncate: " << program.stdout_config_truncate << '\n';
        
        for (auto option: program.cmd_arguments) {
            std::cout << "arg: " << option << endl;
        }
        std::cout << "-----------" << std::endl;
      }
    } catch (std::exception &ex) {
      std::cout << "Ouch! That hurts, because: " << ex.what() << "!"
                << std::endl;
    }
  } else {
    std::cout << "Pass config filename as first argument to program"
              << std::endl;
  }
}