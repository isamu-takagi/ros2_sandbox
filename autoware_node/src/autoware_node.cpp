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

#include "autoware_node.hpp"
#include <lifecycle_msgs/msg/state.hpp>
#include <memory>
#include <string>

AutowareNode::AutowareNode(const std::string & name, const rclcpp::NodeOptions & options) : LifecycleNode(name, options)
{
  RCLCPP_INFO(get_logger(), "AutowareNode constructor");
  diagnostic_updater_ = std::make_unique<diagnostic_updater::Updater>(this);
  diagnostic_updater_->setHardwareID("none");
  diagnostic_updater_->add("heartbeat", this, &AutowareNode::autoware_node_heartbeat);
}

bool AutowareNode::is_autoware_node_ready()
{
  using lifecycle_msgs::msg::State;
  auto state = get_current_state();

  if (is_autoware_node_ready_)
  {
    if (state.id() == State::PRIMARY_STATE_UNCONFIGURED)
    {
      state = configure();
      RCLCPP_INFO(get_logger(), "AutowareNode transition: configure");
    }
    if (state.id() == State::PRIMARY_STATE_INACTIVE)
    {
      state = activate();
      RCLCPP_INFO(get_logger(), "AutowareNode transition: activate");
    }
  }

  return state.id() == State::PRIMARY_STATE_ACTIVE;
}

void AutowareNode::enable_autoware_node()
{
  is_autoware_node_ready_ = true;
}

void AutowareNode::autoware_node_heartbeat(diagnostic_updater::DiagnosticStatusWrapper & stat)
{
  stat.summary(diagnostic_msgs::msg::DiagnosticStatus::OK, "");
}
