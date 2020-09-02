#include "/Users/macbookpro/CLionProjects/AAA3/common/triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

golovin::Triangle::Triangle(const point_t & a, const point_t & b, const point_t & c):
  a_(a),
  b_(b),
  c_(c)
{
  if (getArea() <= 0.0)
  {
    throw std::invalid_argument("Error\nAll points lie on one straight line");
  }
}

double golovin::Triangle::getArea() const
{
  return std::abs(a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y))/2.0;
}

golovin::rectangle_t golovin::Triangle::getFrameRect() const
{
  const double minX = std::min(std::min(a_.x, b_.x), c_.x);
  const double minY = std::min(std::min(a_.y, b_.y), c_.y);
  const double maxX = std::max(std::max(a_.x, b_.x), c_.x);
  const double maxY = std::max(std::max(a_.y, b_.y), c_.y);
  return {std::abs(maxX - minX), std::abs(maxY - minY), {(maxX + minX) / 2, (maxY + minY) / 2}};
}

void golovin::Triangle::move(const point_t &destinationPoint)
{
  const double deltaX = destinationPoint.x - Triangle::getPos().x;
  const double deltaY = destinationPoint.y - Triangle::getPos().y;
  move(deltaX, deltaY);
}

void golovin::Triangle::move(double dX, double dY)
{
  a_.x += dX;
  b_.x += dX;
  c_.x += dX;
  a_.y += dY;
  b_.y += dY;
  c_.y += dY;
}

golovin::point_t golovin::Triangle::getPos() const
{
  return point_t({(a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3});
}

void golovin::Triangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error\nThe incoming coefficient of the scalability must be > 0");
  }
  point_t basePoint = getPos();
  a_.x *= coefficient;
  a_.y *= coefficient;
  b_.x *= coefficient;
  b_.y *= coefficient;
  c_.x *= coefficient;
  c_.y *= coefficient;
  move(basePoint);
}
