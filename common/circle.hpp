#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "/Users/macbookpro/CLionProjects/AAA3/common/shape.hpp"
#include "/Users/macbookpro/CLionProjects/AAA3/common/base-types.hpp"

namespace golovin
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &, double);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void scale(double) override;

    void move(const point_t &) override;

    void move(double dX, double dY) override;

    point_t getPos() const override;

  private:
    point_t center_;
    double radius_;
  };
}
#endif
