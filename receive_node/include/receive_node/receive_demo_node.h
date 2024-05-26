#ifndef __RECEIVE_DEMO_NODE_H__
#define __RECEIVE_DEMO_NODE_H__

#include <rclcpp/rclcpp.hpp>
#include <cutom_ros2_interfaces/msg/cutom_string.hpp>

class ReceiveDemoNode : public rclcpp::Node
{
public:
    ReceiveDemoNode();
    ~ReceiveDemoNode();

private:    
    rclcpp::Subscription<cutom_ros2_interfaces::msg::CutomString>::SharedPtr sub_;
    void onMessage(const cutom_ros2_interfaces::msg::CutomString::SharedPtr msg);

private:
    constexpr static const char *TOPIC_NAME = "alan/test/cutom_string_topic";
};

#endif  // __RECEIVE_DEMO_NODE_H__