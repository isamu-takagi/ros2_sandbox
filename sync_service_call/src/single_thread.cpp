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

#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>

using example_interfaces::srv::AddTwoInts;

class ServiceProxy : public rclcpp::Node
{
public:
  ServiceProxy() : Node("service_proxy")
  {
    client_ = create_client<AddTwoInts>("/add_two_ints");
    server_ = create_service<AddTwoInts>("/proxy/add_two_ints", std::bind(&ServiceProxy::on_service, this, std::placeholders::_1, std::placeholders::_2));
  }

private:
  void on_service(AddTwoInts::Request::SharedPtr req, AddTwoInts::Response::SharedPtr res)
  {
    if (!client_->service_is_ready())
    {
      RCLCPP_ERROR_STREAM(get_logger(), "service not found");
      return;
    }

    auto future = client_->async_send_request(req);
    if (future.wait_for(std::chrono::seconds(1)) != std::future_status::ready)
    {
      RCLCPP_INFO_STREAM(get_logger(), "service timeout");
      return;
    }
    res->sum = future.get()->sum;
  }

  rclcpp::Client<AddTwoInts>::SharedPtr client_;
  rclcpp::Service<AddTwoInts>::SharedPtr server_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::executors::SingleThreadedExecutor executor;
  const auto node= std::make_shared<ServiceProxy>();
  executor.add_node(node);
  executor.spin();
  rclcpp::shutdown();
}
