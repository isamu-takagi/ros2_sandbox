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

#ifndef INTERFACE_SPECS__MESSAGE_INTERFACE_BASE_HPP_
#define INTERFACE_SPECS__MESSAGE_INTERFACE_BASE_HPP_

#include <rclcpp/rclcpp.hpp>

#include <utility>

namespace interface_specs
{

template <class T>
struct MessageInterfaceBase
{
  using Message = typename T::Message;
  using Adaptor = typename T::Adaptor;
  using Subscription = typename rclcpp::Subscription<Adaptor>::SharedPtr;
  using Publisher = typename rclcpp::Publisher<Adaptor>::SharedPtr;

  static rclcpp::QoS get_qos()
  {
    rclcpp::QoS qos(T::depth);
    qos.reliability(T::reliability);
    qos.durability(T::durability);
    return qos;
  }

  template <class F>
  static Subscription create_subscription(rclcpp::Node * node, F && callback)
  {
    const auto qos = get_qos();
    return node->create_subscription<Adaptor>(T::name, qos, std::forward<F>(callback));
  }

  static Publisher create_publisher(rclcpp::Node * node)
  {
    const auto qos = get_qos();
    return node->create_publisher<Adaptor>(T::name, qos);
  }
};

}  // namespace interface_specs

#endif  // INTERFACE_SPECS__MESSAGE_INTERFACE_BASE_HPP_
