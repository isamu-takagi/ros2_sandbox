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

#ifndef INTERFACE_SPECS__INTERFACE_MANAGER_HPP_
#define INTERFACE_SPECS__INTERFACE_MANAGER_HPP_

#include <rclcpp/rclcpp.hpp>

#include <memory>
#include <utility>

namespace interface_specs
{

class ComponentInterfaceManager
{
public:
  using UniquePtr = std::unique_ptr<ComponentInterfaceManager>;
  explicit ComponentInterfaceManager(rclcpp::Node * node) : node_(node) {}

  template <class T, class F>
  typename T::Subscription create_subscription(F && callback)
  {
    const auto qos = get_qos<T>();
    return node_->create_subscription<typename T::Adaptor>(
      T::Setting::name, qos, std::forward<F>(callback));
  }

  template <class T>
  typename T::Publisher create_publisher()
  {
    const auto qos = get_qos<T>();
    return node_->create_publisher<typename T::Adaptor>(T::Setting::name, qos);
  }

private:
  template <class T>
  static rclcpp::QoS get_qos()
  {
    rclcpp::QoS qos(T::Setting::depth);
    qos.reliability(T::Setting::reliability);
    qos.durability(T::Setting::durability);
    return qos;
  }

private:
  rclcpp::Node * node_;
};

inline ComponentInterfaceManager::UniquePtr create_interface_manager(rclcpp::Node * node)
{
  return std::make_unique<ComponentInterfaceManager>(node);
}

}  // namespace interface_specs

#endif  // INTERFACE_SPECS__INTERFACE_MANAGER_HPP_
