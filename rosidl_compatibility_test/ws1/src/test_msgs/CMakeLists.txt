cmake_minimum_required(VERSION 3.14)
project(test_msgs)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Message.msg"
  "msg/Array.msg"
)

ament_auto_package()
