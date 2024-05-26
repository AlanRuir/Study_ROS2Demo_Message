#ifndef __SEND_DEMO_NODE_H__
#define __SEND_DEMO_NODE_H__

#include <rclcpp/rclcpp.hpp>
#include <cutom_ros2_interfaces/msg/cutom_string.hpp>

class SendDemoNode : public rclcpp::Node
{
public:
    SendDemoNode();
    ~SendDemoNode();

private:
    void onTimer();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<cutom_ros2_interfaces::msg::CutomString>::SharedPtr pub_;

private:
    constexpr static const char *TOPIC_NAME = "alan/test/cutom_string_topic";
};

#endif  // __SEND_DEMO_NODE_H__