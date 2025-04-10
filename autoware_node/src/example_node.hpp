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

#ifndef COMPONENT_NODE_HPP
#define COMPONENT_NODE_HPP

#include "autoware_node.hpp"
#include <std_msgs/msg/int32.hpp>

class ExampleNode : public AutowareNode
{
public:
  explicit ExampleNode(const rclcpp::NodeOptions & options);

private:
  void on_timer();
  void on_timer_init();
  void on_timer_main();
  rclcpp::TimerBase::SharedPtr timer_;

  using Int32 = std_msgs::msg::Int32;
  Int32::ConstSharedPtr msg_num1_;
  Int32::ConstSharedPtr msg_num2_;
  rclcpp::Subscription<Int32>::SharedPtr sub_num1_;
  rclcpp::Subscription<Int32>::SharedPtr sub_num2_;
};

#endif  // EXAMPLE_NODE_HPP
