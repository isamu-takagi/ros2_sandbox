#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class ProducerComponent : public rclcpp::Node
{
  public:
    ProducerComponent(const rclcpp::NodeOptions& options) : Node("producer", options)
    {
      using namespace std::chrono_literals;
      counter_ = 0;
      pub_ = create_publisher<std_msgs::msg::Int32>("intra_topic", 10);
      timer_ = create_wall_timer(1s, [this]{ProducerComponent::callback();});
    }
    void callback()
    {
      std_msgs::msg::Int32::UniquePtr msg = std::make_unique<std_msgs::msg::Int32>();
      msg->data = counter_++;
      RCLCPP_INFO(get_logger(), "produce: %03d, %p", msg->data, msg.get());
      pub_->publish(std::move(msg));
    }

  private:
    int counter_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(ProducerComponent)
