#include <receive_demo_node.h>

ReceiveDemoNode::ReceiveDemoNode()
    : Node("receive_demo_node")
    , sub_(nullptr)
{
    sub_ = this->create_subscription<cutom_ros2_interfaces::msg::CutomString>(
        TOPIC_NAME, 
        10, 
        std::bind(&ReceiveDemoNode::onMessage, this, std::placeholders::_1)
    );
}

ReceiveDemoNode::~ReceiveDemoNode()
{

}

void ReceiveDemoNode::onMessage(const cutom_ros2_interfaces::msg::CutomString::SharedPtr msg)
{
    std::cout << "receive data: " << (int)msg->head << " " << (int)msg->data << " " << (int)msg->crc << std::endl;
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

    rclcpp::spin(std::make_shared<ReceiveDemoNode>());
    rclcpp::shutdown();

    return 0;
}