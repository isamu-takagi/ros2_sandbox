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

#ifndef INTERFACE_SPECS__SAMPLE_COLOR__V1_HPP_
#define INTERFACE_SPECS__SAMPLE_COLOR__V1_HPP_

#include "base.hpp"

#include <interface_specs/message_interface_base.hpp>

#include <interface_msgs/msg/sample_message.hpp>

namespace interface_specs::sample_color::v1
{

struct CustomMessage
{
  float r;
  float g;
  float b;
};

struct TypeDefinition
{
  using Message = CustomMessage;
  using Adaptor = rclcpp::TypeAdapter<CustomMessage, interface_msgs::msg::SampleMessage>;
};

using Interface = MessageInterfaceBase<TypeDefinition, BaseDefinition>;

}  // namespace interface_specs::sample_color::v1

template <>
struct rclcpp::TypeAdapter<
  interface_specs::sample_color::v1::CustomMessage, interface_msgs::msg::SampleMessage>
{
  using is_specialized = std::true_type;
  using custom_type = interface_specs::sample_color::v1::CustomMessage;
  using ros_message_type = interface_msgs::msg::SampleMessage;

  static void convert_to_ros_message(const custom_type & custom, ros_message_type & rosidl)
  {
    rosidl.r = custom.r;
    rosidl.g = custom.g;
    rosidl.b = custom.b;
  }

  static void convert_to_custom(const ros_message_type & rosidl, custom_type & custom)
  {
    custom.r = rosidl.r;
    custom.g = rosidl.g;
    custom.b = rosidl.b;
  }
};

#endif  // INTERFACE_SPECS__SAMPLE_COLOR__V1_HPP_
