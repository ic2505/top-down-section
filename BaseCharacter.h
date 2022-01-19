
#ifndef BASE_CHARACTER_H // prevents redefinition of classes: define if not already defined
#define BASE_CHARACTER_H // this is called conditional compilation
#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle getCollisionRec();
    virtual void tick(float deltaTime); //virtual specifies that the function can be overridden
    virtual Vector2 getScreenPos() = 0; // this is a pure virtual function: it is only declared in the parent, not defined. 
    // Pure virtual functions are marked with = 0 and are only defined in child classes.
    // the base character class is now said to be an ABSTRACT class, which means we cant create instances of it, we can only derive
    // child classes from it. 
    bool getAlive() { return alive; }
    void setAlive(bool isAlive) { alive = isAlive; }
protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // 1 : facing right, -1 facing left
    float rightLeft{};
    // animation variables
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{4.0f};
    Vector2 velocity{};
private:
    bool alive{true};
};

#endif