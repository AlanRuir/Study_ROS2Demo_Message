#include <send_demo_node.h>

SendDemoNode::SendDemoNode() 
    : Node("send_demo_node")
{
    timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&SendDemoNode::onTimer, this));     // 定时器，每隔1秒执行一次

    pub_ = this->create_publisher<cutom_ros2_interfaces::msg::CutomString>(TOPIC_NAME, 10);
}

void SendDemoNode::onTimer()
{
    cutom_ros2_interfaces::msg::CutomString msg;
    msg.head = 0x55;
    msg.data = 0x01;
    msg.crc = 0x55;
    pub_->publish(msg);
}

SendDemoNode::~SendDemoNode()
{
}

void signalHandler(int sig)
{
    struct sigaction new_action;
    new_action.sa_handler = SIG_DFL;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;

    sigaction(sig, &new_action, NULL);
    raise(sig);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    struct sigaction action;
    action.sa_handler = signalHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    rclcpp::spin(std::make_shared<SendDemoNode>());
    rclcpp::shutdown();

    return 0;
}