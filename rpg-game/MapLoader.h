#include <string>
#include <utility>
#include <vector>
#pragma one
#include <iostream>

class MapLoader {
public:
  std::vector<std::pair<std::string, std::string>> filevars;
  void Load(std::string);
};
