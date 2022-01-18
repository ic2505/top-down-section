#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

int main()
{
    // window dimensions
    const float mapScale{4.0f};
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;

    // initialize the window
    InitWindow(windowDimensions[0], windowDimensions[1], "Ilker's Top-Down");

    // init map
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};

    // init knight as class character 
    Character knight(windowDimensions[0], windowDimensions[1]);

    // init props
    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // mapPos = -knight.worldPos
        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        // draw the props
        for (auto prop : props)
        {
            prop.Render(knight.getWorldPos());
        }
        

        knight.tick(GetFrameTime());

        // check map bounds 
        if (knight.getWorldPos().x < 0.f || 
            knight.getWorldPos().y < 0.f || 
            knight.getWorldPos().x + windowDimensions[0] > map.width * mapScale ||
            knight.getWorldPos().y + windowDimensions[1] > map.height * mapScale)
        {
            knight.undoMovement();
        }

        // check prop collisions
        for (auto prop : props)
        {
            if ( CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec()) )
            {
                knight.undoMovement();
            }
        }
        

        // stop drawing
        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}