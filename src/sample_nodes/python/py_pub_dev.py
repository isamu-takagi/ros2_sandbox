# Copyright 2023 Takagi Isamu
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http:#www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
import rclpy.node
from interface_specs.interface_manager import ComponentInterfaceManager
from interface_specs.sample_color.dev import Interface as SampleColor


class PyPubDev(rclpy.node.Node):
    def __init__(self):
        super().__init__("py_pub_dev")
        self.manager = ComponentInterfaceManager(self)
        self.pub = self.manager.create_publisher(SampleColor)
        self.timer = self.create_timer(1.0, self.on_timer)

    def on_timer(self):
        msg = SampleColor.Message()
        msg.r = 14.0
        msg.g = 15.0
        msg.b = 16.0
        self.pub.publish(msg)


if __name__ == "__main__":
    rclpy.init()
    rclpy.spin(PyPubDev())
    rclpy.shutdown()
