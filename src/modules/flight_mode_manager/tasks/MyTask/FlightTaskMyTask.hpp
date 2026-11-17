#pragma once

#include "FlightTask.hpp"

class FlightTaskMyTask : public FlightTask
{
public:
  FlightTaskMyTask() = default;
  virtual ~FlightTaskMyTask() = default;

  bool activate(const trajectory_setpoint_s &last_setpoint) override;
  bool update() override;

private:
  bool _printed_once{false}; // 新增标记
};

