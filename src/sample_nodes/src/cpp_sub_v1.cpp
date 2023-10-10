// Copyright 2023 Takagi Isamu
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "cpp_sub_v1.hpp"

#include <memory>

CppSubV1::CppSubV1() : Node("cpp_sub_v1")
{
  const auto callback = std::bind(&CppSubV1::on_color, this, std::placeholders::_1);
  sub_ = SampleColor::create_subscription(this, callback);
}

void CppSubV1::on_color(const SampleColor::Message & msg)
{
  RCLCPP_INFO(get_logger(), "r: %f, g: %f, b: %f", msg.r, msg.g, msg.b);
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::executors::SingleThreadedExecutor executor;
  auto node = std::make_shared<CppSubV1>();
  executor.add_node(node);
  executor.spin();
  executor.remove_node(node);
  rclcpp::shutdown();
}