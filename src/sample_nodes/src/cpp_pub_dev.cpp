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

#include <interface_specs/interface_manager.hpp>
#include <interface_specs/sample_color/dev.hpp>
#include <rclcpp/rclcpp.hpp>

class CppPubDev : public rclcpp::Node
{
public:
  CppPubDev();

private:
  using SampleColor = interface_specs::sample_color::dev::Interface;
  interface_specs::ComponentInterfaceManager::UniquePtr interface_;
  SampleColor::Publisher pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  void on_timer();
};

CppPubDev::CppPubDev() : Node("cpp_pub_dev")
{
  interface_ = interface_specs::create_interface_manager(this);
  pub_ = interface_->create_publisher<SampleColor>();

  const auto period = rclcpp::Rate(1.0).period();
  timer_ = rclcpp::create_timer(this, get_clock(), period, [this]() { on_timer(); });
}

void CppPubDev::on_timer()
{
  SampleColor::Message msg;
  msg.r = 4;
  msg.g = 5;
  msg.b = 6;
  pub_->publish(msg);
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::executors::SingleThreadedExecutor executor;
  auto node = std::make_shared<CppPubDev>();
  executor.add_node(node);
  executor.spin();
  executor.remove_node(node);
  rclcpp::shutdown();
}
