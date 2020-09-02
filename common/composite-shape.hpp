#ifndef A3_COMPOSITE_SHAPE_HPP
#define A3_COMPOSITE_SHAPE_HPP

#include <memory>
#include "/Users/macbookpro/CLionProjects/AAA3/common/shape.hpp"
#include "/Users/macbookpro/CLionProjects/AAA3/common/base-types.hpp"
namespace golovin {
  class CompositeShape : public Shape {
  public:
    typedef std::shared_ptr<Shape> shapePointer;
    typedef std::unique_ptr<shapePointer[]> shapeArray;

    CompositeShape();

    ~CompositeShape() override = default;

    CompositeShape(const CompositeShape &);

    CompositeShape(CompositeShape &&);

    CompositeShape& operator=(const CompositeShape&);

    CompositeShape& operator=(CompositeShape&&);

    shapePointer& operator[](size_t) const;

    void pushBack(const shapePointer &);

    void popBack();

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void scale(double) override;

    void move(const point_t &) override;

    void move(double dX, double dY) override;

    bool isEmpty() const;

    point_t getPos() const override;
  private:
    size_t size_{};
    size_t capacity_{};
    shapeArray array_;
    const int COEFFICIENT = 2;
    void swap(CompositeShape &);
  };
}
#endif //A3_COMPOSITE_SHAPE_HPP
