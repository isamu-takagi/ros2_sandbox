cmake_minimum_required(VERSION 3.14)
project(template_package_cpp)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_executable(main_node
  "src/main.cpp"
)

ament_auto_add_library(${PROJECT_NAME} SHARED
  "src/component_node.cpp"
)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "ComponentNode"
  EXECUTABLE "component_node"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
  file(GLOB_RECURSE test_files test/*.cpp)
  ament_auto_add_gtest(test_${PROJECT_NAME} ${test_files})
endif()

ament_auto_package()
