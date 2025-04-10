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

#include "component_node.hpp"

ComponentNode::ComponentNode(const rclcpp::NodeOptions & options) : Node("component_node", options)
{
  RCLCPP_INFO(this->get_logger(), "ComponentNode initialized");

  const auto period = rclcpp::Rate(1.0).period();
  timer_ = rclcpp::create_timer(this, get_clock(), period, [this]() { on_timer(); });
}

void ComponentNode::on_timer()
{
  RCLCPP_INFO(this->get_logger(), "ComponentNode timer callback");
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(ComponentNode)
