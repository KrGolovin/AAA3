#ifndef A1_SHAPE_HPP
#define A1_SHAPE_HPP

#include "base-types.hpp"

namespace golovin
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void scale(double) = 0;

    virtual void move(const point_t &) = 0;

    virtual void move(double dX, double dY) = 0;

    virtual point_t getPos() const = 0;
  };
}
#endif
