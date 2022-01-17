// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Loading.h"

Loading::Loading(Rendall* rendall) : m_rendall{rendall} {}

// Called when the command is initially scheduled.
void Loading::Initialize() {
  this->m_rendall->stop();
}

// Called repeatedly when this Command is scheduled to run
void Loading::Execute() {
  this->m_rendall->load(kPower);
}

// Called once the command ends or is interrupted.
void Loading::End(bool interrupted) {
  this->m_rendall->stop();
}

// Returns true when the command should end.
bool Loading::IsFinished() {
  return false;
}
