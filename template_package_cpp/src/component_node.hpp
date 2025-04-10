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

#include <rclcpp/rclcpp.hpp>

class ComponentNode : public rclcpp::Node
{
public:
  explicit ComponentNode(const rclcpp::NodeOptions & options);

private:
  void on_timer();
  rclcpp::TimerBase::SharedPtr timer_;
};

#endif  // COMPONENT_NODE_HPP
