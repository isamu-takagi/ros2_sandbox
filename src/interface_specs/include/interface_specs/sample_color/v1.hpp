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

struct Definition
{
  using Message = CustomMessage;
  using Adaptor = rclcpp::TypeAdapter<CustomMessage, interface_msgs::msg::SampleMessage>;
  static constexpr char name[] = "/sample/color";
  static constexpr auto reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  static constexpr auto durability = RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL;
  static constexpr size_t depth = 1;
};

using Interface = MessageInterfaceBase<Definition>;

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
    rosidl.has_alpha = false;
    rosidl.color.r = custom.r;
    rosidl.color.g = custom.g;
    rosidl.color.b = custom.b;
  }

  static void convert_to_custom(const ros_message_type & rosidl, custom_type & custom)
  {
    custom.r = rosidl.color.r;
    custom.g = rosidl.color.g;
    custom.b = rosidl.color.b;
  }
};

#endif  // INTERFACE_SPECS__SAMPLE_COLOR__V1_HPP_
