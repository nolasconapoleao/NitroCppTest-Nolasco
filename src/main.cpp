#include "utilities/CustomList.h"
#include<iostream>

int main() {
  RectangleVector rectangles{};
  rectangles.parseFromJson("/home/nolasco/Projects/Sandbox/cpp/Nitro/src/example.json");
  rectangles.print();
  const auto intersections {rectangles.calculate_intersections()};
  for (const auto &intersection : intersections) {
    std::cout << intersection;
  };
  return 0;
}
