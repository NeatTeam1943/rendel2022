// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Chassis.h"

Chassis::Chassis() = default;

// This method will be called once per scheduler run
void Chassis::Periodic() {}

void Chassis::ArcadeDrive(double fwd, double  rot, bool sqr) {
  this->Put_in.ArcadeDrive(fwd, rot, sqr);
}

void Chassis::Rotate(units::degree_t targetAngle) {
  if (targetAngle < (units::degree_t)180) {
    if (this->Gyro.GetAngle() < targetAngle) {
      this->m_forntLeft.Set(PID.Calculate((double)Gyro.GetAngle(), (double)targetAngle));
      this->m_rearLeft.Set(PID.Calculate((double)Gyro.GetAngle(), (double)targetAngle));
      this->m_frontRight.Set(PID.Calculate((double)Gyro.GetAngle(), (double)targetAngle));
      this->m_rearRight.Set(PID.Calculate((double)Gyro.GetAngle(), (double)targetAngle));
    }
  } else {
    if (this->Gyro.GetAngle() > targetAngle) {
      this->m_forntLeft.Set(PID.Calculate((double)Gyro.GetAngle() - 360, (double)targetAngle - 360));
      this->m_rearLeft.Set(PID.Calculate((double)Gyro.GetAngle() - 360, (double)targetAngle - 360));
      this->m_frontRight.Set(PID.Calculate((double)Gyro.GetAngle() - 360, (double)targetAngle - 360));
      this->m_rearRight.Set(PID.Calculate((double)Gyro.GetAngle() - 360, (double)targetAngle - 360));
    }
  }
}
//comment
void Chassis::Calibrate_n_stop() {
  this->Gyro.Calibrate();

  this->m_forntLeft.Set(PID.Calculate(m_encoder.GetRate(), 0));
  this->m_rearLeft.Set(PID.Calculate(m_encoder.GetRate(), 0));
  this->m_frontRight.Set(PID.Calculate(m_encoder.GetRate(), 0));
  this->m_rearRight.Set(PID.Calculate(m_encoder.GetRate(), 0));
}

bool Chassis::isInDirection(units::degree_t targetAngle) {
  return this->Gyro.GetAngle() == targetAngle;
}
