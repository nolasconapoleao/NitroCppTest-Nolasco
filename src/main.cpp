#include <fstream>
#include <nlohmann/json.hpp>

#include "rectangle/Rectangle.h"
using json = nlohmann::json;

int main() {
  std::ifstream f("/home/nolasco/Projects/Sandbox/cpp/Nitro/src/example.json");
  json data = json::parse(f);

  std::vector<Rectangle> vec;
  vec.reserve(data["rects"].size());
  for (const auto &val : data["rects"]) {
    vec.emplace_back(Rectangle{val["x"].get<int>(), val["y"].get<int>(), val["w"].get<int>(), val["h"].get<int>()});
  }

  for (const auto &val : vec) {
    std::cout << val;
  }
  return 0;
}
