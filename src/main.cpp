
#include <iostream>
#include <iterator>

#include "utilities/Intersector.h"

int main() {
  const std::string filepath {"/home/nolasco/Projects/Sandbox/cpp/Nitro/src/example.json"};
  Intersector intersector{};
  if(!intersector.parseFromFile(filepath)) {
    return 1;
  }
  
  std::cout << "Input:\n";
  intersector.printRectangles();

  std::cout << "\nIntersections\n";
  const auto intersections{intersector.calculate_intersections()};
  for (const auto &intersection : intersections) {
    std::cout << intersection;
  };
  return 0;
}
