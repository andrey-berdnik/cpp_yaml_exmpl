#include <iostream>
#include "include/yaml_parse.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc > 1) {








    try {
      auto program = parse_yaml(argv[1]);
      // TODO: add logic there

    } catch (std::exception &ex) {
      cout << "Ouch! That hurts, because: " << ex.what() << "!" << endl;
    }
  } else {
    cout << "Pass config filename as first argument to program" << endl;
  }
}