#include "FlightTaskMyTask.hpp"
#include <cmath> // for NAN

bool FlightTaskMyTask::activate(const trajectory_setpoint_s &last_setpoint)
{
  bool ret = FlightTask::activate(last_setpoint);
  _printed_once = false; // 每次激活重置打印标记
  PX4_INFO("FlightTaskMyTask activate was called! ret: %d", ret);
  return ret;
}

bool FlightTaskMyTask::update()
{
  if (!_printed_once) {
    PX4_INFO("FlightTaskMyTask update was called!");
    _printed_once = true;
  }

  // 原地定点：目标位置 = 当前位置，速度/加速度填NAN表示不控制
  _position_setpoint = _position;
  _velocity_setpoint.setAll(NAN);
  _acceleration_setpoint.setAll(NAN);

  _yaw_setpoint = _yaw;
  _yawspeed_setpoint = NAN;

  return true;
}

