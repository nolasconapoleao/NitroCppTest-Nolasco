
#include <iostream>
#include <iterator>

#include "utilities/Intersector.h"

int main(int, char *argv[]) {
  const std::string filepath{argv[1]};
  Intersector intersector{};
  if (!intersector.parseFromFile(filepath)) {
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
