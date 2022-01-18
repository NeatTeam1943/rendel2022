// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/PIDSubsystem.h>
#include "ctre/Phoenix.h"
#include <frc/Encoder.h>
#include <frc/DigitalInput.h>
#include <frc/controller/PIDController.h>

#include <Constants.h>

class RendallPID : public frc2::PIDSubsystem {
 public:
  RendallPID();

 protected:
  
  void load(double power);

  void load_n_shoot(double power);

  void UseOutput(double output, double setpoint) override;

  double GetMeasurement() override;
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonSRX m_loader{shoot::kLoader};
  WPI_TalonSRX m_shooter{shoot::kShooter};
  
  frc::Encoder m_encoder {shoot::kEncoderPorts[0], shoot::kEncoderPorts[1]};
  frc::DigitalInput m_switch {shoot::kSwitchPort};

  frc2::PIDController PID{PID::Kp, PID::Ki, PID::Kd};
};
