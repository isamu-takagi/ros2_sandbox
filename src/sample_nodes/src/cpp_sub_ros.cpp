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

#include <rclcpp/rclcpp.hpp>

#include <interface_msgs/msg/sample_message.hpp>

class CppSubDev : public rclcpp::Node
{
public:
  CppSubDev();

private:
  using SampleMessage = interface_msgs::msg::SampleMessage;
  rclcpp::Subscription<SampleMessage>::SharedPtr sub_;
  void on_color(const SampleMessage::ConstSharedPtr msg);
};

CppSubDev::CppSubDev() : Node("cpp_sub_ros")
{
  const auto qos = rclcpp::QoS(1).transient_local();
  sub_ = this->create_subscription<SampleMessage>(
    "/sample/color", qos, std::bind(&CppSubDev::on_color, this, std::placeholders::_1));
}

void CppSubDev::on_color(const SampleMessage::ConstSharedPtr msg)
{
  RCLCPP_INFO(get_logger(), "r: %f", msg->r);
  RCLCPP_INFO(get_logger(), "g: %f", msg->g);
  RCLCPP_INFO(get_logger(), "b: %f", msg->b);
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
