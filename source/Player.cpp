#include "Player.h"

Player::Player() {
    x = 100;
    y = 300;
    velY = 0;
    grounded = false;
}

void Player::MoveLeft() {
    x -= 3;
}

void Player::MoveRight() {
    x += 3;
}

void Player::Jump() {
    if (grounded) {
        velY = -10.0f;
        grounded = false;
    }
}

void Player::Update() {
    velY += 0.5f;
    y += velY;

    if (y >= 350) {
        y = 350;
        velY = 0;
        grounded = true;
    }
}
