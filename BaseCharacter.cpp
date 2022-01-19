#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale};
}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
        {
            frame = 0;
        }
    }

    if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPos + velociyu  (were now moving the world in opposite velocity as the character)

        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f; // shorthand for if else statement: ternary operator
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};

    // draw the character
    Rectangle source{               // source gets the image from the texture and we will later have to cast it into dest
                     width * frame, // get texture correct frame
                     0.f,
                     rightLeft * width, // multiplying by rightLeft flips the image
                     height};
    Rectangle dest{// x&y are location we wish to draw the knight
                   getScreenPos().x,
                   getScreenPos().y,
                   scale * width,   // scaling the texture.
                   scale * height}; // Note .f notation casts value as float, just like (float)
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}