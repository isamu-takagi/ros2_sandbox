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

#include <interface_specs/interface_manager.hpp>
#include <interface_specs/sample_color/dev.hpp>
#include <rclcpp/rclcpp.hpp>

class CppSubDev : public rclcpp::Node
{
public:
  CppSubDev();

private:
  using SampleColor = interface_specs::sample_color::dev::Interface;
  interface_specs::ComponentInterfaceManager::UniquePtr interface_;
  SampleColor::Subscription sub_;
  void on_color(const SampleColor::Message::SharedPtr msg);
};

CppSubDev::CppSubDev() : Node("cpp_sub_dev")
{
  interface_ = interface_specs::create_interface_manager(this);
  sub_ = interface_->create_subscription<SampleColor>(
    std::bind(&CppSubDev::on_color, this, std::placeholders::_1));
}

void CppSubDev::on_color(const SampleColor::Message::SharedPtr msg)
{
  RCLCPP_INFO(get_logger(), "r: %f", msg->color.r);
  RCLCPP_INFO(get_logger(), "g: %f", msg->color.g);
  RCLCPP_INFO(get_logger(), "b: %f", msg->color.b);
  if (msg->has_alpha) {
    RCLCPP_INFO(get_logger(), "a: %f", msg->color.a);
  }
  RCLCPP_INFO(get_logger(), "---");
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::executors::SingleThreadedExecutor executor;
  auto node = std::make_shared<CppSubDev>();
  executor.add_node(node);
  executor.spin();
  executor.remove_node(node);
  rclcpp::shutdown();
}
