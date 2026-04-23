#include "CustomList.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::ostream &operator<<(std::ostream &oss, const Intersection &intersection) {
  oss << "Between rectangle " << intersection.indexes[0]+1;
  for(auto k {1u}; k < intersection.indexes.size(); k++) {
    oss << (k==intersection.indexes.size()-1 ? " and " : ", ") << intersection.indexes[k]+1;
  }
  oss << " at " << intersection.rectangle << ".\n";
  return oss;
}

void RectangleVector::parseFromJson(const std::string &filepath) {
  std::ifstream f(filepath);
  json data = json::parse(f);

  rectangles.reserve(data["rects"].size());
  for (const auto &val : data["rects"]) {
    rectangles.emplace_back(
        Rectangle{val["x"].get<int>(), val["y"].get<int>(), val["w"].get<int>(), val["h"].get<int>()});
  }
}

void RectangleVector::print() {
  // TODO: Beware of zero indexing in vector
  auto k{1u};
  for (const auto &rect : rectangles) {
    std::cout << k++ << ": Rectangle at " << rect << ".\n";
  };
}

[[nodiscard]] std::vector<Intersection> RectangleVector::calculate_intersections(long unsigned int level) {
  if(level == 0) {
    level = rectangles.size();
  }

  std::vector<Intersection> result;
  for (auto ii{0u}; ii < rectangles.size(); ii++) {
    for (auto jj{ii + 1}; jj < rectangles.size(); jj++) {
      const auto intersect = rectangles[ii].intersect(rectangles[jj]);
      if(intersect.has_value()) {
        std::vector<uint> indexes = {ii, jj};
        result.emplace_back(Intersection{indexes, intersect.value()});
      }
    }
  }

  //TODO: Add level after 2
  for (auto ii : result) {
    for (auto jj{ii.indexes.back() + 1}; jj < rectangles.size(); jj++) {
      const auto intersect = ii.rectangle.intersect(rectangles[jj]);
      if(intersect.has_value()) {
        std::vector<uint> indexes = ii.indexes;
        indexes.emplace_back(jj);
        result.emplace_back(Intersection{indexes, intersect.value()});
      }
    }
  }
  return result;
};
