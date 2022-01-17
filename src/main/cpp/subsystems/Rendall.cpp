// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Rendall.h"

Rendall::Rendall() = default;

// This method will be called once per scheduler run
void Rendall::Periodic() {}

void Rendall::load(double power) {
    if (this->m_switch.Get()) {
        this->m_loader.Set(PID.Calculate(m_encoder.GetRate(), power));
    }
}

void Rendall::load_n_shoot(double power) {
    this->m_shooter.Set(PID.Calculate(m_encoder.GetRate(), power));
    if (this->m_encoder.GetRate() >= 0.3) {
        this->m_loader.Set(PID.Calculate(m_encoder.GetRate(), power));
    }
}
void Rendall::stop() {
    this->m_shooter.Set(PID.Calculate(m_encoder.GetRate(), 0));
    this->m_loader.Set(PID.Calculate(m_encoder.GetRate(), 0));
}
