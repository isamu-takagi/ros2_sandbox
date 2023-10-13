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

#include <rclcpp/rclcpp.hpp>

#include <interface_msgs/msg/sample_message.hpp>

class CppPubDev : public rclcpp::Node
{
public:
  CppPubDev();

private:
  using SampleMessage = interface_msgs::msg::SampleMessage;
  rclcpp::Publisher<SampleMessage>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  void on_timer();
};

CppPubDev::CppPubDev() : Node("cpp_pub_ros")
{
  const auto qos = rclcpp::QoS(1).transient_local();
  pub_ = this->create_publisher<SampleMessage>("/sample/color", qos);

  const auto period = rclcpp::Rate(1.0).period();
  timer_ = rclcpp::create_timer(this, get_clock(), period, [this]() { on_timer(); });
}

void CppPubDev::on_timer()
{
  SampleMessage msg;
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
