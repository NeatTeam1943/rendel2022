// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/RunCommand.h>

#include "subsystems/Chassis.h"
#include "commands/Rotation.h"


#include "subsystems/Rendall.h"
#include "commands/Loading.h"
#include "commands/Loading_n_Shooting.h"

#include "Constants.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  frc::XboxController m_controller{0};//Defines the class of the controller as m_controller

  frc2::JoystickButton x{&m_controller, 3};
  frc2::JoystickButton y{&m_controller, 4};
  frc2::JoystickButton RB{&m_controller, 6};
  frc2::JoystickButton LB{&m_controller, 5};

  Rendall m_rendall; //Defines the class Rendall as m_rendall
  Loading m_loading{&m_rendall};
  Loading_n_Shooting m_loading_n_shooting{&m_rendall};

  Chassis m_chassis; //Defines the class Chassis as m_chassis
  Rotation m_rotation_R{&m_chassis, rotation::kRotationdegreesRight};
  Rotation m_rotation_L{&m_chassis, rotation::kRotationdegreesLeft};
  
  //continue from here
  void ConfigureButtonBindings();
};
