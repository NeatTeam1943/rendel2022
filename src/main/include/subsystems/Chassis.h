// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "ctre/Phoenix.h"
#include <frc/Encoder.h>
#include <frc/ADIS16448_IMU.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/controller/PIDController.h>

#include "Constants.h"

class Chassis : public frc2::SubsystemBase {
 public:
  Chassis();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  
  void ArcadeDrive(double fwd, double  rot, bool sqr);

  void Rotate(units::degree_t targetAngle);

  void Calibrate_n_stop();

  bool isInDirection(units::degree_t targetAngle);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonSRX m_forntLeft{drv::kFrontLeft};
  WPI_TalonSRX m_rearLeft{drv::kRearLeft};
  frc::MotorControllerGroup m_left{m_forntLeft, m_rearLeft};

  WPI_TalonSRX m_frontRight{drv::kFrontRight};
  WPI_TalonSRX m_rearRight{drv::kRearRight};
  frc::MotorControllerGroup m_right{m_frontRight, m_rearRight};

  frc::DifferentialDrive Put_in{m_left, m_right};

  frc::ADIS16448_IMU Gyro;

  frc::Encoder m_encoder {shoot::kEncoderPorts[0], shoot::kEncoderPorts[1]};

  frc2::PIDController PID{PID::Kp, PID::Ki, PID::Kd};
};
