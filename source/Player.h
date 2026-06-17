#pragma once

class Player {
public:
    float x;
    float y;
    float velY;
    bool grounded;

    Player();

    void Update();
    void MoveLeft();
    void MoveRight();
    void Jump();
};
