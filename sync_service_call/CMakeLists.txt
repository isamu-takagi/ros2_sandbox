cmake_minimum_required(VERSION 3.14)
project(sync_service_call)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_executable(single_thread "src/single_thread.cpp")
ament_auto_add_executable(multi_thread "src/multi_thread.cpp")

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package(INSTALL_TO_SHARE launch)
