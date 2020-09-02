#include "rectangle.hpp"
#include <stdexcept>

golovin::Rectangle::Rectangle(const point_t &center, double width, double height):
  center_(center),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Error\nThe incoming sides of the rectangle must be > 0");
  }
}

double golovin::Rectangle::getArea() const
{
  return width_ * height_;
}

golovin::rectangle_t golovin::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void golovin::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error\nThe incoming coefficient of the scalability must be > 0");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}

void golovin::Rectangle::move(const point_t &destinationPoint)
{
  center_ = destinationPoint;
}

void golovin::Rectangle::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}

golovin::point_t golovin::Rectangle::getPos() const {
  return getFrameRect().pos;
}
