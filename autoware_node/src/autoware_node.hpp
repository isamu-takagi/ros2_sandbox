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

#ifndef AUTOWARE_NODE_HPP
#define AUTOWARE_NODE_HPP

#include <diagnostic_updater/diagnostic_updater.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <memory>
#include <string>

class AutowareNode : public rclcpp_lifecycle::LifecycleNode
{
public:
  AutowareNode(const std::string & name, const rclcpp::NodeOptions & options);
  bool is_autoware_node_ready();
  void enable_autoware_node();
  auto get_diagnostic_updater() { return diagnostic_updater_.get(); }

private:
  void autoware_node_heartbeat(diagnostic_updater::DiagnosticStatusWrapper & stat);
  bool is_autoware_node_ready_;
  std::unique_ptr<diagnostic_updater::Updater> diagnostic_updater_;
};

#endif  // AUTOWARE_NODE_HPP
