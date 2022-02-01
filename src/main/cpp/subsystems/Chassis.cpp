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

void Chassis::Stop() {
  this->ArcadeDrive(0,0,false);
}

double Chassis::GetAngle() {
  return (double)this->Gyro.GetAngle();
}
