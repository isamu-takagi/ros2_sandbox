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

#ifndef CPP_SUB_DEV_HPP_
#define CPP_SUB_DEV_HPP_

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

#endif  // CPP_SUB_DEV_HPP_
