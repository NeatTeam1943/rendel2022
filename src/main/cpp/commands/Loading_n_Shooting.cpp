// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Loading_n_Shooting.h"

Loading_n_Shooting::Loading_n_Shooting(Rendall* rendall) : m_rendall{rendall} {}

// Called when the command is initially scheduled.
void Loading_n_Shooting::Initialize() {
  this->m_rendall->stop();
}

// Called repeatedly when this Command is scheduled to run
void Loading_n_Shooting::Execute() {
  this->m_rendall->load_n_shoot(kPower);
}

// Called once the command ends or is interrupted.
void Loading_n_Shooting::End(bool interrupted) {
  this->m_rendall->stop();
}

// Returns true when the command should end.
bool Loading_n_Shooting::IsFinished() {
  return false;
}
