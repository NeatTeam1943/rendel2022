// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Shoot.h"

Shoot::Shoot(RendallPID* rendallpid) : m_rendallpid{rendallpid} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({rendallpid});
}

// Called when the command is initially scheduled.
void Shoot::Initialize() {
  this->m_rendallpid->Disable();
  this->m_rendallpid->Load(false);
  this->m_rendallpid->SetSetpoint(powers::kShootPower);
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
  if (m_rendallpid->GetController().AtSetpoint())
    m_rendallpid->Load(true, powers::kLoadPower);
  else
    m_rendallpid->Load(false);

  m_rendallpid->Enable();
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted) {
  this->m_rendallpid->Disable();
  m_rendallpid->Load(false);
}

// Returns true when the command should end.
bool Shoot::IsFinished() {
  return false;
}
