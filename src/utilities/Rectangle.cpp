#include "Rectangle.h"

#include <array>
#include <cmath>
#include <iostream>

std::optional<Rectangle> Rectangle::intersect(const Rectangle &ot) const {
  if (*this == ot) {
    return *this;
  }

  // Separating axis theorem
  if (x + width <= ot.x || y + height <= ot.y || ot.x + ot.width <= x || ot.y + ot.height <= y) {
    return {};
  }

  const auto intLeft{std::max(x, ot.x)};
  const auto intTop{std::max(y, ot.y)};
  const auto intRight{std::min(x + width, ot.x + ot.width)};
  const auto intBottom{std::min(y + height, ot.y + ot.height)};
  return Rectangle{intLeft, intTop, intRight - intLeft, intBottom - intTop};
}

std::ostream &operator<<(std::ostream &oss, const Rectangle &rectangle) {
  oss << "(" << rectangle.x << "," << rectangle.y << "), w=" << rectangle.width << ", h=" << rectangle.height;
  return oss;
}

bool operator==(const Rectangle &lhs, const Rectangle &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.width == rhs.width && lhs.height == rhs.height;
}