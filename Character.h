
#ifndef CHARACTER_H // prevents redefinition of classes: define if not already defined
#define CHARACTER_H
#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character( int winWidth, int winHeight);
    virtual void tick(float deltaTime) override; // tick is now an override of the parent version in BaseCharacter
    virtual Vector2 getScreenPos() override;
    Rectangle getWeaponCollisionRec() { return weaponCollisionRec; }
private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
};

#endif
