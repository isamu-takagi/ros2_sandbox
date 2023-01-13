cmake_minimum_required(VERSION 3.14)
project(ros_deb_pkg_test2)

find_package(autoware_cmake REQUIRED)
autoware_package()
ament_auto_add_executable(${PROJECT_NAME} src/main.cpp)
ament_auto_package(INSTALL_TO_SHARE launch)
