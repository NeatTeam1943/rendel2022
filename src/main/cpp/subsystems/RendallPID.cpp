// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/RendallPID.h"

RendallPID::RendallPID()
    : PIDSubsystem(
          // The PIDController used by the subsystem
          frc2::PIDController(PID::Kp, PID::Ki, PID::Kd)) {}

void RendallPID::load(bool load, double power, bool reversed) {
    this->m_loader.Set(load ? (reversed ? -power : power) : 0.);
}

void RendallPID::UseOutput(double output, double setpoint) {
  // Use the output here
  m_shooter.SetVoltage((units::voltage::volt_t) output);
}

double RendallPID::GetMeasurement() {
  // Return the process variable measurement here
  return m_encoder.GetRate();
}
