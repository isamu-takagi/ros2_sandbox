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

#ifndef INTERFACE_SPECS__SAMPLE_COLOR__DEV_HPP_
#define INTERFACE_SPECS__SAMPLE_COLOR__DEV_HPP_

#include "base.hpp"

#include <interface_specs/message_interface_base.hpp>

#include <interface_msgs/msg/sample_message.hpp>

namespace interface_specs::sample_color::dev
{

struct TypeDefinition
{
  using Message = interface_msgs::msg::SampleMessage;
  using Adaptor = Message;
};

using Interface = MessageInterfaceBase<TypeDefinition, BaseDefinition>;

}  // namespace interface_specs::sample_color::dev

#endif  // INTERFACE_SPECS__SAMPLE_COLOR__DEV_HPP_
