#include <logger/logger.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "/logger");

  ros::NodeHandle NH;
  ros::AsyncSpinner AS(0);

  sub_log = NH.subscribe("/log", 10, CllbckLog);

  if (LogInit() == -1) {
    ROS_ERROR("LOGGER INITIALIZATION ERROR");
    ros::shutdown();
  }
  return 0;
}