cmake_minimum_required(VERSION 3.15)
project(AAA3)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()
add_executable(BoostTest A3/test-main.cpp common/rectangle.cpp common/rectangle.hpp common/circle.hpp common/circle.cpp common/shape.hpp common/base-types.hpp common/composite-shape.cpp common/composite-shape.hpp common/triangle.cpp common/triangle.hpp)
if(Boost_FOUND)

    target_link_libraries(BoostTest ${Boost_LIBRARIES})

endif()

add_executable(AAA3 A3/main.cpp common/rectangle.cpp common/rectangle.hpp common/circle.hpp common/circle.cpp common/shape.hpp common/base-types.hpp common/composite-shape.cpp common/composite-shape.hpp common/triangle.cpp common/triangle.hpp)