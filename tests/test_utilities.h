#pragma once

#include "utilities/Rectangle.h"

bool operator==(const Point2d &lhs, const Point2d &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator==(const Rectangle &lhs, const Rectangle &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.width == rhs.width && lhs.height == rhs.height;
}