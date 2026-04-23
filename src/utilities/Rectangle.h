#include <optional>
#include <ostream>

#pragma once

struct Point2d {
  int x{};
  int y{};
};

struct Rectangle {
  [[nodiscard]] std::optional<Rectangle> intersect(const Rectangle &other) const;
  std::array<Point2d, 4> get_vertices() const;
  bool contains(const Point2d) const;

  int x;
  int y;
  int width;
  int height;
};

std::ostream &operator<<(std::ostream &oss, const Rectangle &rectangle);
bool operator==(const Rectangle &lhs, const Rectangle &rhs);