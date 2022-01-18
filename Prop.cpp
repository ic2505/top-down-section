#include "Prop.h"
#include "raymath.h"

// member initializer list: worldPos will be initialized with the values of Pos
// this is the more efficient way as oppsed to initializing in body
Prop::Prop(Vector2 pos, Texture2D tex) : 
    worldPos(pos), 
    texture(tex)
{
    
}

void Prop::Render(Vector2 knightPos)
{
    Vector2 screenPos { Vector2Subtract(worldPos, knightPos) };
    DrawTextureEx(texture, screenPos, 0.f, scale, WHITE);
}

Rectangle Prop::getCollisionRec(Vector2 knightPos)
{
    Vector2 screenPos { Vector2Subtract(worldPos, knightPos) };
    return Rectangle{
        screenPos.x,
        screenPos.y,
        texture.width * scale,
        texture.height * scale
    };
}