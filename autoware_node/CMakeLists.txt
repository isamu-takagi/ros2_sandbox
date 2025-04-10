cmake_minimum_required(VERSION 3.14)
project(autoware_node_example)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(${PROJECT_NAME} SHARED
  "src/autoware_node.cpp"
  "src/example_node.cpp"
)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "ExampleNode"
  EXECUTABLE "example_node"
)

ament_auto_package()
