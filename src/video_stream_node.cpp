#include <nodelet/loader.h>
#include <ros/console.h>
#include <ros/ros.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "video_stream");

    if (ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug)) {
        ros::console::notifyLoggerLevelsChanged();
    }

    nodelet::Loader manager(true);
    nodelet::M_string remappings;
    nodelet::V_string my_argv(argv + 1, argv + argc);
    my_argv.push_back("--shutdown-on-close"); // Internal

    manager.load(ros::this_node::getName(), "video_stream_opencv/VideoStream", remappings, my_argv);

    ros::spin();

    return 0;
}
