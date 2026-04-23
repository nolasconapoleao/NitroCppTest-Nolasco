#include "Rectangle.h"

#include<vector>

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
  [[nodiscard]] std::vector<Intersection> calculate_intersections(long unsigned int level=0);

private:
  std::vector<Rectangle> rectangles {};
};
