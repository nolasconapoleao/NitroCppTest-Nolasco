#include <vector>

#include "Rectangle.h"

#pragma once

struct Intersection {
  std::vector<uint> indexes;
  Rectangle rectangle;
};

std::ostream &operator<<(std::ostream &oss, const Intersection &intersection);

class RectangleVector {
public:
  RectangleVector() = default;
  void parseFromJson(const std::string &filepath);
  void print();
  [[nodiscard]] std::vector<Intersection> calculate_intersections();

private:
  std::vector<Rectangle> rectangles{};
};
