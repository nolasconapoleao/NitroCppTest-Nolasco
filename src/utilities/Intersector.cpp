#include "Intersector.h"

#include <fstream>
#include <iostream>

std::ostream &operator<<(std::ostream &oss, const Intersection &intersection) {
  // Important: Beware of zero indexing in print
  constexpr auto offset{1u};
  oss << "Between rectangle " << intersection.indexes[0] + offset;

  // Print , | and by checking index
  for (auto k{1u}; k < intersection.indexes.size(); k++) {
    oss << (k == intersection.indexes.size() - 1 ? " and " : ", ") << intersection.indexes[k] + offset;
  }
  oss << " at " << intersection.rectangle << ".\n";
  return oss;
}

bool Intersector::parseFromFile(const std::string &filepath) {
  std::ifstream f(filepath);
  if (!f.is_open()) {
    std::cerr << "Incorrect file path or json file does not exist\n";
    return false;
  }

  try {
    json data = json::parse(f);
    return parse(data);
  } catch (...) {
    std::cerr << "Invalid json schema";
    return false;
  }
}

bool Intersector::parseFromString(const std::string &fileDump) {
  try {
    json data = json::parse(fileDump);
    return parse(data);
  } catch (...) {
    std::cerr << "Invalid json schema";
    return false;
  }
}

void Intersector::clear() {
  rectangles.clear();
}

void Intersector::printRectangles() {
  // Important: Beware of zero indexing in print
  auto id{1u};
  for (const auto &rect : rectangles) {
    std::cout << id++ << ": Rectangle at " << rect << ".\n";
  };
}

//TODO: Optimization: Two identical rectangles don't need to be tested, any intersection for A also exists for B
[[nodiscard]] std::vector<Intersection> Intersector::calculate_intersections() {
  // Search space for intersections should avoid ii <= jj, since a rectangle intersects itself and A & B equals B & A
  std::vector<Intersection> result;
  for (auto ii{0u}; ii < rectangles.size(); ii++) {
    for (auto jj{ii + 1}; jj < rectangles.size(); jj++) {
      const auto intersect = rectangles[ii].intersect(rectangles[jj]);
      if (intersect.has_value()) {
        std::vector<uint> indexes = {ii, jj};
        result.emplace_back(Intersection{indexes, intersect.value()});
      }
    }
  }

  // Search space for intersections can skip previous empty intersections, and continue from last
  for (auto ii{0u}; ii < result.size(); ii++) {
    for (auto jj{result[ii].indexes.back() + 1}; jj < rectangles.size(); jj++) {
      const auto intersect = result[ii].rectangle.intersect(rectangles[jj]);
      if (intersect.has_value()) {
        std::vector<uint> indexes = result[ii].indexes;
        indexes.emplace_back(jj);
        result.emplace_back(Intersection{indexes, intersect.value()});
      }
    }
  }
  return result;
};

bool Intersector::parse(const json &j) {
  // Smoke tests
  if (!j.contains("rects")) {
    std::cerr << "Json file has no rects field\n";
    return false;
  }

  rectangles.reserve(j["rects"].size());
  for (const auto &val : j["rects"]) {
    // Skip invalid lines in json
    if (val.contains("x") && val.contains("y") && val.contains("w") && val.contains("h")) {
      rectangles.emplace_back(
          Rectangle{val["x"].get<int>(), val["y"].get<int>(), val["w"].get<int>(), val["h"].get<int>()});
    }
  }

  //Failed to parse unless more than 1 rectangle captured
  return (rectangles.size()!=0);
}