
#include<iterator>
#include <iostream>

#include "utilities/CustomList.h"

int main() {

  std::string inp { R"({
      "rects": [
          {"x": 100, "y": 100, "w": 250, "h": 80 },
          {"x": 120, "y": 200, "w": 250, "h": 150 },
          {"x": 140, "y": 160, "w": 250, "h": 100 },
          {"x": 160, "y": 140, "w": 350, "h": 190 }
      ]
  })"};

  RectangleVector rectangles{};
  // rectangles.parsefrom("/home/nolasco/Projects/Sandbox/cpp/Nitro/src/example.json");
  rectangles.parseFromString(inp);

  const auto intersections{rectangles.calculate_intersections()};
  for (const auto &intersection : intersections) {
    std::cout << intersection;
  };
  return 0;
}
