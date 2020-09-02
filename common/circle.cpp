#include "/Users/macbookpro/CLionProjects/AAA3/common/circle.hpp"
#include <cmath>
#include <stdexcept>

golovin::Circle::Circle(const point_t &center, double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Error\nThe incoming raduis of the circle must be > 0");
  }
}

double golovin::Circle::getArea() const
{
  return M_PI * std::pow(radius_, 2);
}

golovin::rectangle_t golovin::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void golovin::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error\nThe incoming coefficient of the scalability must be > 0");
  }
  radius_ *= coefficient;
}

void golovin::Circle::move(const point_t &destinationPoint)
{
  center_ = destinationPoint;
}

void golovin::Circle::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}

golovin::point_t golovin::Circle::getPos() const {
  return getFrameRect().pos;
}
