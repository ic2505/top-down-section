#include "BaseCharacter.h"

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
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
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

    // draw the character
    Rectangle source{               // source gets the image from the texture and we will later have to cast it into dest
                     width * frame, // get texture correct frame
                     0.f,
                     rightLeft * width, // multiplying by rightLeft flips the image
                     height};
    Rectangle dest{// x&y are location we wish to draw the knight
                   screenPos.x,
                   screenPos.y,
                   scale * width,   // scaling the texture.
                   scale * height}; // Note .f notation casts value as float, just like (float)
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}