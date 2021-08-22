cmake_minimum_required(VERSION 3.0.2)
project(foundations_robot_kinematics)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}_lib src/common_operations.cpp)
add_dependencies(${PROJECT_NAME}_lib ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_lib ${catkin_LIBRARIES})

add_executable(three_r_planar_forward src/3r_planar_forward.cpp)
add_dependencies(three_r_planar_forward ${catkin_EXPORTED_TARGETS})
target_link_libraries(three_r_planar_forward ${catkin_LIBRARIES} ${PROJECT_NAME}_lib)

add_executable(three_r_planar_inverse src/3r_planar_inverse.cpp)
add_dependencies(three_r_planar_inverse ${catkin_EXPORTED_TARGETS})
target_link_libraries(three_r_planar_inverse ${catkin_LIBRARIES} ${PROJECT_NAME}_lib)

# add_executable(three_r_planar_jacobian src/3r_planar_jacobian.cpp)
# add_dependencies(three_r_planar_jacobian ${catkin_EXPORTED_TARGETS})
# target_link_libraries(three_r_planar_jacobian ${catkin_LIBRARIES} ${PROJECT_NAME}_lib)