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

#ifndef CPP_PUB_V1_HPP_
#define CPP_PUB_V1_HPP_

#include <interface_specs/sample_color/v1.hpp>
#include <rclcpp/rclcpp.hpp>

class CppPubV1 : public rclcpp::Node
{
public:
  CppPubV1();

private:
  using SampleColor = interface_specs::sample_color::v1::Interface;
  SampleColor::Publisher pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  void on_timer();
};

#endif  // CPP_PUB_V1_HPP_