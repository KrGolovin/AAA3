#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>
#include <stdexcept>
#include <cmath>
#include "/Users/macbookpro/CLionProjects/AAA3/common/rectangle.hpp"
#include "/Users/macbookpro/CLionProjects/AAA3/common/circle.hpp"
#include "/Users/macbookpro/CLionProjects/AAA3/common/triangle.hpp"
#include "/Users/macbookpro/CLionProjects/AAA3/common/composite-shape.hpp"

const double ACCURACY = 1e-8;

BOOST_AUTO_TEST_SUITE(TestRectangle)

  BOOST_AUTO_TEST_CASE(TestInvalidWidth)
  {
    const double width = -5.0;
    const double height = 10.0;
    const golovin::point_t basePoint{0.0, 0.0};

    BOOST_CHECK_THROW(golovin::Rectangle rectangle(basePoint, width, height), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidHeight)
  {
    const double width = 5.0;
    const double height = -10.0;
    const golovin::point_t basePoint{0.0, 0.0};

    BOOST_CHECK_THROW(golovin::Rectangle rectangle(basePoint, width, height), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMovingInPoint)
  {
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};
    const double width = 5.0;
    const double height = 10.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    rectangle.move(endPoint);

    BOOST_CHECK_CLOSE(rectangle.getPos().x, endPoint.x, ACCURACY);
    BOOST_CHECK_CLOSE(rectangle.getPos().y, endPoint.y, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestMovingByOffset)
  {
    const double dX = 2.0;
    const double dY = -2.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    rectangle.move(dX, dY);

    BOOST_CHECK_CLOSE(rectangle.getPos().x, basePoint.x + dX, ACCURACY);
    BOOST_CHECK_CLOSE(rectangle.getPos().y, basePoint.y + dY, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestRightArea)
  {
    const double width = 5.0;
    const double height = 10.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double rightArea = 50.0;

    golovin::Rectangle rectangle(basePoint, width, height);

    BOOST_CHECK_CLOSE(rectangle.getArea(), rightArea, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfRectangleAfterMovingInPoint)
  {
    const double baseWidth = 5.0;
    const double baseHeight = 10.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Rectangle rectangle(basePoint, baseWidth, baseHeight);
    double width = rectangle.getFrameRect().width;
    double height = rectangle.getFrameRect().height;
    rectangle.move(endPoint);

    BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfRectangleAfterMovingByOffset)
  {
    const double width = 2.0;
    const double height = 4.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    rectangle.move(dX, dY);

    BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingInPoint)
  {
    const double baseWidth = 5.0;
    const double baseHeight = 10.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Rectangle rectangle(basePoint, baseWidth, baseHeight);
    double area = rectangle.getArea();
    rectangle.move(endPoint);

    BOOST_CHECK_CLOSE(rectangle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingByOffset)
  {
    const double width = 2.0;
    const double height = 4.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    double area = rectangle.getArea();
    rectangle.move(dX, dY);

    BOOST_CHECK_CLOSE(rectangle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidScale)
  {
    const double width = 2.0;
    const double height = 4.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double scaleValue = -2.0;

    golovin::Rectangle rectangle(basePoint, width, height);

    BOOST_CHECK_THROW(rectangle.scale(scaleValue), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestRightAreaAfterScale)
  {
    const double width = 2.0;
    const double height = 4.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double scaleValue = 2.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    double area = rectangle.getArea();
    rectangle.scale(scaleValue);

    BOOST_CHECK_CLOSE(rectangle.getArea(), area * scaleValue * scaleValue, ACCURACY);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCircle)

  BOOST_AUTO_TEST_CASE(TestInvalidRadius)
  {
    const double radius = -5.0;
    const golovin::point_t basePoint{0.0, 0.0};

    BOOST_CHECK_THROW(golovin::Circle circle(basePoint, radius), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMovingInPoint)
  {
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};
    const double radius = 5.0;

    golovin::Circle circle(basePoint, radius);
    circle.move(endPoint);

    BOOST_CHECK_CLOSE(circle.getPos().x, endPoint.x, ACCURACY);
    BOOST_CHECK_CLOSE(circle.getPos().y, endPoint.y, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestMovingByOffset)
  {
    const double dX = 2.0;
    const double dY = -2.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double radius = 5.0;

    golovin::Circle circle(basePoint, radius);
    circle.move(dX, dY);

    BOOST_CHECK_CLOSE(circle.getPos().x, basePoint.x + dX, ACCURACY);
    BOOST_CHECK_CLOSE(circle.getPos().y, basePoint.y + dY, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestRightArea)
  {
    const golovin::point_t basePoint{0.0, 0.0};
    const double radius = 1.0;
    const double rightArea = M_PI;

    golovin::Circle circle(basePoint, radius);

    BOOST_CHECK_CLOSE(circle.getArea(), rightArea, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfCircleAfterMovingInPoint)
  {
    const double baseRadius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Circle circle(basePoint, baseRadius);
    double width = circle.getFrameRect().width;
    double height = circle.getFrameRect().height;
    circle.move(endPoint);

    BOOST_CHECK_CLOSE(circle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(circle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfCircleAfterMovingByOffset)
  {
    const double baseRadius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Circle circle(basePoint, baseRadius);
    double width = circle.getFrameRect().width;
    double height = circle.getFrameRect().height;
    circle.move(dX, dY);

    BOOST_CHECK_CLOSE(circle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(circle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingInPoint)
  {
    const double radius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Circle circle(basePoint, radius);
    double area = circle.getArea();
    circle.move(endPoint);

    BOOST_CHECK_CLOSE(circle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingByOffset)
  {
    const double radius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Circle circle(basePoint, radius);
    double area = circle.getArea();
    circle.move(dX, dY);

    BOOST_CHECK_CLOSE(circle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidScale)
  {
    const double radius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double scaleValue = -2.0;

    golovin::Circle circle(basePoint, radius);

    BOOST_CHECK_THROW(circle.scale(scaleValue), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestRightAreaAfterScale)
  {
    const double radius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double scaleValue = 2.0;

    golovin::Circle circle(basePoint, radius);
    double area = circle.getArea();
    circle.scale(scaleValue);

    BOOST_CHECK_CLOSE(circle.getArea(), area * scaleValue * scaleValue, ACCURACY);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestTriangle)

  BOOST_AUTO_TEST_CASE(TestInvalidPoints)
  {
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{2.0, 2.0};

    BOOST_CHECK_THROW(golovin::Triangle triangle(pointA, pointB, pointC), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMovingInPoint)
  {
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Triangle triangle(pointA, pointB, pointC);
    triangle.move(endPoint);

    BOOST_CHECK_CLOSE(triangle.getPos().x, endPoint.x, ACCURACY);
    BOOST_CHECK_CLOSE(triangle.getPos().y, endPoint.y, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestMovingByOffset)
  {
    const double dX = 2.0;
    const double dY = -2.0;
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    golovin::Triangle triangle(pointA, pointB, pointC);
    const golovin::point_t basePoint = triangle.getPos();
    triangle.move(dX, dY);

    BOOST_CHECK_CLOSE(triangle.getPos().x, basePoint.x + dX, ACCURACY);
    BOOST_CHECK_CLOSE(triangle.getPos().y, basePoint.y + dY, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestRightArea)
  {
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{0.0, 2.0};
    const golovin::point_t pointC{1.0, 0.0};
    const double rightArea = 1;

    golovin::Triangle triangle(pointA, pointB, pointC);

    BOOST_CHECK_CLOSE(triangle.getArea(), rightArea, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfTriangleAfterMovingInPoint)
  {
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};
    const golovin::point_t endPoint{10.0,-10.0};

    golovin::Triangle triangle(pointA, pointB, pointC);
    double width = triangle.getFrameRect().width;
    double height = triangle.getFrameRect().height;
    triangle.move(endPoint);

    BOOST_CHECK_CLOSE(triangle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(triangle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfTriangleAfterMovingByOffset)
  {
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Triangle triangle(pointA, pointB, pointC);
    double width = triangle.getFrameRect().width;
    double height = triangle.getFrameRect().height;
    triangle.move(dX, dY);

    BOOST_CHECK_CLOSE(triangle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(triangle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingInPoint)
  {
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};
    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Triangle triangle(pointA, pointB, pointC);
    double area = triangle.getArea();
    triangle.move(endPoint);

    BOOST_CHECK_CLOSE(triangle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingByOffset)
  {
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Triangle triangle(pointA, pointB, pointC);
    double area = triangle.getArea();
    triangle.move(dX, dY);

    BOOST_CHECK_CLOSE(triangle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidScale)
  {
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};
    const double scaleValue = -2.0;

    golovin::Triangle triangle(pointA, pointB, pointC);

    BOOST_CHECK_THROW(triangle.scale(scaleValue), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestRightAreaAfterScale)
  {
    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};
    const double scaleValue = 2.0;

    golovin::Triangle triangle(pointA, pointB, pointC);
    double area = triangle.getArea();
    triangle.scale(scaleValue);

    BOOST_CHECK_CLOSE(triangle.getArea(), area * scaleValue * scaleValue, ACCURACY);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CompositeShapeTest)

  BOOST_AUTO_TEST_CASE(TestEmptyCompositeShapeFrameRect)
  {
    golovin::CompositeShape compositeShape;

    BOOST_CHECK_THROW(compositeShape.getFrameRect(), std::logic_error);
  }

  BOOST_AUTO_TEST_CASE(TestCompositeShapeInvalidPushingElement)
  {
    golovin::CompositeShape testCompositeShape;

    BOOST_CHECK_THROW(testCompositeShape.pushBack(nullptr), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfCompositeShapeAfterMovingInPoint)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    const golovin::point_t endPoint{10.0, -10.0};

    golovin::CompositeShape::shapePointer rectangle =
      std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
      std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
      std::make_shared<golovin::Triangle>(pointA, pointB, pointC);

    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);
    golovin::rectangle_t baseRectangle = compositeShape.getFrameRect();
    compositeShape.move(endPoint);

    BOOST_CHECK_CLOSE(compositeShape.getPos().x, endPoint.x, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShape.getPos().y, endPoint.y, ACCURACY);

    BOOST_CHECK_CLOSE(baseRectangle.width, compositeShape.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(baseRectangle.height, compositeShape.getFrameRect().height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfCompositeShapeAfterMovingByOffset)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    const double dX = 2.0;
    const double dY = -2.0;

    golovin::CompositeShape::shapePointer rectangle =
      std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
      std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
      std::make_shared<golovin::Triangle>(pointA, pointB, pointC);

    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);
    golovin::rectangle_t baseRectangle = compositeShape.getFrameRect();
    compositeShape.move(dX, dY);

    BOOST_CHECK_CLOSE(compositeShape.getPos().x, baseRectangle.pos.x + dX, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShape.getPos().y, baseRectangle.pos.y + dY, ACCURACY);

    BOOST_CHECK_CLOSE(baseRectangle.width, compositeShape.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(baseRectangle.height, compositeShape.getFrameRect().height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfCompositeShapeAreaAfterMovingInPoint) {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    const golovin::point_t endPoint{10.0, -10.0};

    golovin::CompositeShape::shapePointer rectangle =
      std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
      std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
      std::make_shared<golovin::Triangle>(pointA, pointB, pointC);

    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);

    double baseArea = compositeShape.getArea();

    compositeShape.move(endPoint);

    BOOST_CHECK_CLOSE(baseArea, compositeShape.getArea(), ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfCompositeShapeAreaAfterMovingByOffset)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    const double dX = 2.0;
    const double dY = -2.0;

    golovin::CompositeShape::shapePointer rectangle =
      std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
      std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
      std::make_shared<golovin::Triangle>(pointA, pointB, pointC);

    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);

    double baseArea = compositeShape.getArea();

    compositeShape.move(dX, dY);

    BOOST_CHECK_CLOSE(baseArea, compositeShape.getArea(), ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidScalingCoefficient)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    const double coefficient = -2.0;

    golovin::CompositeShape::shapePointer rectangle =
      std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
      std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
      std::make_shared<golovin::Triangle>(pointA, pointB, pointC);

    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);

    BOOST_CHECK_THROW(compositeShape.scale(coefficient), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCompositeShapeAreaAfterScale)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    const double coefficient = 2.0;

    golovin::CompositeShape::shapePointer rectangle =
      std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
      std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
      std::make_shared<golovin::Triangle>(pointA, pointB, pointC);

    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);
    double baseArea = compositeShape.getArea();
    compositeShape.scale(coefficient);

    BOOST_CHECK_CLOSE(baseArea * coefficient * coefficient, compositeShape.getArea(), ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestCompositeShapeInvalidIndex)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    golovin::CompositeShape::shapePointer rectangle =
      std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
      std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
      std::make_shared<golovin::Triangle>(pointA, pointB, pointC);
    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);

    BOOST_CHECK_THROW(compositeShape[-1], std::out_of_range);
    BOOST_CHECK_THROW(compositeShape[3], std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(TestIndexTreatment)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    golovin::CompositeShape::shapePointer rectangle =
      std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
      std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
      std::make_shared<golovin::Triangle>(pointA, pointB, pointC);
    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);

    double areaOfRectangle = rectangle->getArea();
    double areaOfCircle = circle->getArea();
    double areaOfTriangle = triangle->getArea();

    BOOST_CHECK_CLOSE(areaOfRectangle, compositeShape[0]->getArea(), ACCURACY);
    BOOST_CHECK_CLOSE(areaOfCircle, compositeShape[1]->getArea(), ACCURACY);
    BOOST_CHECK_CLOSE(areaOfTriangle, compositeShape[2]->getArea(), ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestDeleteFigures)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    golovin::CompositeShape::shapePointer rectangle =
      std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
      std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
      std::make_shared<golovin::Triangle>(pointA, pointB, pointC);
    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);
    compositeShape.popBack();
    compositeShape.popBack();
    compositeShape.popBack();
    BOOST_CHECK_THROW(compositeShape.popBack(), std::logic_error);
  }

  BOOST_AUTO_TEST_CASE(TestCompositeShapeCopyAssigmentOperator)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    golovin::CompositeShape::shapePointer rectangle =
            std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
            std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
            std::make_shared<golovin::Triangle>(pointA, pointB, pointC);
    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);

    golovin::CompositeShape copyCompositeShape = compositeShape;
    golovin::rectangle_t compositeShapeFrameRect = compositeShape.getFrameRect();
    golovin::rectangle_t copyCompositeShapeFrameRect = copyCompositeShape.getFrameRect();
    double compositeShapeArea = compositeShape.getArea();
    double copyCompositeShapeArea = copyCompositeShape.getArea();

    BOOST_CHECK_CLOSE(compositeShapeFrameRect.pos.x, copyCompositeShapeFrameRect.pos.x, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShapeFrameRect.pos.y, copyCompositeShapeFrameRect.pos.y, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShapeFrameRect.width, copyCompositeShapeFrameRect.width, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShapeFrameRect.height, copyCompositeShapeFrameRect.height, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShapeArea, copyCompositeShapeArea, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestCompositeShapeMoveAssigmentOperato)
  {
    const golovin::point_t basePointOfRectangle{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    const golovin::point_t basePointOfCircle{1.1, 1.1};
    const double radius = 5.0;

    const golovin::point_t pointA{0.0, 0.0};
    const golovin::point_t pointB{1.0, 1.0};
    const golovin::point_t pointC{0.0, 2.0};

    golovin::CompositeShape::shapePointer rectangle =
            std::make_shared<golovin::Rectangle>(basePointOfRectangle, width, height);
    golovin::CompositeShape::shapePointer circle =
            std::make_shared<golovin::Circle>(basePointOfCircle, radius);
    golovin::CompositeShape::shapePointer triangle =
            std::make_shared<golovin::Triangle>(pointA, pointB, pointC);
    golovin::CompositeShape compositeShape;
    compositeShape.pushBack(rectangle);
    compositeShape.pushBack(circle);
    compositeShape.pushBack(triangle);

    golovin::rectangle_t compositeShapeFrameRect = compositeShape.getFrameRect();
    double compositeShapeArea = compositeShape.getArea();

    golovin::CompositeShape newCompositeShape = std::move(compositeShape);

    golovin::rectangle_t newCompositeShapeFrameRect = newCompositeShape.getFrameRect();
    double newCompositeShapeArea = newCompositeShape.getArea();

    BOOST_CHECK_CLOSE(compositeShapeFrameRect.pos.x, newCompositeShapeFrameRect.pos.x, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShapeFrameRect.pos.y, newCompositeShapeFrameRect.pos.y, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShapeFrameRect.width, newCompositeShapeFrameRect.width, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShapeFrameRect.height, newCompositeShapeFrameRect.height, ACCURACY);
    BOOST_CHECK_CLOSE(compositeShapeArea, newCompositeShapeArea, ACCURACY);
  }

BOOST_AUTO_TEST_SUITE_END()
