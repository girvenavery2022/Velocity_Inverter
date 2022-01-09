#include <memory>

#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist.hpp>
using std::placeholders::_1;

class VelInverter : public rclcpp::Node
{
  public:
    VelInverter()
    : Node("velocity_inverter")
    {
      subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel", 10, std::bind(&VelInverter::topic_callback, this, _1));  
      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/mammoth/cmd_vel", 10);
    }

  private:
    void topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const
    {
      msg->linear.x = msg->linear.x * -0.25;
	  	publisher_->publish(*msg);
		}
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VelInverter>());
  rclcpp::shutdown();
  return 0;
}
