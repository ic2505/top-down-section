#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) // constructor
{
    width = texture.width / maxFrames;
    height = texture.height;
    screenPos = {
        static_cast<float>(winWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(winHeight) / 2.0f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
        // set worldPos = worldPos + direction  (were now moving the world in opposite direction as the character)
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f; // shorthand for if else statement: ternary operator
        texture = run;
    }
    else
    {
        texture = idle;
    }

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

void Character::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle Character::getCollisionRec()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
}