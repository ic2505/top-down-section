#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    virtual void tick(float deltaTime) override; // tick is now an override of the parent version in BaseCharacter
    void setTarget(Character* character) { target = character; } // take a character pointer and assign it to target, which is also type character pointer
    virtual Vector2 getScreenPos() override;
private:
    Character* target;
    float damagePerSec{10.f};
    float radius{25.f};
};