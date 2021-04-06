#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class ConsumerComponent : public rclcpp::Node
{
  public:
    ConsumerComponent(const rclcpp::NodeOptions& options) : Node("consumer", options)
    {
      sub_ = create_subscription<std_msgs::msg::Int32>("intra_topic", 10,
        [this](const std_msgs::msg::Int32::UniquePtr msg)
        {
          RCLCPP_INFO(get_logger(), "consume: %03d, %p", msg->data, msg.get());
        }
      );
    }

  private:
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_;
};

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(ConsumerComponent)
