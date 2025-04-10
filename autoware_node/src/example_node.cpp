// Copyright 2025 Takagi Isamu
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

#include "example_node.hpp"
#include <lifecycle_msgs/msg/state.hpp>

ExampleNode::ExampleNode(const rclcpp::NodeOptions & options) : AutowareNode("example_node", options)
{
  RCLCPP_INFO(get_logger(), "ExampleNode initialized");

  sub_num1_ = create_subscription<Int32>("num1", 1, [this](Int32::ConstSharedPtr msg) { msg_num1_ = msg; });
  sub_num2_ = create_subscription<Int32>("num2", 1, [this](Int32::ConstSharedPtr msg) { msg_num2_ = msg; });

  const auto period = rclcpp::Rate(1.0).period();
  timer_ = rclcpp::create_timer(this, get_clock(), period, [this]() { on_timer(); });
}

void ExampleNode::on_timer()
{
  is_autoware_node_ready() ? on_timer_main() : on_timer_init();
}

void ExampleNode::on_timer_init()
{
  RCLCPP_INFO(get_logger(), "ExampleNode timer_init");
  if (msg_num1_ && msg_num2_)
  {
    enable_autoware_node();
  }
}

void ExampleNode::on_timer_main()
{
  int a = msg_num1_->data;
  int b = msg_num2_->data;
  RCLCPP_INFO(get_logger(), "ExampleNode timer_main: %d + %d = %d", a, b, a + b);
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(ExampleNode)
