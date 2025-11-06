#include "MapLoader.h"
#include <fstream>
#include <string>

void MapLoader::Load(std::string fname) {
  std::ifstream mapfile(fname);
  std::string line;
  bool mapisValid = false;
  while (std::getline(mapfile, line)) {
    if (!mapisValid) {
      if (line == "[Map]") {
        mapisValid = true;
        continue;
        ;
      } else {
        std::cout << "Map is not valid" << std::endl;
        break;
      }
    }

    if (mapisValid) {
      for (auto b = line.begin(); b != line.end(); b++) {
        if (*b == '=') {
          std::string ke(line.begin(), b);
          std::string va(++b, line.end());
          filevars.push_back(std::make_pair(ke, va));
        }
      }
      std::cout << line << std::endl;
    } else {
      std::cout << "Line did not have = : " << line << std::endl;
    }
  }
  for (auto a : filevars) {
    std::cout << "Key: " << a.first << ", Value: " << a.second << std::endl;
  }
}
