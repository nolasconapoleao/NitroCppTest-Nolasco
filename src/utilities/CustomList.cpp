#include "CustomList.h"

#include <iostream>
#include <fstream>


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

void RectangleVector::parseFromFile(const std::string &filepath) {
  std::ifstream f(filepath);
  json data = json::parse(f);
  parse(data);
}

void RectangleVector::parseFromString(const std::string &fileDump) {
  json data = json::parse(fileDump);
  parse(data);
}

void RectangleVector::print() {
  // Important: Beware of zero indexing in print
  auto id{1u};
  for (const auto &rect : rectangles) {
    std::cout << id++ << ": Rectangle at " << rect << ".\n";
  };
}

[[nodiscard]] std::vector<Intersection> RectangleVector::calculate_intersections() {
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


void RectangleVector::parse(const json &data) {
 // TODO: Check input sanity
  rectangles.reserve(data["rects"].size());
  for (const auto &val : data["rects"]) {
    rectangles.emplace_back(
        Rectangle{val["x"].get<int>(), val["y"].get<int>(), val["w"].get<int>(), val["h"].get<int>()});
  }
}