// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  this->m_chassis.SetDefaultCommand(frc2::RunCommand([this] { //sets the default command of the subsystem chassis to be a RunCommand that runs ArcadeDrive
    this->m_chassis.ArcadeDrive(
      this->m_controller.GetLeftY(),//Up and Down = forwards and backwards
      this->m_controller.GetLeftX(),//Right and Left = rotate left and rotate right
      this->m_controller.GetLeftStickButton()//press and hold joystick = slow robot
    );
  }, {&this->m_chassis}));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  this->y.WhileHeld([this] {m_rendallpid.WhatTheSwitchDoin() ? m_rendallpid.Load(true, powers::kLoadPower) : m_rendallpid.Load(false); });
  this->y.WhenReleased([this] { m_rendallpid.Load(false); });

  this->x.WhileHeld(this->m_shoot);
  this->RB.WhenPressed(this->m_rotation_R);
  this->LB.WhenPressed(this->m_rotation_L);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
