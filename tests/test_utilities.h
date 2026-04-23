#pragma once

#include "utilities/Rectangle.h"

bool operator==(const Point2d &lhs, const Point2d &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}
