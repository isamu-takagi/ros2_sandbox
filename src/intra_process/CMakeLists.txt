cmake_minimum_required(VERSION 3.5)
project(intra_process)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
include_directories(${rclcpp_INCLUDE_DIRS} ${std_msgs_INCLUDE_DIRS})

add_library(producer SHARED src/producer.cpp)
rclcpp_components_register_nodes(producer "ProducerComponent")
target_compile_definitions(producer PRIVATE "MY_LIBRARY_BUILDING_LIBRARY")
ament_target_dependencies(producer rclcpp rclcpp_components std_msgs)

add_library(consumer SHARED src/consumer.cpp)
rclcpp_components_register_nodes(consumer "ConsumerComponent")
target_compile_definitions(consumer PRIVATE "MY_LIBRARY_BUILDING_LIBRARY")
ament_target_dependencies(consumer rclcpp rclcpp_components std_msgs)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(
  TARGETS producer consumer
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
