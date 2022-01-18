
#ifndef CHARACTER_H // prevents redefinition of classes: define if not already defined
#define CHARACTER_H
#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character( int winWidth, int winHeight);
    virtual void tick(float deltaTime) override; // tick is now an override of the parent version in BaseCharacter
private:
    
};

#endif
