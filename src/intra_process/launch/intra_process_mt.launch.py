import launch
from launch_ros.descriptions import ComposableNode
from launch_ros.actions import ComposableNodeContainer
from launch_ros.actions import LoadComposableNodes

def generate_launch_description():

    producer = ComposableNode(
        package="intra_process",
        plugin="ProducerComponent",
        name="producer",
        extra_arguments=[{"use_intra_process_comms": True}],
    )

    consumer = ComposableNode(
        package="intra_process",
        plugin="ConsumerComponent",
        name="consumer",
        extra_arguments=[{"use_intra_process_comms": True}],
    )

    container = ComposableNodeContainer(
        package="rclcpp_components",
        namespace="/",
        executable='component_container_mt',
        name="intra_process_container",
        composable_node_descriptions=[producer, consumer],
    )

    return launch.LaunchDescription([container])
