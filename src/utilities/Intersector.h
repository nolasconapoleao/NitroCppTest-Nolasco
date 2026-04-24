#pragma once

#include <nlohmann/json.hpp>
#include <vector>

#include "Rectangle.h"

using json = nlohmann::json;

/**
 * @brief Represents an intersection entry
 * @param indexes list of rectangle indexes from the input (0 indexed)
 * @param rectangle produced by intersecting the rectangles
 */
struct Intersection {
  std::vector<uint> indexes;
  Rectangle rectangle;
};

std::ostream &operator<<(std::ostream &oss, const Intersection &intersection);

class Intersector {
public:
  Intersector() = default;
  [[nodiscard]] bool parseFromString(const std::string &fileDump);
  [[nodiscard]] bool parseFromFile(const std::string &filepath);
  [[nodiscard]] std::vector<Intersection> calculate_intersections();
  void printRectangles();
  /// @brief Unit test utility
  void clear();
private:
  [[nodiscard]] bool parse(const nlohmann::json &j);
  std::vector<Rectangle> rectangles{};
};
