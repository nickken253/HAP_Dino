#pragma once
#define screenWidth 1536
#define screenHight 768
#define titleGame "HAP Dino"

#define ScaleBG 3

#define groundY ((screenHight - 32 * ScaleBG + 2))

// Player

#define ScaleCharacter 1.5
#define PRunVelocity 200
#define PJumpVelocity 400

// Monster
#define MRunVelocity 100
#define MJumpVelocity 700

// Following Camera
#define ViewSizeWidht 512
#define ViewSizeHight 256

// Position
#define Pos0X m_background.getPosition().x - m_background.getGlobalBounds().width / 2
#define Pos0Y m_background.getPosition().y - m_background.getGlobalBounds().height / 2

// Score
#define LevelPoint 10
#define CoinPoint 3