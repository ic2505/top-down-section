#include "Prop.h"

// member initializer list: worldPos will be initialized with the values of Pos
// this is the more efficient way as oppsed to initializing in body
Prop::Prop(Vector2 pos, Texture2D tex) : 
    worldPos(pos), 
    texture(tex)
{
    
}