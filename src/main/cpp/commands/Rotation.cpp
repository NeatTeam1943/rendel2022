// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Rotation.h"

Rotation::Rotation(Chassis* chassis, double angle) : m_chassis{chassis} ,turnAngle{angle}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(this->m_chassis);
}

// Called when the command is initially scheduled.
void Rotation::Initialize() {
  this->m_chassis->Stop();
  if (turnAngle > 0)
    rotationPower = -0.5;
  else 
    rotationPower = 0.5;
  finalAngle = this->m_chassis->GetAngle() + turnAngle;
  this->m_chassis->ArcadeDrive(0,this->rotationPower,true);
}

// Called repeatedly when this Command is scheduled to run
void Rotation::Execute() {}

// Called once the command ends or is interrupted.
void Rotation::End(bool interrupted) {
  this->m_chassis->Stop();
}

// Returns true when the command should end.
bool Rotation::IsFinished() {
  return abs(this->m_chassis->GetAngle() - this->finalAngle) <= 1;
}
