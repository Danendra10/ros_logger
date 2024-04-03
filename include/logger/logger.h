#ifndef LOGGER_H_
#define LOGGER_H_

#pragma once

#include <logger/Log.h>
#include <logger/color.h>

#include <ros/ros.h>

ros::Subscriber sub_log;

int LogInit();

#endif // LOGGER_H_