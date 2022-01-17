// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Rotation.h"

Rotation::Rotation(Chassis* chassis, double angle) : m_chassis{chassis} {
  // Use addRequirements() here to declare subsystem dependencies.
  Rotation::Angle = angle;
}

// Called when the command is initially scheduled.
void Rotation::Initialize() {
  this->m_chassis->Calibrate_n_stop();
}

// Called repeatedly when this Command is scheduled to run
void Rotation::Execute() {
  if (!this->m_chassis->isInDirection((units::degree_t)Angle))
  this->m_chassis->Rotate((units::degree_t)Angle);
}

// Called once the command ends or is interrupted.
void Rotation::End(bool interrupted) {
  this->m_chassis->Calibrate_n_stop();
}

// Returns true when the command should end.
bool Rotation::IsFinished() {
  return this->m_chassis->isInDirection((units::degree_t)Angle);
}
