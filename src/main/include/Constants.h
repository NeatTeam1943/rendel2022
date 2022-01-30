// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

namespace drv {
    constexpr int kRearLeft = 1;
    constexpr int kFrontLeft = 2;
    constexpr int kRearRight = 3;
    constexpr int kFrontRight = 4;

    constexpr int kLeftEncoderPorts[] = { 6, 7 };
    constexpr int kRightEncoderPorts[] = { 8, 9 };
}

namespace shoot {
    constexpr int kEncoderPorts[] = {4, 5};

    constexpr int kSwitchPort = 0;

    constexpr int kLoader = 5;
    constexpr int kShooter = 6;
}
namespace powers {
    const double kLoadPower = .6;
    const double kShootPower = 25;
}

namespace radius {
    const double wheelRad = .1;
    const double robotRad = .5;
}

namespace rotation {
    const double kRotationdegreesRight = 270;
    const double kRotationdegreesLeft = 90;
}

namespace PID {
    const double Kp = 1.78;

    const double Ki = .1;

    const double Kd = .0;
}
/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
